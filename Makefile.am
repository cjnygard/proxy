# -----------------------------------------------------
# Makefile.am example
# -----------------------------------------------------

SUBDIRS = proxy $(DOXYGEN)
DIST_SUBDIRS = $(SUBDIRS) 

EXTRA_DIST = \
	proxy.spec.in \
	app-docs.make

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = proxy.pc

dist-hook: proxy.spec
	cp proxy.spec $(distdir)

MAINTAINERCLEANFILES= \
	aclocal.m4 \
	config.guess \
	config.sub \
	config.h.in \
	configure \
	COPYING \
	depcomp \
	INSTALL \
	install-sh \
	ltmain.sh \
	Makefile.in \
	xmldb.spec \
	xmldb.pc \
	missing

CLEANFILES = *~

