CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC = main.c

# Output executable
OUT = mygame

# Build target
all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

# Clean build files
clean:
	rm -f $(OUT)
