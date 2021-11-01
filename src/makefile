# Use gcc as default C compiler
CC = gcc

# Target name
TARGET = dodger

# Add compile options
CFLAGS += `sdl2-config --cflags` -g -lefence

# Add linking options
LDFLAGS += `sdl2-config --libs` -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lm

# Source files' list: files with extension .c
# For example, main.c draw.c init.c input.c utils.c
SRCS = $(wildcard *.c)
# Object files' list: files with name of source files and extension .o
# For example, main.o draw.o init.o input.o utils.o
OBJS = $(patsubst %.c,%.o,$(SRCS))

# Step 1: make object files
# gcc `sdl2-config --cflags` -g -lefence -c OOO.c
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Step 2: make executable files and link libraries
# gcc -o (object files) `sdl2-config --libs` -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lm
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
	@mv $(TARGET) ..

# clear all object files
clean:
	@rm -rf *.o

