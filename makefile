vpath %.c src/
vpath %.h include/
vpath %.o obj/
vpath main bin/

.PHONY: all clean

CC = gcc 
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g -O3
O_REP = obj/
B_REP = bin/
L_REP = lib/
D_REP = doc/

all: clean main

main: main.o matrice.o io.o
	$(CC) $(CFLAGS) $(patsubst %,$(O_REP)%,$^) -lm -o $(B_REP)$@

matrice.o: matrice.c matrice.h
io.o: io.c io.h matrice.h
main.o: main.c matrice.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -lm -I include -o $(O_REP)$@

clean:
	rm -f $(O_REP)*.o $(B_REP)main

archive: src/ include/ obj/ bin/ makefile
	tar -czf lucas-schott.tar.gz $^
