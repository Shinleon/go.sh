
CC = gcc

# Compiler flags:
# -Wall for debugger warnings
# -std=c11 for updated standards
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
ifdef DEBUG
	CFLAGS += -g
endif

TARGET = test.out

FILES = StringArrayListMain.c StringArrayList.c
AUX = StringArrayList.h

all : $(TARGET)

$(TARGET) : $(FILES) $(AUX)
	$(CC) $(FLAGS) -o $(TARGET) $(FILES)

clean :
	rm $(TARGET)
