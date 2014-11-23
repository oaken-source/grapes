
## process this file with automake to produce Makefile.in

EXTRA_DIST =  asparagus.exp \
              lib/feedback.tcl lib/string.tcl \
              steps/dispatcher.tcl steps/default.tcl \
	      static/file.txt static/empty.txt \
	      grapes-feedback.tests/feedback.exp \
	      grapes-file.tests/file.exp \
	      grapes-util.tests/util.exp \
	      grapes-vector.tests/vector.exp

AUTOMAKE_OPTIONS = dejagnu

DEJAGNU  = $(top_srcdir)/tests/asparagus.exp
DEJATOOL = grapes

libdir   = $(top_builddir)/grapes/.libs/
incdir   = $(top_srcdir)

export DEJAGNU libdir incdir

if PROFILING

DEJATOOL += leakcheck

endif ## PROFILING
