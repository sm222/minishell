
#ifndef SHELLDATA_H
# define SHELLDATA_H

#include <sys/param.h>

// https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive

# define FT_LINUX 0 // Linux is use
# define FT_WIN   1 // Windows is use
# define FT_MAC   2 // Mac is use

# if (unix || __unix || __unix__ || __linux__)
#  define SYSTYPE FT_LINUX
# elif (_WIN32 || _WIN64 || __CYGWIN__)
#  define SYSTYPE FT_WIN
# elif (__APPLE__ || __MACH__)
#  define SYSTYPE FT_MAC
# else
#  define SYSTYPE -1
# endif

// all system                                        |
# define SH_LV_MAX  10


// linux
# if (SYSTYPE == FT_LINUX)
#  define PATH_SEP   '/'
#  define PATH_SPLIT ':'
#  define PATH_BIN_S "PATH="
#  define PROMPT     "$ "                            //at least one space at the end to show cursor
# endif

//mac
# if (SYSTYPE == FT_MAC)
#  define PATH_SEP   '/'
#  define PATH_SPLIT ':'
#  define PATH_BIN_S "PATH="
#  define PROMPT     "~> "
# endif

//win	unsuport for now
# if (SYSTYPE == FT_WIN)
#  define PATH_SEP   '\\'
#  define PATH_SPLIT ':'
#  define PATH_BIN_S "PATH="
#  define PROMPT     "| "
# endif

//unsuport
# if (SYSTYPE == -1 || SYSTYPE == 1)                 //if system is not suport set default value
#  define NORUN 1
#  define PATH_SEP   '/'
#  define PATH_SPLIT ':'
#  define PATH_BIN_S "PATH="
#  define PROMPT     "<> "
# else
#  define NORUN 0
# endif

#endif // SHELLDATA_H
