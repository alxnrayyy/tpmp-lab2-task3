CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./src
TARGET = program
SRCDIR = src
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/student.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
