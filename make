GCC = /usr/bin/gcc
CFLAGS = -fPIC
LINK = ld -x --shared -o /lib/security/dialog.so
 
$(GCC CFLAGS) newpam.c
$(LINK) 
