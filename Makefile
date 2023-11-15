CC = g++

CFLAGS = -Wall -std=c++11


TARGET = meu_programa


SOURCES = headers.cpp main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES:.cpp=.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(SOURCES:.cpp=.o)
