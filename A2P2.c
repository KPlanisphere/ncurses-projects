#include <stdlib.h>
#include <ncurses.h>
#include <errno.h>
#include <unistd.h>

int main(){
	initscr();
	start_color();
	init_pair (1,COLOR_BLUE,COLOR_YELLOW);
	init_pair (2,COLOR_RED,COLOR_YELLOW);
	bkgd (COLOR_PAIR(2));
	attron(COLOR_PAIR(1)| A_UNDERLINE);
	move (10,40);
	attron(A_REVERSE);
	printw("HOLA MUNDO");
	getch();
	endwin();
	exit(0);
}


