
## process this file with automake to produce Makefile.in

check_PROGRAMS = fdispatch

fdispatch_SOURCES = fdispatch.c
fdispatch_LDADD = ${top_builddir}/src/libgrapes.la
AM_CFLAGS += -I${top_srcdir}

EXTRA_DIST =  asparagus.exp \
              lib/feedback.tcl lib/string.tcl \
              steps/dispatcher.tcl steps/default.tcl \
	      static/file.txt static/empty.txt \
	      grapes-feedback.tests/feedback.exp \
	      grapes-file.tests/file.exp \
	      grapes-util.tests/util.exp

AUTOMAKE_OPTIONS = dejagnu

export DEJAGNU
