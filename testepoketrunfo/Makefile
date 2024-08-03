CC = gcc
CFLAGS = -Wall -g
all: main.o ponto.o
 $(CC) $(CFLAGS) -o all main.o ponto.o $(LIBS)
main.o: main.c ponto.h
 $(CC) $(CFLAGS) -c main.c
ponto.o: ponto.c ponto.h
 $(CC) $(CFLAGS) -c ponto.c $(LIBS)
clean:
 rm -rf *.o *~ all