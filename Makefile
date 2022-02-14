CC=g++
CFLAGS=-Wall -std=c++1z -I.
DEPS=src\state_globals.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

linrpn: src/main.o src/parser.o
	$(CC) -o linrpn src/main.o src/parser.o

clean:
	rm src/*.o

run:
	./linrpn
