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

#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>

inline void warning (const char* msg)
{
  std::cerr << "WARNING: " << msg << std::endl;
}

inline void error (const char* msg)
{
  std::cerr << "ERROR: " << msg << " Exiting..." << std::endl;
}

#endif // COMMON_H__
