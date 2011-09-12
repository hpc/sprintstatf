CC=gcc
CFLAGS=-I. -g
DEPS = sprintstatf.h
OBJ = sprintstatf.o example.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

example: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o ./core ./*~ ./example
