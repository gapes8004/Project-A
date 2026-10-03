# ========================================================================
# Makefile - Municipal Financial Management System (MFMS)
# Build with:  make
# Run with:    ./mfms
# Clean with:  make clean
# ========================================================================

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = mfms
SOURCES = main.c employees.c budget.c suppliers.c assets.c reports.c utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
