CC = gcc
CFLAGS = -I. 
DEPS = node.h
OBJ = main.o node.o

%.o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 
myexec: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 
.PHONY: clean
clean:
	rm -f*.o myexec