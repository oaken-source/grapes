
dnl process this file with autoconf to procude configure script

AC_PREREQ([2.69])
AC_INIT([grapes], [0.1], [andreas@grapentin.org])
AC_CONFIG_SRCDIR([src/feedback.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([scripts])
AC_CONFIG_MACRO_DIR([m4])

AC_SUBST([AM_CFLAGS], [])

AM_INIT_AUTOMAKE([-Wall -Werror gnu])

AC_PROG_CC
AM_PROG_AR

AX_ALLOW_PROFILING
AX_ALLOW_DEBUG

if test x"$DEJAGNU" = x; then
  DEJAGNU="\$(top_srcdir)/tests/asparagus.exp"
fi
AC_SUBST(DEJAGNU)

LT_INIT

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 docs/Makefile
		 tests/Makefile
		 leakcheck/Makefile])

AC_OUTPUT
