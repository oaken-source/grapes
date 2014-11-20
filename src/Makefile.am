
## process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libgrapes.la

libgrapes_la_SOURCES = feedback.c file.c vector.c

libgrapes_la_includedir = $(includedir)/grapes
libgrapes_la_include_HEADERS = feedback.h file.h vector.h util.h

## see http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html for an updating guide
libgrapes_la_LDFLAGS = -version-info 0:0:0

if TESTBUILD

lib_LTLIBRARIES += libgrapes-gp.la

libgrapes_gp_la_SOURCES = ${libgrapes_la_SOURCES}

libgrapes_gp_la_includedir = ${libgrapes_la_includedir}
libgrapes_gp_la_include_HEADERS = ${libgrapes_la_include_HEADERS}

libgrapes_gp_la_LDFLAGS = ${libgrapes_la_LDFLAGS}
libgrapes_gp_la_CFLAGS = -finstrument-functions -g

endif ## TESTBUILD
