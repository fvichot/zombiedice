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
#include <iostream>
#include <sstream>
#include <vector>

#include "common.h"
#include "dice_set.h"
#include "die.h"
#include "display_tty.h"
#include "player.h"

typedef Display_tty Display;

int main (int argc, char** argv)
{
  if (argc == 1)
    {
      std::cout << "Usage: " << argv[0] << " [nb_players]" << std::endl;
      return EXIT_SUCCESS;
    }

  unsigned int nb_players = argv[1][0];
  std::istringstream ss(argv[1]);
  if (!(ss >> nb_players))
    {
      error ("Invalid argument.");
    }
  if (2 > nb_players || nb_players > 8)
    {
      std::cout << "2 to 8 players only." << std::endl;
      return EXIT_SUCCESS;
    }

  Display display;
  Dice_set main_set;
  std::vector<Player> players;

  display.opening (nb_players);

  for (unsigned int i = 0; i < nb_players; ++ i)
    {
      display.ask_for_name (i + 1);
      std::string name;
      std::cin >> name;
      Player p (name);
      players.push_back (p);
    }

  unsigned int current_player = rand () % nb_players;

  bool last_turn = false;
  unsigned int remaining_turns = nb_players;

  while (true)
    {
      main_set.init ();
      Player& p = players[current_player];
      if (last_turn)
	{
	  -- remaining_turns;
	  if (remaining_turns == 0)
	    break;
	  display.last_turn ();
	}
      display.begin_turn (p.name ());

      std::vector<Die> running;
      while (true)
	{
	  for (unsigned int i = 0; i < running.size (); ++ i)
	    main_set.insert (running[i]);
	  running.clear ();

	  for (unsigned int i = 0; i < 3; ++ i)
	    if (!main_set.empty ())
	      {
		Die d = main_set.pick ();
		if (d.roll () == RUNNING)
		  running.push_back (d);
		else
		  p.get_dice (d);
	      }
	  display.player_dice (p);
	  for (unsigned int i = 0; i < running.size (); ++ i)
	    display.one_die (running[i]);

	  if (p.is_dead ())
	    {
	      display.dead (p);
	      break;
	    }

	  display.what_now ();
	  std::string choice;
	  do
	    {
	      std::cin >> choice;
	    }
	  while (choice != "k" && choice != "s");

	  if (choice == "s")
	    {
	      display.stop (p);
	      break;
	    }
	}
      p.end_turn ();

      for (unsigned int i = 0; i < players.size (); ++ i)
	{
	  display.points (players[i]);
	  if (players[i].score () > 12)
	    last_turn = true;
	}
	      
      current_player = (current_player + 1) % nb_players;
    }

  unsigned int winner = 0;
  unsigned int best_score = 0;
  for (unsigned int i = 0; i < players.size (); ++ i)
    if (players[i].score () > best_score)
      {
	winner = i;
	best_score = players[i].score ();
      }

  display.winner (players[winner]);


  return EXIT_SUCCESS;
}
