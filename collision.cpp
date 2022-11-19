#include "collision.h"
#include "vec2.h"


void Collision::collide ( Object* obj1, Object* obj2 ) {

        double far = sqrt ( pow ( obj1-> getPosition ().x - obj2 -> getPosition ().x, 2 )
                        + pow ( obj1 -> getPosition ().y - obj2 -> getPosition ().y, 2 ) );

	Vec2 obj1Impulse = obj2 -> getImpulse () - obj1 -> getImpulse () * obj2 -> getDensity ();

	Vec2 obj2Impulse = obj1 -> getImpulse () - obj2 -> getImpulse () * obj2 -> getDensity ();

        if ( far <= 1 ) {
                obj1 -> addImpulse ( obj1Impulse );
		obj2 -> addImpulse ( obj2Impulse );
        }
}
