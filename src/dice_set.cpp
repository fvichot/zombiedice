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
#include <utility>
#include <vector>
#include <algorithm>

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

bool comp_pair(const std::pair<int, Die> & a,
               const std::pair<int, Die> & b) {
   return (a.first < b.first);
}

void Dice_set::init ()
{
  clear ();

  std::vector<Die> dice;

  for (int i = 0; i < 6; ++ i)
    dice.push_back (Die (GREEN));
  for (int i = 0; i < 4; ++ i)
    dice.push_back (Die (YELLOW));
  for (int i = 0; i < 3; ++ i)
    dice.push_back (Die (RED));

  std::vector<std::pair<int, Die> > tmp;
  for (int i = 0; i < 13; ++ i)
    tmp.push_back(std::make_pair(rand(), dice[i]));

  std::sort (tmp.begin(), tmp.end(), comp_pair);
  
  for (int i = 0; i < 13; ++ i)
    insert(tmp[i].second);
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
