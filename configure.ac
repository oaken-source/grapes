
dnl process this file with autoconf to procude configure script

AC_PREREQ([2.69])
AC_INIT([grapes], [0.1.1], [andreas@grapentin.org])
AC_CONFIG_SRCDIR([grapes/util.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([scripts])
AC_CONFIG_MACRO_DIR([m4])

AC_SUBST([AM_CFLAGS], [])

AM_INIT_AUTOMAKE([-Wall -Werror gnu])

AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_AR

AX_ALLOW_PROFILING
AX_ALLOW_DEBUG

LT_INIT

PKG_INSTALLDIR([/usr/lib/pkgconfig])

AC_CONFIG_FILES([
  grapes.pc
  Makefile
  docs/Makefile])

AC_OUTPUT
