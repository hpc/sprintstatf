sprintstatf
============

The % sequences are:

```
* %a st_atime, as decimal number
* %A st_atime, as ctime(3) string
* %c st_ctime, as decimal number
* %C st_ctime, as ctime(3) string
* %g st_gid, as decimal number
* %G st_gid, expanded as group name (Unix only)
* %i st_ino
* %m st_mtime, as decimal number
* %M st_mtime, as ctime(3) string
* %n st_nlink
* %p st_mode, as octal number
* %P st_mode, as ls(1)-style string ("rw-r--r--")
* %s st_size
* %u st_uid, as decimal number
* %U st_uid, expanded as user name (Unix only)
* %% print one %
```

The prototype is:

```C
int sprintstatf(char *out, char *format, struct stat *stbuf)
```

See example.c for a live version that stat()s the file specified at argv[1].
