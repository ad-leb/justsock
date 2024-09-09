VERSION::= 0.0.1

NAME::= justsock
SONAME::= lib${NAME}.so.${VERSION}
INCLUDE::= ${INCLDIR}/${NAME}.h



DLINKER::= /lib64/ld-linux-x86-64.so.2

ASFLAGS::= 
CFLAGS+= -c -fPIC -I src/include/ -Wno-builtin-declaration-mismatch
LDFLAGS+= -lc --dynamic-linker=$(DLINKER)
MDFLAGS+= -r


TGT::= $(BINDIR)/${NAME}
SO::= $(BINDIR)/${SONAME}
