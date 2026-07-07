CC = gcc
CFLAGS = -Wall -g

TARGET = heap

OBJS = main.o heap.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c heap.h
	$(CC) $(CFLAGS) -c main.c

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

clean:
	rm -f $(TARGET) $(OBJS)
