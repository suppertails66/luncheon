#ifndef LISTMENUITEMEVENTTYPE_H
#define LISTMENUITEMEVENTTYPE_H

namespace Luncheon {


namespace ListMenuItemEventTypes {
  enum ListMenuItemEventType {
    dummy = 0,
    confirmed,
    confirmedDisabledItem,
    moved,
    cancelled,
    focusReturned
  };
};


}


#endif 
