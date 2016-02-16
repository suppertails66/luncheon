AR=ar
CXX=g++
# Compile only
CDEFINES = -dLUNCHEON_ENABLE_FREETYPE
CLIBS = -lSDL2 -lfreetype -lvorbisfile
CFLAGS = -std=gnu++11 -O2 -Wall
CINCLUDES = -I/usr/local/include/SDL2 -I/usr/include/freetype2 -I/usr/include/vorbis
CXXFLAGS=$(CFLAGS) $(DEFINES) $(DEFINES) $(CINCLUDES) -I$(IDIR)

IDIR := include
SRCDIR := src
ODIR := obj
LDIR :=

SRC := $(wildcard $(SRCDIR)/*/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%,$(ODIR)/%,$(patsubst %.cpp,%.o,$(SRC)))
DEP := $(patsubst %.o,%.d,$(OBJ))
LIB := libluncheon.a

all: $(LIB)

-include $(DEP)

$(ODIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c -MMD -MP -MF $(@:.o=.d) -o $@ $< $(CXXFLAGS)

$(LIB): $(OBJ)
	$(AR) rcs $@ $^
	#doxygen Doxyfile

.PHONY: clean

clean:
	rm -f $(LIB)
	rm -rf $(ODIR)
