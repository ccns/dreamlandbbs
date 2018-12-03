#include "dao.h"

void
archiv32(
    time_t chrono,      /* 32 bits */
    char *fname         /* 7 chars */
)
{
    char *str;

    str = fname + 7;
    *str = '\0';
    for (;;)
    {
        *(--str) = radix32[chrono & 31];
        if (str == fname)
            return;
        chrono >>= 5;
    }
}

void
archiv32m(
    time_t chrono,      /* 32 bits */
    char *fname         /* 7 chars */
)
{
    char *str;

    str = fname + 8;
    *str = '\0';
    for (;;)
    {
        *(--str) = radix32[chrono & 31];
        if (str == fname)
            return;
        chrono >>= 5;
    }
}
