CC = g++

TARGET = proc

ALL = main.cpp proc.cpp stack.cpp

all: $(ALL)
	$(CC) $(ALL) -Wall -Wextra -o $(TARGET)
