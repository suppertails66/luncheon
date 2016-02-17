CXX=g++
# Compile only
DEFINES =
CXXFLAGS=-std=gnu++11 -O2 -Wall -lSDL2 -lfreetype -lvorbisfile -lluncheon $(DEFINES)
INCLUDES=-I../luncheon/include -I/usr/local/include/SDL2 -I/usr/include/freetype2 -I/usr/include/vorbis
LIBRARIES=-L../luncheon

all:
	cd ../luncheon && $(MAKE) && cd $(CURDIR)
	$(CXX) *.cpp -o test $(INCLUDES) $(LIBRARIES) $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f *.o
