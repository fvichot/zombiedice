//        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//                    Version 2, December 2004 

// Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

// Everyone is permitted to copy and distribute verbatim or modified 
// copies of this license document, and changing it is allowed as long 
// as the name is changed. 

//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

//  0. You just DO WHAT THE FUCK YOU WANT TO.

#ifndef __DISPLAY_TTY_H__
#define __DISPLAY_TTY_H__

#include "player.h"

class Display_tty
{

protected:

public:

  Display_tty ();
  virtual ~Display_tty () { }
  void opening (const unsigned int nb_players) const;
  void ask_for_name (const unsigned int index) const;
  void begin_turn (const Player& p) const;
  void player_dice (const Player& p) const;
  void one_die (const Die& d) const;
  void dead (const Player& p) const;
  void stop (const Player& p) const;
  void what_now () const;
  void points (const Player& p) const;
  void last_turn () const;
  void winner (const Player& p) const;
};


#endif // DISPLAY_TTY_H__
