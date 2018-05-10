CC=g++
CXXFLAGS=-g --std=c++11
WIDGET=term.o application.o keystream.o widget.o
TARGETS=menutest game

all: $(TARGETS)
game: $(WIDGET) warrior.o paladin.o berzerker.o monk.o archer.o assassin.o mage.o necromancer.o menu.o game.o
menutest: $(WIDGET) menu.h menu.cpp
menu.o: menu.h menu.cpp
warrior.o: warrior.h warrior.cpp
paladin.o: paladin.h paladin.cpp
berzerker.o: berzerker.h berzerker.cpp
monk.o: monk.h monk.cpp
archer.o: archer.h archer.cpp
assassin.o: assassin.h assassin.cpp
mage.o: mage.h mage.cpp
necromancer.o: necromancer.h necromancer.cpp
widget.o: widget.h widget.cpp
term.o: term.h termmanip.h term.cpp
application.o: application.h application.cpp
keystream.o: keystream.h keystream.cpp


clean:
	rm -f *.o $(TARGETS)