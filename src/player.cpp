//        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//                    Version 2, December 2004 

// Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

// Everyone is permitted to copy and distribute verbatim or modified 
// copies of this license document, and changing it is allowed as long 
// as the name is changed. 

//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

//  0. You just DO WHAT THE FUCK YOU WANT TO.

#include <string>

#include "common.h"
#include "player.h"

Player::Player (const std::string& name)
{
  m_name = name;
  m_points = 0;
}

const std::string& Player::name () const
{
  return m_name;
}

void Player::get_dice (Die d)
{
  m_dice.push_back (d);
}

unsigned int Player::shotguns () const
{
  unsigned int out = 0;
  for (unsigned int i = 0; i < m_dice.size (); ++ i)
    if (m_dice[i].value () == SHOTGUN)
      ++ out;
  return out;
}

unsigned int Player::points () const
{
  unsigned int out = 0;
  for (unsigned int i = 0; i < m_dice.size (); ++ i)
    if (m_dice[i].value () == BRAIN)
      ++ out;
  return out;
}

unsigned int Player::score () const
{
  return m_points;
}

bool Player::is_dead () const
{
  int shotguns = 0;
  for (unsigned int i = 0; i < m_dice.size (); ++ i)
    if (m_dice[i].value () == SHOTGUN)
      ++ shotguns;

  return (shotguns > 2);
}

const std::vector<Die>& Player::dice () const
{
  return m_dice;
}

void Player::end_turn ()
{
  if (!is_dead ())
    m_points += points ();

  m_dice.clear ();
}
