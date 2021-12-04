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

	mvprintw ( -y * charAspect * windowAspect + m_posY, 
			x * charAspect * windowAspect + m_posX, 
			str.c_str () );
}

char conRender::getInput () {
	return getchar();
}


void conRender::clearScreen () {

	clear ();

	getmaxyx ( stdscr, windowHeight, windowWidth );
	windowAspect = windowWidth / windowHeight;
}

void conRender::refreshScreen () {
	refresh ();
}


void conRender::setViewPosition ( double x, double y ) {
	
	m_posX = windowWidth/2 + x;
        m_posY = windowHeight/2 + y;
}


conRender::~conRender () {
	endwin ();
}
