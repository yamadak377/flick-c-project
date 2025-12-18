CC = gcc
CFLAGS = -Wall -O2
TARGET = c_flick_test.exe

all: $(TARGET)

$(TARGET): c_flick_test.c
	$(CC) $(CFLAGS) -o $(TARGET) c_flick_test.c

clean:
	del $(TARGET) 2>nul || true
	