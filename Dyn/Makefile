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
LIBS = lib_dyn_roles.so

# Build the target executable
$(TARGET): main.o $(LIBS)
	$(CXX) -o $@ main.o -L. $(LIBS) -Wl,--rpath -Wl,.

# Build object files from source files
%.o: ../%.cpp
	$(CXX) -c -fPIC $< $(CXXFLAGS)

# Build library files from object files
lib_dyn_roles.so: Database.o radio.o UserInterface.o
	gcc -shared -o $@ $^

# Clean up by removing object files, library files, and the target executable
clean:
	rm -f *.o *.so $(TARGET)


#binary: radio.o test_lib.so
#	g++ -o binary radio.o -L. test_lib.so -Wl,--rpath -Wl,.
#
#radio.o: ../radio.cpp
#	g++ -c ../radio.cpp
#
#test_lib.so: Database.o UserInterface.o
#	g++ -shared -o test_lib.so Database.o UserInterface.o
#
#Database.o: ../Database.cpp
#	g++ -c -fPIC ../Database.cpp
#
#UserInterface.o: ../UserInterface.cpp
#	g++ -c -fPIC ../UserInterface.cpp
#
#clean:
#	rm -f *.so *.a binary