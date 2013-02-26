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

#include "common.h"
#include "die.h"

Die::Die (Die_type type)
{
  if (type > 3)
    error ("Wrong die type.");
  m_type = type;
  m_current_face = 0;
}

Die_type Die::type () const
{
  return m_type;
}

Face_type Die::value () const
{
  if (m_current_face == 0)
    return BRAIN;
  if (m_current_face == 1)
    {
      if (m_type == RED)
	return RUNNING;
      return BRAIN;
    }
  if (m_current_face == 2)
    {
      if (m_type == GREEN)
	return BRAIN;
      return RUNNING;
    }
  if (m_current_face == 3)
    {
      if (m_type == RED)
	return SHOTGUN;
      return RUNNING;
    }
  if (m_current_face == 4)
    {
      if (m_type == GREEN)
	return RUNNING;
      return SHOTGUN;
    }
  return SHOTGUN;
}

Face_type Die::roll ()
{ 
  m_current_face = (unsigned int)(6. * (rand () / (double)RAND_MAX));
  return value ();
}

