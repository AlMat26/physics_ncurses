#include <ncurses.h>
#include <string>

class conRender {
public:
	conRender ();	

	void printxy ( std::string str, int x, int y );

	void clearScreen ();
	void refreshScreen ();

	char getInput ();

	void setViewPosition ( double x, double y );

	~conRender ();
private:
	double m_posX;
	double m_posY;

	unsigned int windowWidth;
	unsigned int windowHeight;

	double windowAspect;

	const double charAspect = 0.89;
};
