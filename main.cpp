#include <iostream>
#include <string>
#include <ctime>
#include <thread>

#include "conRender.h"
#include "object.h"
#include "collision.h"
#include "vec2.h"


void getCharUpdate ( conRender* render, bool* run, char* input ) {

	while ( *run ) {

		*input = render -> getInput ();
	}
}

std::string getObjectProperties ( Object* obj ) {

	return "[x:" + std::to_string ( obj -> getPosition ().x ) + "; y:" +
                                std::to_string ( obj -> getPosition ().y ) + "]\n" +

				"[impulse (x;y) = "
                                + std::to_string ( obj -> getImpulse ().x ) + ";" +
                                std::to_string ( obj -> getImpulse ().y ) + "]";
}

int main () {

	bool run = true;
	char input;
	conRender render;
	Object object1 ( Vec2 ( 0, 0 ), 500, 0.8 );
	Object object2 ( Vec2 ( 6, 0 ), 200, 0.5 );
	Collision collision;

	std::thread getChar ( getCharUpdate, &render, &run, &input );

	render.clearScreen ();
	render.refreshScreen ();

	object1.setBegin ();
	object2.setBegin ();

	while ( run ) {
		render.clearScreen ();

		render.printxy ( getObjectProperties ( &object1 ), 
				object1.getPosition ().x, object1.getPosition ().y + 2 );
		render.printxy ( "@",
				object1.getPosition ().x, 
				object1.getPosition ().y );
		object1.update ();

		render.setViewPosition ( 0, 0 );

		render.printxy ( "#",
                                object2.getPosition ().x,
                                object2.getPosition ().y );
                object2.update ();

		collision.collide ( &object1, &object2 );

		time_t begin = clock ();
		while ( clock () - begin <= 1000 ) {}

		if ( input == 'q' ) {

			run = false;

		} else if ( input == 'w' ) {

			object1.addImpulse ( Vec2 ( 0, 0.5 ) );
			input = ' ';

		} else if ( input == 'a' ) {

			object1.addImpulse ( Vec2( -0.5, 0 ) );
			input = ' ';

		} if ( input == 's' ) {

			object1.addImpulse ( Vec2 ( 0, -0.5 ) );
			input = ' ';

		} else if ( input == 'd' ) {

			object1.addImpulse ( Vec2 ( 0.5, 0 ) );
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
