CXX := g++
CXXFLAGS := -std=c++11 -Wall
TARGET := dynamic_link_example
LIBS := v1/fun.so v2/fun.so

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.cpp $(LIBS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -ldl

v1/fun.so: v1/fun.cpp
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $<

v2/fun.so: v2/fun.cpp
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $<

clean:
	rm -f $(TARGET) $(LIBS)
