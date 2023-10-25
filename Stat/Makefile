# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic

# Target executable
TARGET = binary

# Source files
SRCS = main.cpp radio.cpp Database.cpp UserInterface.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Library files
LIBS = lib_stat_roles.a

# Build the target executable
$(TARGET): main.o $(LIBS)
	$(CXX) -o $@ main.o -L. $(LIBS)

# Build object files from source files
%.o: ../%.cpp
	$(CXX) -c $< $(CXXFLAGS)

# Build library files from object files
lib_stat_roles.a: Database.o radio.o UserInterface.o
	ar cr $@ $^

# Clean up by removing object files, library files, and the target executable
clean:
	rm -f *.o *.a $(TARGET)


#binary: radio.o test_lib.a
#	g++ -o binary radio.o -L. test_lib.a
#
#radio.o: ../radio.cpp
#	g++ -c ../radio.cpp
#
#test_lib.a: Database.o UserInterface.o
#	ar cr test_lib.a Database.o UserInterface.o
#
#Database.o: ../Database.cpp
#	g++ -c ../Database.cpp
#
#UserInterface.o: ../UserInterface.cpp
#	g++ -c ../UserInterface.cpp
#
#clean:
#	rm -f *.o *.a binary