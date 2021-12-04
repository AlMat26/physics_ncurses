#include "collision.h"


void Collision::collide ( Object* obj1, Object* obj2 ) {

        double far = sqrt ( pow ( obj1-> getX () - obj2 -> getX (), 2 )
                        + pow ( obj1 -> getY () - obj2 -> getY (), 2 ) );

	double obj1ImpulseX = obj2 -> getImpulseX () - obj1 -> getImpulseX ();
	double obj1ImpulseY = obj2 -> getImpulseY () - obj1 -> getImpulseY ();

	double obj2ImpulseX = obj1 -> getImpulseX () - obj2 -> getImpulseX ();
        double obj2ImpulseY = obj1 -> getImpulseY () - obj2 -> getImpulseY ();

        if ( far <= 0.7 ) {
                obj1 -> addImpulse ( obj1ImpulseX, obj1ImpulseY );
		obj2 -> addImpulse ( obj2ImpulseX, obj2ImpulseY );
        }
}
