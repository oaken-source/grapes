
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

# Allow for a graprof-profiled test build to be enabled at configure time
AC_ARG_ENABLE(testbuild,
AS_HELP_STRING([--enable-testbuild],
               [Build and install instrumented versions of grapes used for profiling with graprof. This is mainly useful for developers working on grapes itself. Default: no]),
[case "${enableval}" in
        yes) testbuild=true ;;
        no)  testbuild=false ;;
        *)   AC_MSG_ERROR([bad value ${enableval} for --enable-testbuild]) ;;
esac],
[testbuild=false])

AM_CONDITIONAL(TESTBUILD, test x"$testbuild" = x"true")

# Allow for deeper error messaging to be enabled at configure time
AC_ARG_ENABLE(debug,
AS_HELP_STRING([--enable-debug],
               [Enable output of failed assertions that may or may not lead to errors that surface on stderr. Useful for debugging, and for submitting bug reports. Default: no]),
[case "${enableval}" in
        yes) debug=1 ;;
        no)  debug=0 ;;
        *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],
[debug=0])

AC_DEFINE_UNQUOTED([DEBUG], [$debug], [increased debug output])

LT_INIT

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 docs/Makefile])

AC_OUTPUT
