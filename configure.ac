#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([input], [0.1.0], [adamkoehn1@gmail.com])
AC_CONFIG_SRCDIR([src/input.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([SDL2], [sdl2], [], [AC_MSG_ERROR([could not find sdl2])])
PKG_CHECK_MODULES([SDL2_IMAGE], [SDL2_image], [], [AC_MSG_ERROR([could not find SDL2_image])]);
PKG_CHECK_MODULES([CHECK], [check], [], [AC_MSG_ERROR([could not find check])])
LT_LIB_M

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset pow sqrt])
AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile])

AM_INIT_AUTOMAKE([subdir-objects])
AC_OUTPUT
