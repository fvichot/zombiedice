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

#include <cstdlib>
#include <ctime>
#include <stack>

#include "common.h"
#include "dice_set.h"

Dice_set::Dice_set ()
{
  srand (time (NULL));
  init ();
}

bool Dice_set::empty () const
{
  return m_set.empty ();
}

void Dice_set::clear ()
{
  while (!m_set.empty ())
    m_set.pop ();
}

void Dice_set::init ()
{
  clear ();

  std::stack<Die> dice[3];

  for (int i = 0; i < 6; ++ i)
    dice[0].push (Die (GREEN));
  for (int i = 0; i < 4; ++ i)
    dice[1].push (Die (YELLOW));
  for (int i = 0; i < 3; ++ i)
    dice[2].push (Die (RED));

  while (!(dice[0].empty () && dice[1].empty () && dice[2].empty ()))
    {
      unsigned int index;
      do
	{
	  index = rand () % 3;
	}
      while (dice[index].empty ());

      Die die = dice[index].top ();
      dice[index].pop ();
      insert (die);
    }

}

Die Dice_set::pick ()
{
  Die out = m_set.top ();
  m_set.pop ();
  return out;
}

void Dice_set::insert (const Die& d)
{
  m_set.push (d);
}
