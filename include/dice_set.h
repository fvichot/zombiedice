//        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//                    Version 2, December 2004 
//
// Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 
//
// Everyone is permitted to copy and distribute verbatim or modified 
// copies of this license document, and changing it is allowed as long 
// as the name is changed. 
//
//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 
//
//  0. You just DO WHAT THE FUCK YOU WANT TO.

#ifndef __DICE_SET_H__
#define __DICE_SET_H__

#include <stack>

#include "die.h"

class Dice_set
{

protected:

  std::stack<Die> m_set;

public:

  Dice_set ();
  virtual ~Dice_set () { }
  bool empty () const;
  void clear ();
  void init ();
  Die pick ();
  void insert (const Die& d);

};


#endif // DICE_SET_H__
