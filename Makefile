

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
TARGET = project
SRC = project.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
