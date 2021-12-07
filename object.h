#include <vector>
#include <ctime>

#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
	Object ( double x, double y, double mass, double density );

	void addImpulse ( double x, double y );
	void update ();
	void setBegin ();

	void invertVelocity ();

	double getX ();
	double getY ();

	double getMass ();

	double getImpulseX ();
	double getImpulseY ();

	double getVelocityX ();
	double getVelocityY ();

	double getDensity ();

private:
	double m_x, m_y;
	double m_mass;
	double m_hight;
	
	double velocityX = 0; //[m/sec]
	double velocityY = 0;

	double pX = 0; //impulse (x,y)
	double pY = 0; //[kg*m/sec]

	double FX; //force
	double FY;

	double m_density;

	double beginTime;
	
	const double g = 9.8;
};

#endif
