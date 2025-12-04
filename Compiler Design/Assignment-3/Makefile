CC = gcc
FLEX = flex
TARGET = lexer
SOURCE = lexer.l
INPUT = sample_input.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(FLEX) -o $(TARGET).c $(SOURCE)
	$(CC) -o $(TARGET) $(TARGET).c -lfl

test: $(TARGET)
	./$(TARGET) < $(INPUT)

clean:
	rm -f $(TARGET) $(TARGET).c

install:
	sudo apt-get update
	sudo apt-get install flex build-essential

help:
	@echo "Available targets:"
	@echo "  all     - Build the lexical analyzer"
	@echo "  test    - Run the analyzer with sample input"
	@echo "  clean   - Remove generated files"
	@echo "  install - Install required dependencies (Ubuntu/Debian)"
	@echo "  help    - Show this help message"

.PHONY: all test clean install help
