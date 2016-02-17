#ifndef TESTMEMORY_H
#define TESTMEMORY_H


#include "logic/GameMemory.h"

namespace LuncheonTest {


class TestMemory : public Luncheon::GameMemory {
public:
  TestMemory(Luncheon::GraphicsCore& graphicsCore__,
             Luncheon::FontCore& fontCore__,
             Luncheon::SoundCore& soundCore__,
             Luncheon::InputCore& inputCore__,
             Luncheon::TimingCore& timingCore__);
protected:
  
};


};

#endif
