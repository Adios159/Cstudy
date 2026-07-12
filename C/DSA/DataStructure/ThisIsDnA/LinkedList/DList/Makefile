CC = gcc
CFLAGS = -Wall -g

TARGET = dlist

OBJS = main.o DList.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c DList.h
	$(CC) $(CFLAGS) -c main.c

DList.o: DList.c DList.h
	$(CC) $(CFLAGS) -c DList.c

clean:
	rm -f $(TARGET) $(OBJS)