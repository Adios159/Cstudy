CC := gcc
CFLAGS := -Wall -Wextra -g -std=c11
GRAPH_DIR := ../Graph

INCLUDES := -I. -I$(GRAPH_DIR)

SRCS := main.c \
        GraphTravel.c \
        $(GRAPH_DIR)/graph.c \
        LinkedQueue.c

OBJS := $(SRCS:.c=.o)
TARGET := graphtravel

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean