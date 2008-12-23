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

#include "character.hpp"

#include <string>

// Constructor
Character::Character(const char *name, Ogre::SceneManager &scene_manager) {
  max_life = 1000;
  actual_life = max_life;
  max_power = 1000;
  actual_power = max_power;
  strength = 10;
  agility = 10;
  level = 1;
  node = scene_manager.getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,1,0));
  std::string entity_name = name;
  std::string file_name = entity_name + ".mesh";
  entity = scene_manager.createEntity(entity_name, file_name);
  entity->setCastShadows(true);
  node->attachObject(entity);
  setAnimations();
}

// Sets all the defined animations.
void Character::setAnimations(void) {
  animation[WALK] = entity->getAnimationState("Walkcycle");
  animation[WALK]->setLoop(true);
  animation[WALK]->setEnabled(false);
  animation[ATTACK] = entity->getAnimationState("kick");
  animation[ATTACK]->setLoop(false);
  animation[ATTACK]->setEnabled(false);
}
