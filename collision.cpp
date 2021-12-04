#include "collision.h"


void Collision::collide ( Object* obj1, Object* obj2 ) {

        double far = sqrt ( pow ( obj1-> getX () - obj2 -> getX (), 2 )
                        + pow ( obj1 -> getY () - obj2 -> getY (), 2 ) );

        if ( far <= 0.7 ) {
                obj1 -> invertVelocity ();
		obj2 -> invertVelocity ();
        }
}
