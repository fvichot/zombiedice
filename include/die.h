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

#ifndef __DIE_H__
#define __DIE_H__

enum Die_type
  {
    GREEN,
    YELLOW,
    RED
  };

enum Face_type
  {
    BRAIN,
    SHOTGUN,
    RUNNING
  };

class Die
{

protected:
  
  Die_type m_type;
  unsigned int m_current_face;

public:

  Die (Die_type type);
  virtual ~Die () { }
  Die_type type () const;
  Face_type value () const;
  Face_type roll ();

};


#endif // DIE_H__
