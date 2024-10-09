# Makefile for Assign3Fork.c

CC = gcc
CFLAGS = -Wall
TARGET = assign3fork

all: $(TARGET)

$(TARGET): Assign3Fork.c
	$(CC) $(CFLAGS) -o $(TARGET) Assign3Fork.c

clean:
	rm -f $(TARGET)
