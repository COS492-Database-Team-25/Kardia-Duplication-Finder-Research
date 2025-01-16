#ifdef STANDARD /* C */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef __WIN__ /* Windows */
typedef unsigned __int64 ulonglong;
typedef __int64 longlong;
#else /* Linux/MacOS */
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif
#else /* MySQL */
#include <my_global.h>
#include <my_sys.h>
/*#if defined(SERVER)
#include <m_string.h>
#else
~when compiled as standalone~
#include <string.h>
#define strmov(a,b) stpcpy(a,b)
#define bzero(a,b) memset(a,0,b)
#define memcpy_fixed(a,b,c) memcpy(a,b,c)
#endif*/
#endif
#include <mysql.h>
#include <ctype.h>

/* init function */



