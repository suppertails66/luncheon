#ifndef CHARACTERCODEFONTMAP_H
#define CHARACTERCODEFONTMAP_H


#include <unordered_map>
#include "font/RenderedFontCharacter.h"
#include "font/CharacterCode.h"

namespace Luncheon {


typedef std::unordered_map<CharacterCode, RenderedFontCharacter*> CharacterCodeFontMap;
typedef std::pair<CharacterCode, RenderedFontCharacter*> CharacterCodeFontMapPair;


};


#endif 
