# FF
# Copyright (C) 2008 Jon Ander Peñalba <jonan88@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>

DEFINES =
OBJECTS = battle.o boot.o character.o input.o main.o
LIBRARIES = OGRE OIS
CC = g++ -Wall -Wno-deprecated -g -c
CFLAGS = $(shell pkg-config --cflags $(LIBRARIES)) $(DEFINES)
LIBS = $(shell pkg-config --libs $(LIBRARIES))

ff: $(OBJECTS)
	g++ -Wall -Wno-deprecated -g $(OBJECTS) $(CFLAGS) $(LIBS) -o ff

battle.o: battle.cpp battle.hpp input_systems.hpp macros.hpp
	$(CC) $(CFLAGS) battle.cpp

boot.o: boot.cpp boot.hpp input.hpp macros.hpp
	$(CC) $(CFLAGS) boot.cpp

character.o: character.cpp character.hpp macros.hpp
	$(CC) $(CFLAGS) character.cpp

input.o: input.cpp input.hpp input_systems.hpp macros.hpp
	$(CC) $(CFLAGS) input.cpp

main.o: main.cpp battle.hpp boot.hpp macros.hpp
	$(CC) $(CFLAGS) main.cpp

.PHONY : all clean

all: clean
	make

clean:
	rm -f fog *~ $(OBJECTS)

