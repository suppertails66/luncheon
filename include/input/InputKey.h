#ifndef INPUTKEY_H
#define INPUTKEY_H


#include <string>

namespace Luncheon {


namespace InputKeys {
  enum InputKey {
    dummy = 0,
    
    esc,
    backspace,
    tab,
    enter,
    lshift,
    rshift,
    lctrl,
    rctrl,
    lalt,
    ralt,
    
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
    j,
    k,
    l,
    m,
    n,
    o,
    p,
    q,
    r,
    s,
    t,
    u,
    v,
    w,
    x,
    y,
    z,
    space,
    
    grave,
    minus,
    equals,
    lbracket,
    rbracket,
    backslash,
    semicolon,
    apostrophe,
    comma,
    period,
    slash,
    
    f1,
    f2,
    f3,
    f4,
    f5,
    f6,
    f7,
    f8,
    f9,
    f10,
    f11,
    f12,
    
    printscreen,
    pause,
    insert,
    home,
    pageup,
    deletekey,
    end,
    pagedown,
    
    up,
    down,
    left,
    right,
    
    kp_divide,
    kp_multiply,
    kp_minus,
    kp_plus,
    kp_enter,
    kp_zero,
    kp_one,
    kp_two,
    kp_three,
    kp_four,
    kp_five,
    kp_six,
    kp_seven,
    kp_eight,
    kp_nine,
    kp_period,
    
    EndOfEnumPlaceholder  // for quick initialization of maps
  };
  
  std::string getKeyString(InputKey key);
};


};


#endif 
