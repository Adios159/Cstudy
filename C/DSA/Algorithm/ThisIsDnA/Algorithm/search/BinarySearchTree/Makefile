CC = gcc
CFLAGS = -Wall -g

TARGET = BinarySearchTree

OBJS = main.o BinarySearchTree.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c BinarySearchTree.h
	$(CC) $(CFLAGS) -c main.c

Binary.o: BinarySearchTree.c BinarySearchTree.h
	$(CC) $(CFLAGS) -c BinarySearchTree.c

clean:
	rm -f $(TARGET) $(OBJS)