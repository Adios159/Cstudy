CC = gcc
CFLAGS = -Wall -g

TARGET = BasicHash

OBJS = main.o BasicHash.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c BasicHash.h
	$(CC) $(CFLAGS) -c main.c

BasicHash.o: BasicHash.c BasicHash.h
	$(CC) $(CFLAGS) -c BasicHash.c

clean:
	rm -f $(TARGET) $(OBJS)
