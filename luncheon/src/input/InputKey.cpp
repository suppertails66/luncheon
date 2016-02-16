#include "input/InputKey.h"

namespace Luncheon {


std::string InputKeys::getKeyString(InputKey key) {
  switch (key) {
  case dummy:
    return "DUMMY";
    break;
  case esc:
    return "Esc";
    break;
  case backspace:
    return "Backspace";
    break;
  case tab:
    return "Tab";
    break;
  case enter:
    return "Enter";
    break;
  case lshift:
    return "Left Shift";
    break;
  case rshift:
    return "Right Shift";
    break;
  case lctrl:
    return "Left Ctrl";
    break;
  case rctrl:
    return "Right Ctrl";
    break;
  case lalt:
    return "Left Alt";
    break;
  case ralt:
    return "Right Alt";
    break;
  case zero:
    return "0";
    break;
  case one:
    return "1";
    break;
  case two:
    return "2";
    break;
  case three:
    return "3";
    break;
  case four:
    return "4";
    break;
  case five:
    return "5";
    break;
  case six:
    return "6";
    break;
  case seven:
    return "7";
    break;
  case eight:
    return "8";
    break;
  case nine:
    return "9";
    break;
  case a:
    return "A";
    break;
  case b:
    return "B";
    break;
  case c:
    return "C";
    break;
  case d:
    return "D";
    break;
  case e:
    return "E";
    break;
  case f:
    return "F";
    break;
  case g:
    return "G";
    break;
  case h:
    return "H";
    break;
  case i:
    return "I";
    break;
  case j:
    return "J";
    break;
  case k:
    return "K";
    break;
  case l:
    return "L";
    break;
  case m:
    return "M";
    break;
  case n:
    return "N";
    break;
  case o:
    return "O";
    break;
  case p:
    return "P";
    break;
  case q:
    return "Q";
    break;
  case r:
    return "R";
    break;
  case s:
    return "S";
    break;
  case t:
    return "T";
    break;
  case u:
    return "U";
    break;
  case v:
    return "V";
    break;
  case w:
    return "W";
    break;
  case x:
    return "X";
    break;
  case y:
    return "Y";
    break;
  case z:
    return "Z";
    break;
  case space:
    return "Space";
    break;
  case grave:
    return "Grave";
    break;
  case minus:
    return "Minus";
    break;
  case equals:
    return "Equals";
    break;
  case lbracket:
    return "Left Bracket";
    break;
  case rbracket:
    return "Right Bracket";
    break;
  case backslash:
    return "Backslash";
    break;
  case semicolon:
    return "Semicolon";
    break;
  case apostrophe:
    return "Apostrophe";
    break;
  case comma:
    return "Comma";
    break;
  case period:
    return "Period";
    break;
  case slash:
    return "Slash";
    break;
  case f1:
    return "F1";
    break;
  case f2:
    return "F2";
    break;
  case f3:
    return "F3";
    break;
  case f4:
    return "F4";
    break;
  case f5:
    return "F5";
    break;
  case f6:
    return "F6";
    break;
  case f7:
    return "F7";
    break;
  case f8:
    return "F8";
    break;
  case f9:
    return "F9";
    break;
  case f10:
    return "F10";
    break;
  case f11:
    return "F11";
    break;
  case f12:
    return "F12";
    break;
  case printscreen:
    return "Print Screen";
    break;
  case pause:
    return "Pause";
    break;
  case insert:
    return "Insert";
    break;
  case home:
    return "Home";
    break;
  case pageup:
    return "Page Up";
    break;
  case deletekey:
    return "Delete";
    break;
  case end:
    return "End";
    break;
  case pagedown:
    return "Page Down";
    break;
  case up:
    return "Up";
    break;
  case down:
    return "Down";
    break;
  case left:
    return "Left";
    break;
  case right:
    return "Right";
    break;
  case kp_divide:
    return "KP Divide";
    break;
  case kp_multiply:
    return "KP Multiply";
    break;
  case kp_minus:
    return "KP Minus";
    break;
  case kp_plus:
    return "KP Plus";
    break;
  case kp_enter:
    return "KP Enter";
    break;
  case kp_zero:
    return "KP 0";
    break;
  case kp_one:
    return "KP 1";
    break;
  case kp_two:
    return "KP 2";
    break;
  case kp_three:
    return "KP 3";
    break;
  case kp_four:
    return "KP 4";
    break;
  case kp_five:
    return "KP 5";
    break;
  case kp_six:
    return "KP 6";
    break;
  case kp_seven:
    return "KP 7";
    break;
  case kp_eight:
    return "KP 8";
    break;
  case kp_nine:
    return "KP 9";
    break;
  case kp_period:
    return "KP Period";
    break;
  case EndOfEnumPlaceholder:
    return "EndOfEnumPlaceholder";
    break;
  default:
    return "Unrecognized key";
    break;
  }
}


}; 
