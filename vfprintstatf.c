#include "vfprintstatf.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>

int
vfprintstatf(char *s, char *format, struct stat *stbuf)
{
    char *p;
    struct passwd *pwp;
    struct group *grp;
    int i = 0;

    if(format != NULL && stbuf != NULL)
    {
        for(p = format; *p != '\0'; p++)
        {
            if(*p != '%')
            {
                putchar(*p);
                continue;
            }

            switch(*++p)
            {
                case 'a':
                    printf("%ld", (long)stbuf->st_atime);
                    break;

                case 'A':
                    printf("%.24s", ctime(&(stbuf->st_atime)));
                    break;

                case 'c':
                    printf("%ld", (long)stbuf->st_ctime);
                    break;

                case 'C':
                    printf("%.24s", ctime(&(stbuf->st_ctime)));
                    break;

                case 'g':
                    printf("%d", stbuf->st_gid);
                    break;
                case 'G':
                    grp = getgrgid(stbuf->st_gid);
                    printf("%s",
                        (grp != NULL) ? grp->gr_name :
                            "");
                    break;
                case 'i':
                    printf("%llu", (long long)stbuf->st_ino);
                    break;

                case 'm':
                    printf("%ld", (long)stbuf->st_mtime);
                    break;

                case 'M':
                    printf("%.24s", ctime(&(stbuf->st_mtime)));
                    break;

                case 'n':
                    printf("%d", stbuf->st_nlink);
                    break;

                case 'p':
                    printf("%o", stbuf->st_mode);
                    break;

                case 'P':
                    printf("%s", lsmodes(stbuf->st_mode));
                    break;

                case 's':
                    printf("%llu", (long long)stbuf->st_size);
                    break;
                case 'u':
                    printf("%d", stbuf->st_uid);
                    break;
                case 'U':
                    pwp = getpwuid(stbuf->st_uid);
                    printf("%s",
                        (pwp != NULL) ? pwp->pw_name :
                            "");
                    break;
                case '%':
                    putchar('%');
                    break;

                /* default ignored */
            }
        }
        putchar('\n');
    }
}

char *
lsmodes(int mode)
{
    char retbuf[11];
    int ifmt = mode & S_IFMT;

    if(ifmt == S_IFDIR)
        retbuf[0] = 'd';
    else if(ifmt == S_IFCHR)
        retbuf[0] = 'c';
    else if(ifmt == S_IFBLK)
        retbuf[0] = 'b';
    else if(ifmt == S_IFLNK)
        retbuf[0] = 'l';
    else if(ifmt == S_IFSOCK)
        retbuf[0] = 's';
    else if(ifmt == S_IFIFO)
        retbuf[0] = 'p';
    else
        retbuf[0] = '-';

    lsrwx(&retbuf[1], mode);
    lsrwx(&retbuf[4], mode << 3);
    lsrwx(&retbuf[7], mode << 6);

    if(mode & S_ISUID)
        retbuf[3] = (mode & S_IEXEC) ? 's' : 'S';

    if(mode & S_ISGID)
        retbuf[6] = (mode & (S_IEXEC >> 3)) ? 's' : 'S';

    if(mode & S_ISVTX)
        retbuf[9] = (mode & (S_IEXEC >> 6)) ? 't' : 'T';

    retbuf[10] = '\0';

    return(retbuf);
}

void
lsrwx(char *p, int mode)
{
    if(mode & S_IREAD)
        p[0] = 'r';
    else
        p[0] = '-';

    if(mode & S_IWRITE)
        p[1] = 'w';
    else
        p[1] = '-';

    if(mode & S_IEXEC)
        p[2] = 'x';
    else
        p[2] = '-';
}

/* EOF */
