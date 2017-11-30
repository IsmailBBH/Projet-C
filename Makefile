

tester: test.c affichage.o possibilites.o
	gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` -g test.c `pkg-config --libs-only-l MLV` possibilites.o affichage.o  -o affichage

affichage.o: affichage.c affichage.h
	gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` -g affichage.c `pkg-config --libs-only-l MLV` -o affichage

possibilites.o: possibilites.c possibilites.h
	gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` -g possibilites.c `pkg-config --libs-only-l MLV` -o possibilites

