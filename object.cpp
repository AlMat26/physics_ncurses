#include <cmath>

#include "object.h"

Object::Object ( Vec2 pos, double mass, double density ) {

	m_position = pos;
	m_mass = mass;
	m_density = density;
}

void Object::addImpulse ( Vec2 arg ) {
	p += arg;
	setBegin ();
}


void Object::update () {

	double time = clock ();
	time /= CLOCKS_PER_SEC;
	double dTime = time - beginTime;

	velocity = p / m_mass /* dTime*/;

	m_position += velocity;

}

void Object::setBegin () {


	beginTime = clock ();
        beginTime /= CLOCKS_PER_SEC;
}


void Object::invertVelocity () {

	velocity *= -1;

	p *= -1;
}


Vec2 Object::getPosition () {
        return m_position;
}


double Object::getMass () {

	return m_mass;
}


Vec2 Object::getImpulse () {

	return p;
}


Vec2 Object::getVelocity () {

	return velocity;
}

double Object::getDensity () {

	return m_density;
}
