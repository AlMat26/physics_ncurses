#include "conRender.h"

conRender::conRender () {
	initscr ();
	start_color ();
	curs_set ( 0 );
	noecho ();
	keypad ( stdscr, TRUE );

	init_pair ( 1, COLOR_WHITE, COLOR_BLACK );
	attrset ( COLOR_PAIR ( 1 ) );
}

void conRender::printxy ( std::string str, int x, int y ) {
	mvprintw ( -y * charAspect, 
			x * charAspect, 
			str.c_str () );
}

char conRender::getInput () {
	return getchar();
}


void conRender::clearScreen () {
	clear ();
}

void conRender::refreshScreen () {
	refresh ();
}


conRender::~conRender () {
	endwin ();
}
