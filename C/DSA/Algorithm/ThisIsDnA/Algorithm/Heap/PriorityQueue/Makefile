CC = gcc
CFLAGS = -Wall -g

TARGET = PriorityQueue

OBJS = main.o PriorityQueue.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c PriorityQueue.h
	$(CC) $(CFLAGS) -c main.c

PriorityQueue.o: PriorityQueue.c PriorityQueue.h
	$(CC) $(CFLAGS) -c PriorityQueue.c

clean:
	rm -f $(TARGET) $(OBJS)
