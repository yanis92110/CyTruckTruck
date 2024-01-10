all: main

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm

SRCS = $(wildcard progc/*.c)
HEADERS = $(wildcard progc/*.h)


main: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug