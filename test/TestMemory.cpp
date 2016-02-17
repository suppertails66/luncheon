#include "TestMemory.h"

using namespace Luncheon;

namespace LuncheonTest {


TestMemory::TestMemory(GraphicsCore& graphicsCore__,
           FontCore& fontCore__,
           SoundCore& soundCore__,
           InputCore& inputCore__,
           TimingCore& timingCore__)
  : GameMemory(graphicsCore__,
               fontCore__,
               soundCore__,
               inputCore__,
               timingCore_) { };


};
