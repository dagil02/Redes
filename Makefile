CC=g++
CFLAGS=-g -I.
DEPS = XLDisplay.h
OBJ = ejemplo.o XLDisplay.o
LIBS=-lpthread -lm -lX11

%.o: %.cc $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

all: ejemplo

ejemplo: $(OBJ) ejemplo.o
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o ejemplo

