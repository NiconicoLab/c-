CXX = g++
CXXFLAGS = -Wall -O -std=c++14 `pkg-config opencv4 --cflags`
LDFLAGS = `pkg-config opencv4 --libs`

all: show_image

clean:
	rm -rf show_image *.o *~

show_image:
