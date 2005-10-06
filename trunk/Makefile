################################################################################
# Makefile for mdate++                                                         
# $Id: Makefile 40 2004-12-19 00:16:04Z ewe2 $
#
# Usage:
#	make target=linux					# linux
#	make target=cygwin					# cygwin 1.3.x
#	make target=mingw32-cross mdate.exe	# linux (Debian) win32 cross-compile
#	gmake target=freebsd				# FreeBSD 4.x target
#	make target=beos					# BeOS r5
#	make target=osx						# Mac OSX 32-bit console
#
# The default target is linux on x86 with a pentium-class processor.
# I can't guarantee the other targets will work, I haven't used Cygwin for
# quite a while now, it's probably out of date. Fixes would be most welcome.
#
# Update: the latest Debian packages for the mingw32 cross-compiler AND the
# latest getopt() source files fixes previous compilation issues for that
# target: we now have a working win32 port.
#
# If the CFLAGS bother you, please dont change -ffloat-store which avoids
# architecture-related problems.
#
# If you want to add a needed target for your OS/distribution, go ahead but
# please email me (Sean Dwyer <ewe2@users.sourceforge.net>) and include a
# patch of your changes so everyone can share!
#
# You may also want to check the documentation targets if you don't need some
# formats: grep for createdoc.
################################################################################

## setup

.SUFFIXES: .c .cc .exe .o .obj
srcdir = .

PACKAGE=Mdate
VERSION=1.5.3

SVNVERSION = 1-5-3
# for future use on the net
#REPOS=http://services.pengsheep.org/svn/mdate
REPOS=svn+ssh://svn.berlios.de/svnroot/repos/mdate

## DEFINE YOUR PREFERRED DEFAULT LANGUAGE HERE with a 1!
DEF_EN=
DEF_ES=
DEF_PL=
DEF_DE=
DEF_FR=

# if not set, set DEFLANG to a sane value. You could cheat and simply define
# your language here.
ifeq ($(DEFLANG),)
    DEFLANG=DEF_EN
endif
ifeq ($(DEF_EN),1)
	DEFLANG=DEF_EN
endif
ifeq ($(DEF_ES),1)
	DEFLANG=DEF_ES
endif
ifeq ($(DEF_DE),1)
	DEFLANG=DEF_DE
endif
ifeq ($(DEF_PL),1)
	DEFLANG=DEF_PL
endif
ifeq ($(DEF_FR),1)
	DEFLANG=DEF_FR
endif

## Debian packaging requires a DESTDIR variable. 
## If you're not packaging, change to taste.
DESTDIR =

BINDIR = $(DESTDIR)/usr/bin
MANDIR = $(DESTDIR)/usr/share/man/man1
DOCDIR = $(DESTDIR)/usr/share/doc/mdate
HTMLDIR = $(DOCDIR)/html
LOCALEDIR = $(DESTDIR)/usr/share/locale

## define nosnprintf=1 if you don't have snprintf, nogetopt=1 if you don't
## have getopt, noi18n if you don't want i18n. This affects what gets built!
 
nosnprintf=
nogetopt=
noi18n=

ifeq ($(target),mingw32-cross)
	nogetopt=1
	noi18n=1
endif

## define pretty if you want to use the old pretty output, otherwise we stick
## with the default one-line hardcore date(1) stuff. This renders the -p flag
## inoperative.
pretty=

ifeq ($(pretty),1)
	DEFS+=-DWANT_PRETTY
endif

## define newmayan if you want newfangled Mayan calendar month names 
## define oldmayan if you want default behaviour.
## you MUST define one!
newmayan=1
oldmayan=

ifneq ($(newmayan),)
DEFS+=-DNEWMAYAN
else
DEFS+=-DOLDMAYAN
endif

## autodetection of target, linux by default
ifneq ($(strip $(wildcard /usr/include/linux)),)
target = linux
endif
		 
OBJS=lang.o mdate.o cmdline.o main.o
		  
ifneq ($(nosnprintf),)
OBJS += snprintf.o 
endif

ifneq ($(nogetopt),)
OBJS += getopt.o getopt1.o
endif
			  
ifneq ($(noi18n),)
LIBS += -lintl
endif

