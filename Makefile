##
## EPITECH PROJECT, 2023
## B-OOP-400-LYN-4-1-raytracer-guilhem.vinet
## File description:
## Makefile
##

.PHONY: all clean fclean re

CXX          = g++
TARGET       = raytracer

INST         = $(shell uname -m)
ARCH         = $(shell uname -s)
SRC          := $(shell find . -name "*.cpp")

CXXFLAGS     += -Wall -Wextra ##-Werror
CXXFLAGS     += -I./include/
CXXFLAGS     += -std=c++20 -c -I. -O2 -g3 -o

LDFLAGS      =
LDLIBS       = -lstdc++ -lconfig++

OBJECTS      := $(SRC:%.cpp=%.o)

all : $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "LD 	$(TARGET)"
	@$(CXX) -o $@ $(LDFLAGS) $^ $(LDLIBS)
	@echo "OK: built $(TARGET) for $(ARCH) ($(INST))."

%.o: %.cpp
	@echo "CXX 	$<"
	@$(CXX) $< $(CXXFLAGS) $@

clean:
	@rm -rf $(TARGET)

fclean: clean
	@$(shell find . -name "*.o" -delete)
	@echo "OK: cleaned few files"

re: fclean all
