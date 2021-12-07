#include "collision.h"


void Collision::collide ( Object* obj1, Object* obj2 ) {

        double far = sqrt ( pow ( obj1-> getX () - obj2 -> getX (), 2 )
                        + pow ( obj1 -> getY () - obj2 -> getY (), 2 ) );

	double obj1ImpulseX = obj2 -> getImpulseX () - obj1 -> getImpulseX () * obj2 -> getDensity ();
	double obj1ImpulseY = obj2 -> getImpulseY () - obj1 -> getImpulseY () * obj2 -> getDensity ();

	double obj2ImpulseX = obj1 -> getImpulseX () - obj2 -> getImpulseX () * obj2 -> getDensity ();
        double obj2ImpulseY = obj1 -> getImpulseY () - obj2 -> getImpulseY () * obj2 -> getDensity ();

        if ( far <= 1 ) {
                obj1 -> addImpulse ( obj1ImpulseX, obj1ImpulseY );
		obj2 -> addImpulse ( obj2ImpulseX, obj2ImpulseY );
        }
}
