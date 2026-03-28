CXX = g++
CXXFLAGS = -Wall -Iinclude

SRC = main.cpp $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)