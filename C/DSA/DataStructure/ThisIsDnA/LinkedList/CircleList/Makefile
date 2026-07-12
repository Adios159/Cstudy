CC = gcc
CFLAGS = -Wall -g

TARGET = CircleList

OBJS = main.o CircleList.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c CircleList.h
	$(CC) $(CFLAGS) -c main.c

CircleList.o: CircleList.c CircleList.h
	$(CC) $(CFLAGS) -c CircleList.c

clean:
	rm -f $(TARGET) $(OBJS)