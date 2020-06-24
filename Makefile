CC=g++
CFLAGS=-g -I.
DEPS = ball.h game.h paddle.h
OBJ = ball.o game.o paddle.o
LIBS=-lpthread -lm -lX11 -std=c++11 -lSDL2 -lSDL2_image -lSDL2_gfx
SDL = `sdl-config --cflags --libs sdl2`

%.o: %.cc $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

all: pong

pong: $(OBJ) pong.o
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o pong

