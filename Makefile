CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = test_FlexLL

SRC = test_FlexLL.cpp TVShow.cpp FlexLL.cpp Episode.cpp

HEADERS = TVShow.h FlexLL.h Actor.h Episode.h

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)
