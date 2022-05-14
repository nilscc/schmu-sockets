SCHMU=~/.opam/default/bin/schmu

.PHONY: all clean run

all: sockets

definitions.o: definitions.c
	cc -c definitions.c -o definitions.o

sockets: sockets.o definitions.o
	cc sockets.o definitions.o -o sockets

sockets.o: sockets.smu
	$(SCHMU) --release sockets.smu

clean:
	-rm *.o sockets

run: all
	./sockets
