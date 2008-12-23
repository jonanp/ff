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

#include <Ogre.h>

#include "input.hpp"

// Loads the Ogre plugins that will be used.
void loadPlugins(Ogre::Root *ogre_root) {
  ogre_root->loadPlugin("RenderSystem_GL"); // OpenGL
  ogre_root->loadPlugin("Plugin_ParticleFX"); // Particle system
  //ogre_root->loadPlugin("Plugin_OctreeSceneManager"); // Octree-based scene graph and manager
}

// Defines where resources are (according to resources.cfg).
void defineResources(void) {
  using Ogre::ConfigFile;

  Ogre::String section_name, type_name, arch_name;
  ConfigFile file;

  file.load("resources.cfg");
  ConfigFile::SectionIterator section = file.getSectionIterator();
  while (section.hasMoreElements()) {
    section_name = section.peekNextKey();
    ConfigFile::SettingsMultiMap *settings = section.getNext();
    ConfigFile::SettingsMultiMap::iterator i;
    for (i = settings->begin(); i != settings->end(); i++) {
      type_name = i->first;
      arch_name = i->second;
      Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name, type_name, section_name);
    }
  }
}

// Setups Ogre's render system.
void setupRenderSystem(Ogre::Root *ogre_root) {
  // Try to use previous configuration (stored in ogre.cfg)
  if (!ogre_root->restoreConfig()) {
    // If there's no configuration file set defaults
    Ogre::RenderSystem* render_system = ogre_root->getRenderSystemByName("OpenGL Rendering Subsystem");
    ogre_root->setRenderSystem(render_system);
    render_system->setConfigOption("Full Screen", "No");
    render_system->setConfigOption("Video Mode", "800 x 600");
    ogre_root->saveConfig();

    // Print all the configuration options
    /*#include <iostream>
    using std::cout;
    using std::endl;
    Ogre::ConfigOptionMap::iterator i;
    Ogre::ConfigOptionMap config = render_system->getConfigOptions();
    for (i = config.begin(); i != config.end(); i++) {
      cout << i->first << " " << i->second.name << endl;
      cout << i->first << " " << i->second.currentValue << endl;
      Ogre::StringVector::iterator j;
      for (j = i->second.possibleValues.begin(); j != i->second.possibleValues.end(); j++)
        cout << *j << endl;
      cout << i->first << " " << i->second.immutable << endl;
    }*/
  }
  ogre_root->initialise(true, "FF");
}

// Initializes all the resources the program will need.
void initializeAllResources(void) {
  /// @todo Don't load all resources, load them as they are needed.
  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

// This function loads all the necessary things that Ogre needs
// to work. It has to be called first thing in the program.
void boot(void) {
  Ogre::Root *ogre_root = new Ogre::Root;

  // For the moment plugins are loaded according to plugins.cfg
  //loadPlugins(ogre_root);
  defineResources();
  setupRenderSystem(ogre_root);
  initializeAllResources();
  // Start capturing all input
  input::Input::getInstance();
}
