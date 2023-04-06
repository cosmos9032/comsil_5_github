OBJECTS = main.o
SRCS = main.cpp

CC = g++
CFLAGS = -g -c

TARGET = stack_link

$(TARGET) : $(OBJECTS)
	      $(CC) -o $(TARGET) $(OBJECTS)
clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : Stack.h LinkedList.h main.cpp
