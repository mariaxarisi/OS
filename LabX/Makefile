# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = test1.c test2.c test3.c test4.c test5.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executables
EXECUTABLES = $(SOURCES:.c=)

# Default target
all: $(EXECUTABLES)

# Targets for each executables
$(EXECUTABLES): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target to remove compiled files
clean:
	rm -f $(EXECUTABLES) $(OBJECTS)
	rm test4.txt
