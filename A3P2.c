#include <stdlib.h>
#include <ncurses.h>
#include <errno.h>
#include <unistd.h>

int main()
{
	int c,t=0;
	int xmax,ymax;
	char cadena[80];
	WINDOW *punt_ven;
	initscr();
	/*crnode();*/
	getmaxyx(stdscr,ymax, xmax);
	/*if((punt_ven=subwin(stdscr,3,40, ymax/3, (xmax-40)/2))==NULL)
	exit(-1);*/
	if(has_colors())
	start_color();
	init_pair (1,COLOR_RED,COLOR_GREEN);
	attron(COLOR_PAIR(1));
	punt_ven=subwin (stdscr,3,40,8, 20);
	box (punt_ven, ACS_VLINE, ACS_HLINE);
	move(9,33);
	mvwaddstr(punt_ven,1,1, "Contraseña: ");
	noecho();
	punt_ven=subwin(stdscr,3,40,8, 20);
	box (punt_ven, ACS_VLINE, ACS_HLINE);
	move (9, 33);
	mvwaddstr(punt_ven,1,1,"Contraseña: ");
	noecho();
	while((c=getch())!='\n' && i<80)
	{
		cadena[i++]=c;
		waddch(punt_ven,'*');
		wrefresh(punt_ven);
	}
	echo();
	cadena[i]='\0';
	wrefresh(punt_ven);
	mvwprintw(punt_ven,1,1,
	box (punt_ven, ACS_VLINE, ACS_HLINE);
	wrefresh (punt_ven);
	sleep (3);
	delwin (punt_ven);
	endwin();
	"El Password es %s\n", cadena);
}



