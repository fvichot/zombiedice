//        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//                    Version 2, December 2004 

// Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

// Everyone is permitted to copy and distribute verbatim or modified 
// copies of this license document, and changing it is allowed as long 
// as the name is changed. 

//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

//  0. You just DO WHAT THE FUCK YOU WANT TO.

#include <cstdlib>
#include <string>
#include <vector>

#include "common.h"
#include "console_color.h"
#include "display_tty.h"

Display_tty::Display_tty ()
{

}

void Display_tty::opening (const unsigned int nb_players) const
{
  std::cout << "===================" << std::endl;
  std::cout << "=== ZOMBIE DICE ===" << std::endl;
  std::cout << "===================" << std::endl << std::endl;
  std::cout << nb_players << " PLAYERS" << std::endl << std::endl;
}

void Display_tty::ask_for_name (const unsigned int index) const
{
  std::cout << "Name of player " << index << "? ";
}

void Display_tty::begin_turn (const Player& p) const
{
  unsigned int r = rand () % 4;
  switch (r)
    {
    case 0:
      std::cout << std::endl << blue
		<< p.name () << white << "'s turn! Let's roll:" << std::endl;
      break;
    case 1:
      std::cout << std::endl << "Come on, " << blue
		<< p.name () << white << ", make us proud!" << std::endl;
      break;
    case 2:
      std::cout << std::endl << "Hurry, " << blue
		<< p.name () << white << ", the brains are waiting!" << std::endl;
      break;
    case 3:
      std::cout << std::endl << blue
		<< p.name () << white << " seems hungry for brains!" << std::endl;
      break;
    default:
      std::cout << "IT IS APOCALYPSE, RUN FOR YOUR LIVES!" << std::endl;
    }
}

void Display_tty::player_dice (const Player& p) const
{
  std::vector<Die> d = p.dice ();
  for (unsigned int i = 0; i < d.size (); ++ i)
    {
      one_die (d[i]);
    }
}

void Display_tty::one_die (const Die& d) const
{
  switch (d.type ())
    {
    case GREEN:
      std::cout << green;
      break;
    case YELLOW:
      std::cout << yellow;
      break;
    case RED:
      std::cout << red;
      break;
    default:
      std::cout << white << "Apocalypse die: ";
    }
  switch (d.value ())
    {
    case BRAIN:
      std::cout << "[     BRAIN     ]";
      break;
    case RUNNING:
      std::cout << "[ STILL RUNNING ]";
      break;
    case SHOTGUN:
      std::cout << "[    SHOTGUN    ]";
      break;
    default:
      std::cout << "[  APOCALYPSE   ]";
    }
  std::cout << white << std::endl;
}

void Display_tty::dead (const Player& p) const
{
  std::cout << std::endl << red << "==> " << p.name ()
	    << " is dead!" << white << std::endl;
}

void Display_tty::stop (const Player& p) const
{
  std::cout << std::endl << green << "==> " << p.name ()
	    << " stops and gets " << p.points ()
	    << " points!" << white << std::endl;
}


void Display_tty::what_now () const
{
  std::cout << "What do you wanna do now?" << std::endl
	    << "   k = Keep going, I want braaaaiins!!!" << std::endl
	    << "   s = Stop, I've had enough..." << std::endl;
}

void Display_tty::points (const Player& p) const
{
  std::cout << blue << p.name () << white
	    << " has " << p.score () << " points." << std::endl;
}

void Display_tty::last_turn () const
{
  std::cout << "LAST TURN!" << std::endl;
}

void Display_tty::winner (const Player& p) const
{
  std::cout << std::endl << blue << p.name () << white
	    << " wins the game! Congratulations!" << std::endl << std::endl;
}

