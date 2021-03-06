CXX := g++ -std=c++11
CFLAGS = -g -Wall -Wno-unused-function -I./include/ -MMD
LDFLAGS := -lrt -lm -ldl -lX11 -lpthread -lXrandr -lXinerama -lXxf86vm -lXcursor
LDLIBS := ./lib-linux/libglfw3.a

CXX_SOURCES := $(wildcard src/*.cpp)
C_SOURCES := $(wildcard src/*.c)
CXX_OBJECTS := $(CXX_SOURCES:%.cpp=%.o)
C_OBJECTS := $(C_SOURCES:%.c=%.o)
OBJECTS := $(CXX_OBJECTS) $(C_OBJECTS)
DEPENDENCIES := $(OBJECTS:.o=.d)

EXEC := ./main

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CXX) -c -o $@ $^ $(CFLAGS)

.PHONY: clean run
clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)
	rm -f $(EXEC)

run: $(EXEC)
	./$<

-include $(DEPENDENCIES)