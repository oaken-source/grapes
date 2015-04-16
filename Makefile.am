
ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects

## libraries

lib_LTLIBRARIES = grapes/libgrapes.la

grapes_libgrapes_la_SOURCES = \
  grapes/feedback.c grapes/feedback.h \
  grapes/file.c grapes/file.h \
  grapes/vector.h \
  grapes/util.h

grapes_libgrapes_la_includedir = $(includedir)/grapes
grapes_libgrapes_la_include_HEADERS = \
  grapes/feedback.h \
  grapes/file.h \
  grapes/vector.h \
  grapes/util.h

## see http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html for an updating guide
grapes_libgrapes_la_LDFLAGS = -version-info 0:0:0

if PROFILING

grapes_libgrapes_la_LDFLAGS += -lgraprof
grapes_libgrapes_la_CFLAGS   = -finstrument-functions -g

endif ## PROFILING

## pkgconfig integration
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = grapes.pc

## tests

# this is what I would like to have
#asparagus_TESTS = \
#  tests/grapes.tests \
#  tests/leakcheck.tests
#
#asparagus_EXTRA_STEPS = \
#  tests/steps/custom.tcl

# this is what I need to use for now
AUTOMAKE_OPTIONS += dejagnu

EXTRA_DIST = \
  tests/grapes.tests \
  tests/leakcheck.tests

RUNTESTFLAGS  = --srcdir $(top_srcdir)/tests/
DEJATOOL      = grapes

ASPARAGUS_EXTRA_STEPS = tests/steps/custom.tcl

test_libdir   = $(top_builddir)/grapes/.libs/
test_incdir   = $(top_srcdir)

export ASPARAGUS_EXTRA_STEPS DEJAGNU test_libdir test_incdir

if PROFILING

DEJATOOL += leakcheck

endif ## PROFILING

## docs

dist_man7_MANS = docs/grapes.7
