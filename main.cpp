#include <iostream>
#include <string>
#include <ctime>
#include <thread>

#include "conRender.h"
#include "object.h"
#include "collision.h"


void getCharUpdate ( conRender* render, bool* run, char* input ) {

	while ( *run ) {

		*input = render -> getInput ();
	}
}

std::string getObjectProperties ( Object* obj ) {

	return "[x:" + std::to_string ( obj -> getX () ) + "; y:" +
                                std::to_string ( obj -> getY () ) + "]\n" +

				"[impulse (x;y) = "
                                + std::to_string ( obj -> getImpulseX () ) + ";" +
                                std::to_string ( obj -> getImpulseY () ) + "]";
}

int main () {

	bool run = true;
	char input;
	conRender render;
	Object object1 ( 0, 0, 500, 0.8 );
	Object object2 ( 6, 0, 200, 0.5 );
	Collision collision;

	std::thread getChar ( getCharUpdate, &render, &run, &input );

	render.clearScreen ();
	render.refreshScreen ();

	object1.setBegin ();
	object2.setBegin ();

	while ( run ) {
		render.clearScreen ();

		render.printxy ( getObjectProperties ( &object1 ), 
				object1.getX (), object1.getY () + 2 );
		render.printxy ( "@",
				object1.getX (), 
				object1.getY () );
		object1.update ();

		render.setViewPosition ( 0, 0 );

		render.printxy ( "#",
                                object2.getX (),
                                object2.getY () );
                object2.update ();

		collision.collide ( &object1, &object2 );

		time_t begin = clock ();
		while ( clock () - begin <= 1000 ) {}

		if ( input == 'q' ) {

			run = false;

		} else if ( input == 'w' ) {

			object1.addImpulse ( 0, 0.5 );
			input = ' ';

		} else if ( input == 'a' ) {

			object1.addImpulse ( -0.5, 0 );
			input = ' ';

		} if ( input == 's' ) {

			object1.addImpulse ( 0, -0.5 );
			input = ' ';

		} else if ( input == 'd' ) {

			object1.addImpulse ( 0.5, 0 );
			input = ' ';

		} else if ( input == 'r' ) {

			object1.invertVelocity ();
			input = ' ';
		}

		render.refreshScreen ();
	}

	getChar.join ();

	return 0;
}
