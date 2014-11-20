
/******************************************************************************
 *                                  Grapes                                    *
 *                                                                            *
 *    Copyright (C) 2013 - 2014  Andreas Grapentin                            *
 *                                                                            *
 *    This program is free software: you can redistribute it and/or modify    *
 *    it under the terms of the GNU General Public License as published by    *
 *    the Free Software Foundation, either version 3 of the License, or       *
 *    (at your option) any later version.                                     *
 *                                                                            *
 *    This program is distributed in the hope that it will be useful,         *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *    GNU General Public License for more details.                            *
 *                                                                            *
 *    You should have received a copy of the GNU General Public License       *
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ******************************************************************************/


#include <config.h>

#include <grapes/feedback.h>
#include <grapes/file.h>
#include <grapes/vector.h>
#include <grapes/util.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static unsigned int steps_passed = 0;
static unsigned int steps_failed = 0;

#define ASSERT(COND, ...)   do { if (!(COND)) { FAIL(__VA_ARGS__); return; } } while (0)
#define PASS(MSG)           do { ++steps_passed; printf("C_PASS: %s\n", MSG); } while (0)
#define FAIL(...)           do { ++steps_failed; feedback_error(EXIT_SUCCESS, __VA_ARGS__); } while (0)

static void
test_feedback_assert(int argc, char *argv[])
{
  int cond = 0;
  char *msg = NULL;
  unsigned int param = 0;

  if (argc > 0) cond = strtol(argv[0], NULL, 10);
  if (argc > 1) msg = argv[1];
  if (argc > 2) param = strtol(argv[2], NULL, 10);

  feedback_assert(cond, "%s :: %u", msg, param);
}

static void
test_feedback_assert_wrn(int argc, char *argv[])
{
  int cond = 0;
  char *msg = NULL;
  unsigned int param = 0;

  if (argc > 0) cond = strtol(argv[0], NULL, 10);
  if (argc > 1) msg = argv[1];
  if (argc > 2) param = strtol(argv[2], NULL, 10);

  feedback_assert_wrn(cond, "%s :: %u", msg, param);
}

static void
test_feedback_error_at_line(int argc, char *argv[])
{
  char *filename = NULL;
  unsigned int linenum = 0;
  char *msg = NULL;
  unsigned int param = 0;

  if (argc > 0) filename = argv[0];
  if (argc > 1) linenum = strtol(argv[1], NULL, 10);
  if (argc > 2) msg = argv[2];
  if (argc > 3) param = strtol(argv[3], NULL, 10);

  feedback_error_at_line(filename, linenum, "%s :: %u", msg, param);
}

static void
test_feedback_error(int argc, char *argv[])
{
  int status = 0;
  char *msg = NULL;
  unsigned int param = 0;

  if (argc > 0) status = strtol(argv[0], NULL, 10);
  if (argc > 1) msg = argv[1];
  if (argc > 2) param = strtol(argv[2], NULL, 10);

  feedback_error(status, "%s :: %u", msg, param);
}

static void
test_feedback_warning(int argc, char *argv[])
{
  char *msg = NULL;
  unsigned int param = 0;

  if (argc > 0) msg = argv[0];
  if (argc > 1) param = strtol(argv[1], NULL, 10);

  feedback_warning("%s :: %u", msg, param);
}

static void
test_file_map(int argc, char *argv[])
{
  char *filename = NULL;

  if (argc > 0) filename = argv[0];

  size_t length;
  char *data = file_map(filename, &length);
  ASSERT(data, "%s", filename);

  printf(" ** length is: %zu **\n", length);
  printf("%s\n", data);
}

static void
test_file_unmap(int argc, char *argv[])
{
  char *prefix = NULL;

  if (argc > 0) prefix = argv[0];

  char filename[256] = { 0 };

  size_t length;
  // file_unmap should succeed for successfully mapped files
  // FIXME: this breaks on long prefixes.
  sprintf(filename, "%s/static/file.txt", prefix);
  char *data = file_map(filename, &length);
  ASSERT(data, "file_map");
  int res = file_unmap(data, length);
  ASSERT(!res, "file_unmap");
  PASS("unmapping mapped files");

  // file_unmap should succeed for mapped empty files
  sprintf(filename, "%s/static/empty.txt", prefix);
  data = file_map(filename, &length);
  ASSERT(data, "file_map");
  res = file_unmap(data, length);
  ASSERT(!res, "file_unmap");
  PASS("unmapping mapped empty files");

  // file_unmap should succeed for pointer returned by failed maps
  sprintf(filename, "%s/static/nonexistant.txt", prefix);
  data = file_map(filename, &length);
  res = file_unmap(data, length);
  ASSERT(!res, "file_unmap");
  PASS("unmapping files whose map failed");

  // file_unmap should succeed for NULL pointers
  res = file_unmap(NULL, 123);
  ASSERT(!res, "file_unmap");
  PASS("unmapping a NULL pointer");
}

#undef  ASSERT
#undef  FAIL
#undef  PASS

int
main (int argc, char *argv[])
{
  if (argc < 2)
    return 0;

#define test_setup(T) if (!strcmp(argv[1], #T)) test_ ## T(argc - 2, argv + 2)

  test_setup(feedback_assert);
  test_setup(feedback_assert_wrn);
  test_setup(feedback_error_at_line);
  test_setup(feedback_error);
  test_setup(feedback_warning);

  test_setup(file_map);
  test_setup(file_unmap);

#undef  test_setup

  if (steps_failed + steps_passed)
    {
      printf("\n");
      printf("  steps passed: %8u\n", steps_passed);
      printf("  steps failed: %8u\n", steps_failed);
      printf("\n");
    }

  printf("fdispatch done.");

  return steps_failed;
}
