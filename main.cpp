#include <iostream>
#include <string>
#include <ctime>

#include "conRender.h"
#include "object.h"
#include "collision.h"


int main () {
	bool run = true;
	conRender render;
	Object object1 ( 0, 0, 350 );
	Object object2 ( 6, 0, 350 );
	Collision collision;

	render.clearScreen ();
	render.refreshScreen ();

	object1.addImpulse ( 0.5, 0 );
	object2.addImpulse ( -0.5, 0 );

	object1.setBegin ();
	object2.setBegin ();

	while ( run ) {
		render.clearScreen ();

		render.printxy ( "@",
				object1.getX (), 
				object1.getY () );
		object1.update ();

		render.printxy ( "@",
                                object2.getX (),
                                object2.getY () );
                object2.update ();

		collision.collide ( &object1, &object2 );

		time_t begin = clock ();
		while ( clock () - begin <= 1000 ) {}
		//if ( render.getInput () == 'q' ) break;

		render.refreshScreen ();
	}

	return 0;
}
