
## process this file with automake to procude Makefile.in

ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects

## libraries

lib_LTLIBRARIES = grapes/libgrapes.la

grapes_libgrapes_la_SOURCES = \
  grapes/feedback.c grapes/feedback.h \
  grapes/file.c grapes/file.h \
  grapes/vector.c grapes/vector.h \
  grapes/util.c grapes/util.h

grapes_libgrapes_la_includedir = $(includedir)/grapes
grapes_libgrapes_la_include_HEADERS = \
  grapes/feedback.h \
  grapes/file.h \
  grapes/vector.h \
  grapes/util.h

## see http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html for an updating guide
grapes_libgrapes_la_LDFLAGS = -version-info 0:0:0

if PROFILING

lib_LTLIBRARIES += grapes/libgrapes-gp.la

grapes_libgrapes_gp_la_SOURCES = ${grapes_libgrapes_la_SOURCES}

grapes_libgrapes_gp_la_includedir = ${grapes_libgrapes_la_includedir}
grapes_libgrapes_gp_la_include_HEADERS = ${grapes_libgrapes_la_include_HEADERS}

grapes_libgrapes_gp_la_LDFLAGS = ${grapes_libgrapes_la_LDFLAGS} -lgraprof
grapes_libgrapes_gp_la_CFLAGS = -finstrument-functions -g

endif ## PROFILING

## tests

AUTOMAKE_OPTIONS += dejagnu

EXTRA_DIST = \
  tests/asparagus.exp \
  tests/lib/feedback.tcl tests/lib/globals.tcl tests/lib/string.tcl \
  tests/steps/dispatcher.tcl tests/steps/custom.tcl tests/steps/default.tcl \
  tests/static/file.txt tests/static/empty.txt \
  tests/grapes.tests/feedback.exp \
  tests/grapes.tests/file.exp \
  tests/grapes.tests/vector.exp \
  tests/grapes.tests/util.exp \
  tests/leakcheck.tests/leakcheck.exp

RUNTESTFLAGS  = --srcdir $(top_srcdir)/tests/
DEJAGNU       = $(top_srcdir)/tests/asparagus.exp
DEJATOOL      = grapes

test_libdir   = $(top_builddir)/grapes/.libs/
test_incdir   = $(top_srcdir)

export DEJAGNU test_libdir test_incdir

if PROFILING

DEJATOOL += leakcheck

endif ## PROFILING

SUBDIRS = docs
