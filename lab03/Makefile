CC := gcc
CFLAGS := -std=c99 -Wall -pedantic -I. -g3 -fsanitize=address,undefined -fno-omit-frame-pointer

TPOOL_SRC := threadpool.c queue.c

SERVER_SRC := server.c
SERVER_EXEC_NAME := server

CLIENT_SRC := client.c
CLIENT_EXEC_NAME := client

EXECS = ${CLIENT_EXEC_NAME} ${SERVER_EXEC_NAME}

all: client server

client: ${CLIENT_SRC}
	${CC} ${CFLAGS} ${CLIENT_SRC} -o ${CLIENT_EXEC_NAME}

server: ${SERVER_SRC}
	${CC} ${CFLAGS} ${SERVER_SRC} -o ${SERVER_EXEC_NAME} ${TPOOL_SRC}

clean:
	rm -rf ${EXECS}
