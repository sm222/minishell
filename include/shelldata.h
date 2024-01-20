
#ifndef SHELLDATA_H
# define SHELLDATA_H

#include <sys/param.h>

// https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive

# if (unix || __unix || __unix__ || __linux__)
#  define SYSTYPE 0
# elif (_WIN32 || _WIN64 || __CYGWIN__)
#  define SYSTYPE 1
# elif (__APPLE__ || __MACH__)
#  define SYSTYPE 2
# else
#  define SYSTYPE -1
# endif

// linux
# if (SYSTYPE == 0)
#  define PATH_SPLIT '/'
# endif

//mac
# if (SYSTYPE == 1)
#  define PATH_SPLIT '/'
# endif

//win	unsuport for now
# if (SYSTYPE == 2)
#  define PATH_SPLIT '\\'
# endif

//unsuport
# if (SYSTYPE == -1 || SYSTYPE == 2)
#  define NORUN 1
# else
#  define NORUN 0
# endif

#endif // SHELLDATA_H
