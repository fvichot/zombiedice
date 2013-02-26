//        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//                    Version 2, December 2004 

// Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

// Everyone is permitted to copy and distribute verbatim or modified 
// copies of this license document, and changing it is allowed as long 
// as the name is changed. 

//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

//  0. You just DO WHAT THE FUCK YOU WANT TO.

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <vector>

#include "die.h"

class Player
{

protected:

  std::vector<Die> m_dice;
  std::string m_name;
  unsigned int m_points;

public:

  Player (const std::string& name);
  virtual ~Player () { }
  const std::string& name () const;
  void get_dice (Die d);
  unsigned int points () const;
  unsigned int score () const;
  bool is_dead () const;
  const std::vector<Die>& dice () const;
  void end_turn ();

};

#endif // PLAYER_H__
