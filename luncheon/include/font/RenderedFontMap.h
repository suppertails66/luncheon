#ifndef RENDEREDFONTMAP_H
#define RENDEREDFONTMAP_H


#include <unordered_map>
#include <string>
#include "font/RenderedFont.h"

namespace Luncheon {


typedef std::unordered_map<std::string,RenderedFont*> RenderedFontMap;
typedef std::pair<std::string,RenderedFont*> RenderedFontMapPair;


};


#endif 
