APP    := game
SRCS   := src/*\.c
INCL   := -Isrc
CC     := gcc
CFLAGS := -std=c2x -Wall -Werror -Wextra -pedantic -Ofast
LIBS   := -lm -lSDL3
RM     := rm -rf

all: clean build run

clean:
	@$(RM) $(APP)

build:
	@$(CC) -o $(APP) $(CFLAGS) $(SRCS) $(INCL) $(LIBS)

run:
	@./$(APP)


.PHONY: all clean build run
