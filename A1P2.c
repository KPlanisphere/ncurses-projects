#include <ncurses.h>
int main() {
	initscr();
	move (10, 12);
	printw("Hola linux");
	refresh();
	getch();
	endwin();
	return 0;
}

