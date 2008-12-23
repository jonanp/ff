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

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <Ogre.h>

#include "macros.hpp"

/// 
class Battle : public Ogre::FrameListener {
  public:
    Battle(void); // Constructor
    ~Battle(void) {} // Destructor

    /// 
    void start();

  private:
    // This function is called at the beginnig of every frame.
    virtual bool frameStarted(const Ogre::FrameEvent& event);

    Ogre::SceneManager *scene_manager;
    Ogre::Camera *camera;
    Ogre::Viewport *viewport;
    Ogre::Light *light;

    Ogre::Entity *plane;

    DISALLOW_COPY_AND_ASSIGN(Battle);
};

#endif // BATTLE_HPP
