
## process this file with automake to produce Makefile.in

EXTRA_DIST =  asparagus.exp \
              lib/feedback.tcl lib/globals.tcl lib/string.tcl \
              steps/dispatcher.tcl steps/custom.tcl steps/default.tcl \
              static/file.txt static/empty.txt \
              grapes.tests/feedback.exp \
              grapes.tests/file.exp \
              grapes.tests/util.exp \
              grapes.tests/vector.exp \
              leakcheck.tests/leakcheck.exp

AUTOMAKE_OPTIONS = dejagnu

DEJAGNU  = $(top_srcdir)/tests/asparagus.exp
DEJATOOL = grapes

libdir   = $(top_builddir)/grapes/.libs/
incdir   = $(top_srcdir)

export DEJAGNU libdir incdir

if PROFILING

DEJATOOL += leakcheck

endif ## PROFILING
