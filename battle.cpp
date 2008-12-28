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

#include "character.hpp"
#include "input_systems.hpp"

// Constructor
Battle::Battle(std::vector<Character*> team1, std::vector<Character*> team2) {
  this->team1 = team1;
  this->team2 = team2;
  scene_manager = Ogre::Root::getSingleton().createSceneManager(Ogre::ST_GENERIC);
  scene_manager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
  viewport = Ogre::Root::getSingleton().getAutoCreatedWindow()->addViewport(NULL);
  camera = scene_manager->createCamera("battle");
  camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));
  camera->setPosition(30,30,0);
  camera->lookAt(Ogre::Vector3(0,15,0));
  camera->setNearClipDistance(1);
  camera->setFarClipDistance(1000);
  viewport->setCamera(camera);
  light = scene_manager->createLight("battle");
  scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));
  // Add plane
  Ogre::Plane plane_ogre(Ogre::Vector3::UNIT_Y, 0);
  Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                                plane_ogre, 1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
  plane = scene_manager->createEntity("ground", "ground");
  plane->setCastShadows(false);
  scene_manager->getRootSceneNode()->createChildSceneNode()->attachObject(plane);
  setCharacters();
}

// 
void Battle::start(void) {
  Ogre::Root::getSingleton().addFrameListener(this);
  Ogre::Root::getSingleton().startRendering();
}

// 
void Battle::setCharacters(void) {
  int x=-15, y=0, z=-15;
  std::vector<Character*> team = team1;
  for (int j=0; j<2; j++) {
    for (unsigned int i=0; i<team.size(); i++) {
      team[i]->addToBattle(this, Ogre::Vector3(x,y,z));
      x+=15;
    }
    x=-15;
    z=+15;
    team = team2;
  }
}

// This function is called at the beginnig of every frame.
bool Battle::frameStarted(const Ogre::FrameEvent &event) {
  return !input::keyboard[OIS::KC_ESCAPE];
}
