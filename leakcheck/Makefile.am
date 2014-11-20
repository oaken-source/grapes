
## process this file with automake to produce Makefile.in

check_PROGRAMS = leakcheck

leakcheck_SOURCES = ${top_srcdir}/tests/fdispatch.c
leakcheck_CFLAGS = -finstrument-functions -g
leakcheck_LDADD = ${top_builddir}/src/libgrapes.la -lgraprof

AM_CFLAGS += -I${top_srcdir}

EXTRA_DIST = grapes-leakcheck.tests/leakcheck.exp

AUTOMAKE_OPTIONS = dejagnu

export DEJAGNU
