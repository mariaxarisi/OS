# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = example1.c example2.c example3.c example4.c example5.c

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
