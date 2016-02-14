#ifndef COREMANAGER_H
#define COREMANAGER_H


#include "graphics/GraphicsCore.h"
#include "graphics/GraphicsCoreType.h"
#include "font/FontCore.h"
#include "font/FontCoreType.h"
#include "sound/SoundCore.h"
#include "sound/SoundCoreType.h"
#include "input/InputCore.h"
#include "input/InputCoreType.h"
#include "timing/TimingCore.h"
#include "timing/TimingCoreType.h"

namespace Luncheon {


class CoreManager {
public:
  ~CoreManager();
  
  CoreManager();
  
  void initializeCores();
  
  GraphicsCoreTypes::GraphicsCoreType graphicsCoreType();
  void setGraphicsCoreType(GraphicsCoreTypes::GraphicsCoreType
    graphicsCoreType__);
  
  FontCoreTypes::FontCoreType fontCoreType();
  void setFontCoreType(FontCoreTypes::FontCoreType
    fontCoreType__);
  
  SoundCoreTypes::SoundCoreType soundCoreType();
  void setSoundCoreType(SoundCoreTypes::SoundCoreType
    soundCoreType__);
  
  InputCoreTypes::InputCoreType inputCoreType();
  void setInputCoreType(InputCoreTypes::InputCoreType
    inputCoreType__);
  
  TimingCoreTypes::TimingCoreType timingCoreType();
  void setTimingCoreType(TimingCoreTypes::TimingCoreType
    timingCoreType__);
  
  GraphicsCore& graphicsCore();
  
  FontCore& fontCore();
  
  SoundCore& soundCore();
  
  InputCore& inputCore();
  
  TimingCore& timingCore();
  
protected:

  GraphicsCoreTypes::GraphicsCoreType graphicsCoreType_;
  
  FontCoreTypes::FontCoreType fontCoreType_;
  
  SoundCoreTypes::SoundCoreType soundCoreType_;
  
  InputCoreTypes::InputCoreType inputCoreType_;
  
  TimingCoreTypes::TimingCoreType timingCoreType_;
  
  GraphicsCore* graphicsCore_;
  
  FontCore* fontCore_;
  
  SoundCore* soundCore_;
  
  InputCore* inputCore_;
  
  TimingCore* timingCore_;
  
  // Initialize any libraries needed by the selected cores
  void initializeCorePrerequisites();
  
  // Shut down anything initialized by initializeCorePrerequisites()
  void shutDownCorePrerequisites();
  
};


};


#endif
