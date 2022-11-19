#ifndef VEC2_H
#define VEC2_H

struct Vec2 {

	Vec2 () {
		x = 0;
		y = 0;
	}
	Vec2 ( double x, double y ) {
		this -> x = x;
		this -> y = y;
	}

	Vec2 operator + ( Vec2 argVec ) {
		return Vec2 ( this->x + argVec.x, this->y + argVec.y );
	}
	Vec2 operator + ( double arg ) {
		return Vec2 ( this ->x + arg, this->y + arg );
	}

	Vec2 operator - ( Vec2 argVec ) {
		return Vec2 ( this->x - argVec.x, this->y - argVec.y );
	}
	Vec2 operator - ( double arg ) {
                return Vec2 ( this->x - arg, this->y - arg );
	}

	Vec2 operator * ( Vec2 argVec ) {
		return Vec2 ( this->x * argVec.x, this->y * argVec.y );
	}
	Vec2 operator * ( double arg ) {
		return Vec2 ( this->x * arg, this->y * arg );
	}

	Vec2 operator / ( Vec2 argVec ) {
		return Vec2 ( this->x/argVec.x, this->y/argVec.y );
	}
	Vec2 operator / ( double arg ) {
		return Vec2 ( this->x/arg, this->y/arg );
	}


	Vec2 operator += ( Vec2 argVec ) {
		this -> x += argVec.x;
		this -> y += argVec.y;

		return *this;
	}
	Vec2 operator += ( double arg ) {
		this -> x += arg;
		this -> y += arg;

		return *this;
	}

	Vec2 operator -= ( Vec2 argVec ) {
		this -> x -= argVec.x;
		this -> y -= argVec.y;

		return *this;
	}
	Vec2 operator -= ( double arg ) {
                this -> x -= arg;
        	this -> y -= arg;

		return *this;
	}

	Vec2 operator *= ( Vec2 argVec ) {
		this -> x *= argVec.x;
		this -> y *= argVec.y;

		return *this;
	}
	Vec2 operator *= ( double arg ) {
		this -> x *= arg;
		this -> y *= arg;

		return *this;
	}

	Vec2 operator /= ( Vec2 argVec ) {
		this -> x /= argVec.x;
		this -> y /= argVec.y;

		return *this;
	}
	Vec2 operator /= ( double arg ) {
		this -> x /= arg;
		this -> y /= arg;

		return *this;
	}

	double x, y;

};

#endif
