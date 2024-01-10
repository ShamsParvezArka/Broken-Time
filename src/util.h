#ifdef __WIN32
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef UTIL_H_
#define UTIL_H_

#include <stdlib.h>
#include <assert.h>

#ifndef DA_MALLOC
#define DA_MALLOC(sz) malloc(sz)
#endif

#ifndef DA_REALLOC
#define DA_REALLOC(da, sz) realloc(da, sz)
#endif

#ifndef DA_FREE
#define DA_FREE(da) free(da)
#endif

#define DA_INIT_CAP 256
#define DA_GROWTH_FACTOR 1.50
#define DA_APPEND(da, item)															    \
	do {																			    \
		if ((da)->count >= (da)->capacity) {									        \
            (da)->capacity = (da)->capacity == 0 ? DA_INIT_CAP :                        \
                                                   (da)->capacity * DA_GROWTH_FACTOR;   \
            (da)->items = DA_REALLOC((da)->items, (da)->capacity*sizeof(*(da)->items)); \
            ((da)->items != NULL && "BUY MORE RAM LOL\n");							    \
		}																			    \
        (da)->items[(da)->count++] = (item);										    \
	} while (0)	

#define DA_DESTROY(da)      \
    do {                    \
        free((da)->items);  \
        (da)->items = NULL; \
    } while (0)             \

#endif


