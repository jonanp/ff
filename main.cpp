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

#include "boot.hpp"
#include "character.hpp"

int main(int argc, char *argv[]) {
  boot();
  Ogre::SceneManager *scene = Ogre::Root::getSingleton().createSceneManager(Ogre::ST_GENERIC);
  Character player("Player", *scene);
  return 0;
}