## Default compiler. On Debian, we're up to gcc-3.3, so check your cflags!
CXX=g++
CC=gcc
INC=-I/usr/include -I.
DEFS+=-DHAVE_CONFIG_H -D$(DEFLANG) -DPACKAGE=\"$(PACKAGE)\" -DVERSION=\"$(VERSION)\"
CFLAGS=-O -Wall -ffloat-store $(DEFS)
CXXFLAGS=$(CFLAGS) -fno-rtti
LIBS=-lm

## define debug if you want to help debug mdate with gdb. otherwise, ignore.
debug=

ifeq ($(debug),1)
	CFLAGS+=-g
endif


## linux Target.
## If you're not sure about your -march or -mcpu, try uname -a: it will tell
## you what cpu your kernel supports. Also see /proc/cpuinfo.
## gcc 2.95 and below do NOT support -march=athlon !!
ifeq ($(target),linux)
# for athlons. A Pentium II or above is i686.
	CFLAGS += -march=athlon $(INC)
# an example for my net box AMD K6-2
#	CFLAGS += -march=i386 -mcpu=i586
endif

## freebsd target
## on 4.9 at least, don't use higher optimizations, they generally don't work.
## much gnu stuff resides in /usr/local also.
ifeq ($(target),freebsd)
	INC+=-I/usr/local/include
	CFLAGS=-O -Wall -ffloat-store $(DEFS) $(INC)
	LIBS+=-L/usr/local/lib -lgnugetopt -lintl
endif

## cygwin 1.3.x target
ifeq ($(target),cygwin)
	CXXFLAGS += -march=i386 -mcpu=i586 $(INC) -I/usr/include/g++-3/
	CC += $(INC)
endif

## linux mingw32 cross-compiler
ifeq ($(target),mingw32-cross)
	CC = i586-mingw32msvc-gcc
	CXX = i586-mingw32msvc-g++
	CFLAGS += -mconsole -I.
endif

## BeOS has different paths
ifeq ($(target),beos)
	INC=
	CXXFLAGS += -I/boot/home/config/include -I./
	CC= gcc
	LIBS=-L/boot/home/config/lib -lintl
endif

## OSX target
ifeq ($(target),osx)
	DEFS +=-DIS_OSX
endif

###################### END OF USER CONFIGURABLE SECTION ######################

## main targets

all: mdate

.PHONY: help clean docclean distclean updatecl tagall

mdate: $(OBJS)
	$(CXX) $(CFLAGS) $(INC) -o mdate $(OBJS) $(LIBS)

ifeq ($(target),mingw32-cross)
mdate.exe: all
	-cp mdate mdate.exe
endif
## documentation targets

# temporary direct make for Polish mdate docs until we have enough languages
# to justify unifying the make

ifeq ($(DEF_PL),1)
mdate_pl.html: mdate_pl.sgml
	[ -f mdate_pl.html ] || sgml2html -H header -F footer mdate_pl.sgml
endif

createdoc: mdate.pdf mdate.html mdate.tex mdate.dvi mdate.ps mdate.text

# prevent the HTML docs being accidently remade
mdate.html:	mdate.sgml
	[ -f mdate.html ] || sgml2html -H header -F footer mdate.sgml

# ditto mdate.text
mdate.text:
	[ -f mdate.text ] || sgml2txt mdate.sgml
	mv mdate.txt mdate.text
	
mdate.tex: mdate.sgml
	sgml2latex -o tex $<
	grep -v "{t1enc}" $@ > $@.tmp
	mv $@.tmp $@

mdate.dvi: mdate.tex
	latex $<
	latex $<
	
mdate.ps: mdate.dvi
	dvips -o $@ $<

mdate.pdf: mdate.tex
	pdflatex $<
	pdflatex $<
	pdflatex $<

## install targets

install: installbin

installbin: mdate installman
	@[ -d $(BINDIR) ] || mkdir -p $(BINDIR); \
	install -m755 mdate $(BINDIR)/mdate

installman: mdate
	[ -d $(MANDIR) ] || mkdir -p $(MANDIR); \
    install -m644 mdate.1 $(MANDIR); \
    gzip -9f $(MANDIR)/mdate.1
		

