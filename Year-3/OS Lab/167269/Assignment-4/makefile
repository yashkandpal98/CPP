
CFLAGS  = -Wall -pedantic -w
LFLAGS  =
CC      = gcc
RM      = /bin/rm -rf
AR      = ar rc
RANLIB  = ranlib

LIBRARY = gtthread.a

LIB_SRC = gtthread.c 

LIB_OBJ = $(patsubst %.c,%.o,$(LIB_SRC))

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

All: $(LIBRARY)

$(LIBRARY): $(LIB_OBJ)
	$(AR) $(LIBRARY) $(LIB_OBJ)
	$(RANLIB) $(LIBRARY)
	$(CC) $(CFLAGS) -I{…}  -o gtdining.o gtdining.c $(LIBRARY) 

clean:
	$(RM) $(LIBRARY) gtdining.o gtthread.o


