# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
# -Wall for debugger warnings
# -std=c11 for updated standards
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
ifdef DEBUG
	CFLAGS += -g
endif

TARGET = test.out
FILES = StringBuilderMain.c StringBuilder.c

# When we just run "make", what gets built? 
# This is a "phony" target
# that just tells make what other targets to build.
all: $(TARGET)

$(TARGET) : $(FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)

clean :
	rm $(TARGET)
