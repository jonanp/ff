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

/// @file
/// 
/// @author Jonan

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <Ogre.h>

#include "macros.hpp"

/// Types of animations.
enum {WALK,
      ATTACK,
      NUM_ANIMATIONS};

class Battle;

/// 
class Character {
  public:
    Character(std::string name); // Constructor
    ~Character(void) {} // Destructor

    /// 
    void addToBattle(Battle *battle, Ogre::Vector3 position);

  private:
    // Sets all the defined animations.
    void setAnimations(void);

    std::string name;
    double max_life, actual_life;
    double max_power, actual_power;
    double strength, agility;
    int level;

    Ogre::SceneNode *node;
    Ogre::Entity *entity;

    Ogre::AnimationState* animation[NUM_ANIMATIONS];

    DISALLOW_COPY_AND_ASSIGN(Character);
};

#endif // CHARACTER_HPP
