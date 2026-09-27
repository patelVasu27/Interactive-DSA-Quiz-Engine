CC = gcc
CFLAGS = -Wall -Wextra -std=c11

ifeq ($(OS),Windows_NT)
TARGET = dsa_quiz.exe
CLEAN = cmd /C if exist $(TARGET) del /Q $(TARGET)
else
TARGET = dsa_quiz
CLEAN = rm -f $(TARGET)
endif

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(CLEAN)

run: $(TARGET)
	./$(TARGET)