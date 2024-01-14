CC = clang
CFLAGS = -g -Wno-everything -pthread

SRC_DIR = progc
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
HEADER = $(SRC_DIR)/header.h

LIBS = -lm

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main $(OBJS)
