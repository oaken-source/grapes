
## process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libgrapes.la libgrapes-graprof.la

libgrapes_la_SOURCES = feedback.c

libgrapes_la_includedir = $(includedir)/grapes
libgrapes_la_include_HEADERS = feedback.h util.h

## see http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html for an updating guide
libgrapes_la_LDFLAGS = -version-info 0:0:0

libgrapes_graprof_la_SOURCES = feedback.c

libgrapes_graprof_la_includedir = $(includedir)/grapes
libgrapes_graprof_la_include_HEADERS = feedback.h util.h

libgrapes_graprof_la_LDFLAGS = -version-info 0:0:0
libgrapes_graprof_la_CFLAGS = -finstrument-functions -g -DDEBUG
