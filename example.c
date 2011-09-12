#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#include "sprintstatf.h"

int
main(int argc, char *argv[])
{
    char *outbuf = (char *)malloc(2048 * sizeof(char));
    struct stat stbuf;

    char *fmt = \
        "st_atime (decimal) = \"%a\"\n"
        "st_atime (string)  = \"%A\"\n"
        "st_ctime (decimal) = \"%c\"\n"
        "st_ctime (string)  = \"%C\"\n"
        "st_gid   (decimal) = \"%g\"\n"
        "st_gid   (string)  = \"%G\"\n"
        "st_ino             = \"%i\"\n"
        "st_mtime (decimal) = \"%m\"\n"
        "st_mtime (string)  = \"%M\"\n"
        "st_nlink           = \"%n\"\n"
        "st_mode  (octal)   = \"%p\"\n"
        "st_mode  (string)  = \"%P\"\n"
        "st_size            = \"%s\"\n"
        "st_uid             = \"%u\"\n"
        "st_uid             = \"%U\"\n";

    lstat(argv[1], &stbuf);
    sprintstatf(outbuf, fmt, &stbuf);
    printf("%s", outbuf);
    free(outbuf);

    exit(EXIT_SUCCESS);
}

/* EOF */
