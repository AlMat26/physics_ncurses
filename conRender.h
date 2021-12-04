#include <ncurses.h>
#include <string>

class conRender {
public:
	conRender ();	

	void printxy ( std::string str, int x, int y );

	void clearScreen ();
	void refreshScreen ();

	char getInput ();

	~conRender ();
private:
	double m_posX;
	double m_posY;
	const double charAspect = 0.89;
};
