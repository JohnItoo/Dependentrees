CFLAGS = -O
CC = g++
DepTrees: main.o processor.o dependency.o
	$(CC) $(CFLAGS) -o DepTrees main.o processor.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
processor.o: processor.cpp
	$(CC) $(CFLAGS) -c processor.cpp
dependency.o: dependency.h
	$(CC) $(CFLAGS) -c dependency.h
clean:
	rm -f core *.o