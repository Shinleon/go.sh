# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
# -Wall for debugger warnings
# -std=c11 for updated standards
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
ifdef DEBUG
	CFLAGS += -g
endif

# The name of the program that we are producing.
TARGET = nav.out

# .o file dump
OBJ_LOC = o_files
SRC_LOC = src


# When we just run "make", what gets built? 
# This is a "phony" target
# that just tells make what other targets to build.
all: $(TARGET)

# All the .o files we need for our executable.
O_LIST = nav.o
OBJS = $(addprefix $(OBJ_LOC)/, $(O_LIST))

# An option for making a debug target
debug: CFLAGS += -g
debug: $(TARGET)

# The executable
$(TARGET): $(OBJS) directories
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
directories: $(OBJ_LOC)
	

$(OBJ_LOC):
	mkdir -p $(OBJ_LOC)

$(OBJ_LOC)/nav.o : directories $(SRC_LOC)/nav.c
	$(CC) $(CFLAGS) -c $(SRC_LOC)/nav.c -o $(OBJ_LOC)/nav.o

# A "phony" target to remove built files
clean:
	rm -f *.o *.out $(TARGET)
	rm -rf $(OBJ_LOC)