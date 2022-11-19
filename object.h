#include <vector>
#include <ctime>
#include "vec2.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
	Object ( Vec2 pos, double mass, double density );

	void addImpulse ( Vec2 arg );
	void update ();
	void setBegin ();

	void invertVelocity ();

	Vec2 getPosition ();

	double getMass ();

	Vec2 getImpulse ();

	Vec2 getVelocity ();

	double getDensity ();

private:
	Vec2 m_position;
	double m_mass;
	double m_hight;
	
	Vec2 velocity; //[m/sec]

	Vec2 p; //impulse (x,y) [kg*m/sec]

	Vec2 m_force; //force;

	double m_density;

	double beginTime;
	
	const double g = 9.8;
};

#endif
