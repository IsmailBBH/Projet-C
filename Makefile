

tester: main.c affichage.o possibilites.o
	gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` main.c possibilites.o affichage.o -o tester `pkg-config --libs-only-l MLV` 

affichage.o: affichage.c affichage.h
	gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` -c affichage.c `pkg-config --libs-only-l MLV`

possibilites.o: possibilites.c possibilites.h
	gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` -c possibilites.c `pkg-config --libs-only-l MLV`
	
clean:
	rm *.o
	rm tester