installdoc: createdoc installman
	[ -d $(DOCDIR) ] || mkdir -p $(DOCDIR); \
	install -m644  mdate.dvi mdate.ps mdate.sgml $(DOCDIR); \
	gzip $(DOCDIR)/mdate.dvi $(DOCDIR)/mdate.ps $(DOCDIR)/mdate.sgml; \
	install -m644 mdate.text $(DOCDIR);	gzip $(DOCDIR)/mdate.text ; \
	install -m644  README NEWS ChangeLog GPL API $(DOCDIR); \
	install -m644  AUTHORS Translators $(DOCDIR); \
	[ -d $(HTMLDIR) ] || mkdir -p $(HTMLDIR); \
	install -m644  *.html $(HTMLDIR)
	cp $(HTMLDIR)/mdate.html $(HTMLDIR)/index.html

## dependencies
lang.o: lang.cc config.h lang.hh
mdate.o: mdate.cc config.h mdate.hh
cmdline.o: cmdline.cc config.h mdate.hh cmdline.h getopt.h lang.hh
main.o: main.cc config.h mdate.hh cmdline.h getopt.h
getopt.o: getopt.c config.h getopt.h
getopt1.o: getopt1.c config.h getopt.h
snprintf.o: snprintf.c config.h

distclean: clean docclean

SOURCES=main.cc lang.cc mdate.cc cmdline.cc getopt.c getopt1.c snprintf.c \
 lang.hh mdate.hh getopt.h cmdline.h config.h en.h de.h es.h fr.h pl.h
DOX=mdate.html mdate-*.html mdate.text NEWS README GPL API ChangeLog FDL \
AUTHORS mdate.sgml Translators mdate.1 BUGS mdate_pl.sgml
CONFS=Makefile mdate.spec ChangeLog.header Changelog.old .cvsignore
DEBCONF=debian/*
DISTFILES= $(SOURCES) $(DOX) $(CONFS)

# developers targets only!

# we now need to use svn; I use a wrapper around svn2cl.xsl; we don't tag
# willy-nilly as a tag is just a snapshot directory in the repository, so the
# release target is the LAST thing we want to do. I don't know whether silent
# ChangeLog commits will turn up; I assume they do.

updatesvn:
	svn2cl

# this is now how a release is archived.
dorelease:
	svn copy $(REPOS)/trunk $(REPOS)/tags/mdate-$(SVNVERSION)

distdir = $(PACKAGE)-$(VERSION)
debdir = $(distdir)/debian
dist:
	rm -fr $(distdir)
	mkdir -p $(debdir)
	chmod 777 $(distdir)
	chmod 777 $(debdir)
	for file in $(DISTFILES); do \
		ln $(srcdir)$$file $(distdir) 2> /dev/null \
		|| cp -p $(srcdir)/$$file $(distdir); \
	done
	for file in $(DEBCONF); do \
		cp -p $$file $(debdir); \
	done
	tar zchovf $(distdir).tar.gz $(distdir)
	rm -fr $(distdir)

# both these targets build outside the tree and are heavily system-dependent.
rpm:
	rpmbuild -ba mdate.spec

deb:
	dpkg-buildpackage -rfakeroot

clean:
	-rm -f mdate $(OBJS) *.o mdate.exe *~ *core

psclean:
	-rm -f *.dvi *.ps *.log *.tex *.out *.aux *.toc
	
pdfclean: psclean
	-rm -f *.pdf

docclean: psclean pdfclean
	-rm -f *.bak

help:
	@echo -e "\n\
Usage: \n\
\tmake target=linux\n\
\tmake target=cygwin\n\
\tmake target=mingw32-cross mdate.exe\n\
\tmake target=beos\n\
\tgmake target=freebsd\n\
\tmake target=osx\n\n\
The default target is linux on x86 with a pentium-class processor.\n\
I can't guarantee the other targets will work, I haven't used Cygwin for\n\
quite a while now, it's probably out of date. Fixes would be most welcome.\n\
If the CFLAGS bother you, please dont change -ffloat-store which avoids\n\
architecture-related problems.\n\
\n\
"
