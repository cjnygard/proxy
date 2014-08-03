dnl ---------------------------------------------------------------------------
dnl configure.in - an example
dnl 
dnl Replace: YOUR-FILE, YOUR-APPLICATION-NAME
dnl ---------------------------------------------------------------------------

dnl ---------------------------------------------------------------------------
dnl Package name and release number
dnl
dnl Legend:
dnl
dnl  +1 : ? : +1  == new interface that does not break old one
dnl  +1 : ? : 0   == new interface that breaks old one
dnl   ? : ? : 0   == no new interfaces, but breaks apps
dnl   ? :+1 : ?   == just some internal changes, nothing breaks but might work
dnl                  better
dnl ---------------------------------------------------------------------------

AC_INIT([proxy], [0.1.0], [cjnygard@gmailcom])
AM_INIT_AUTOMAKE(tar-ustar)
AC_CONFIG_MACRO_DIR([m4])

dnl ABI_VERSION=0:1:0
DOCROOT=.
RELEASE=$VERSION

AC_SUBST(RELEASE)
AC_SUBST(DOCROOT)
dnl AC_SUBST(ABI_VERSION)

dnl Specify a configuration file
AM_CONFIG_HEADER(config.h)

AM_MAINTAINER_MODE


dnl ---------------------------------------------------------------------------
dnl Check build environment
dnl ---------------------------------------------------------------------------
AC_ISC_POSIX
AC_HEADER_STDC

AC_PROG_CC
AC_PROG_CXX
AC_PROG_CXXCPP
AM_PROG_LIBTOOL
AM_SANITY_CHECK

dnl ---------------------------------------------------------------------------
dnl Set PACKAGE_LOCALE_DIR in config.h.
dnl ---------------------------------------------------------------------------

if test "x${prefix}" = "xNONE"; then
  AC_DEFINE_UNQUOTED(PACKAGE_LOCALE_DIR, "${ac_default_prefix}/${DATADIRNAME}/locale", [Localized package directory])
else
  AC_DEFINE_UNQUOTED(PACKAGE_LOCALE_DIR, "${prefix}/${DATADIRNAME}/locale", [Localized package directory])
fi

AC_LANG_CPLUSPLUS

dnl ---------------------------------------------------------------------------
dnl Checks for header files.
dnl ---------------------------------------------------------------------------
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS(limits.h unistd.h)

dnl ---------------------------------------------------------------------------
dnl Checks for typedefs, structures, and compiler characteristics.
dnl ---------------------------------------------------------------------------
AC_TYPE_PID_T
AC_TYPE_SIZE_T

dnl ---------------------------------------------------------------------------
dnl Checks for library functions.
dnl ---------------------------------------------------------------------------
dnl AC_CHECK_FUNCS(getcwd mkdir strerror strtol)

dnl ---------------------------------------------------------------------------
dnl Post-processing - make substitution
dnl ---------------------------------------------------------------------------

AC_SUBST(CFLAGS)
AC_SUBST(CPPFLAGS)
AC_SUBST(CXXFLAGS)
AC_SUBST(LIBS)
AC_SUBST(LDFLAGS)

# HACK:  Assign a dummy in order to prevent execution of autoheader by the
# maintainer-mode rules.  That would fail since we aren't using autoheader.
AUTOHEADER=':'
                                                                                
dnl ---------------------------------------------------------------------------
dnl Generate Make files
dnl ---------------------------------------------------------------------------

AC_OUTPUT([
Makefile 
proxy.spec
proxy.pc
proxy/Makefile 
])
#docs/Makefile
#docs/C/Makefile
