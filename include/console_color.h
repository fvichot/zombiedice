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

#ifndef __CONSOLE_COLOR_H__
#define __CONSOLE_COLOR_H__

#include <iostream>

#if defined(WIN32)
#include <windows.h>
#endif

inline std::ostream& blue(std::ostream &s)
{
#if defined(WIN32)
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
#else
  s << "\e[0;34m";
#endif
  return s;
}

inline std::ostream& red(std::ostream &s)
{
#if defined(WIN32)
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hStdout, FOREGROUND_RED|FOREGROUND_INTENSITY);
#else
  s << "\e[0;31m";
#endif
  return s;
}

inline std::ostream& green(std::ostream &s)
{
#if defined(WIN32)
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
#else
  s << "\e[0;32m";
#endif
  return s;
}

inline std::ostream& yellow(std::ostream &s)
{
#if defined(WIN32)
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
#else
  s << "\e[0;33m";
#endif
  return s;
}

inline std::ostream& white(std::ostream &s)
{
#if defined(WIN32)
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hStdout, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#else
  s << "\e[0;37m";
#endif
  return s;
}

#endif // CONSOLE_COLOR_H__
