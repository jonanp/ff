/*
FF
Copyright (C) 2008 Jon Ander Peñalba <jonan88@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License version 3 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include "battle.hpp"
#include "boot.hpp"
#include "character.hpp"

int main(int argc, char *argv[]) {
  boot();
  Character *char1 = new Character("orc_archer");
  Character *char2 = new Character("Player");
  std::vector<Character*> team1;
  std::vector<Character*> team2;
  team1.push_back(char1);
  team2.push_back(char2);
  Battle *battle = new Battle(team1, team2);
  battle->start();
  delete battle;
  delete char1;
  delete char2;
  return 0;
}
