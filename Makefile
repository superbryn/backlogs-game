# Compiler and Flags
CXX = clang++
CXXFLAGS = -std=c++17 -Iinclude -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -llua

# Find all .cpp files recursively in src/
SRC = $(shell find src -name "*.cpp")
# Convert .cpp paths to .o paths in a build directory to keep src clean
OBJ = $(SRC:.cpp=.o)

# The final executable name and location
TARGET = bin/game

# Default rule
all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)
	@echo "Run with ./bin/game"

# Rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to start fresh
clean:
	rm -f $(OBJ) $(TARGET)
