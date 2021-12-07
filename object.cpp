#include <cmath>

#include "object.h"

Object::Object ( double x, double y, double mass, double density ) {

	m_x = x;
	m_y = y;
	m_mass = mass;
	pX = 0;
	pY = 0;
	m_density = density;
}

void Object::addImpulse ( double x, double y ) {
	pX += x;
	pY += y;
	setBegin ();
}


void Object::update () {

	double time = clock ();
	time /= CLOCKS_PER_SEC;
	double dTime = time - beginTime;

	velocityX = pX / m_mass /* dTime*/;

	velocityY = pY / m_mass /* dTime*/;

	m_x += velocityX;
	m_y += velocityY;

}

void Object::setBegin () {


	beginTime = clock ();
        beginTime /= CLOCKS_PER_SEC;
}


void Object::invertVelocity () {

	velocityX *= -1;
	velocityY *= -1;

	pX *= -1;
	pY *= -1;
}


double Object::getX () {
        return m_x;
}

double Object::getY () {
        return m_y;
}


double Object::getMass () {

	return m_mass;
}


double Object::getImpulseX () {

	return pX;
}

double Object::getImpulseY () {

	return pY;
}


double Object::getVelocityX () {

	return velocityX;
}

double Object::getVelocityY () {

	return velocityY;
}

double Object::getDensity () {

	return m_density;
}
