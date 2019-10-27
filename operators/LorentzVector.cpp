#include "pch.h"
#include "LorentzVector.h"
#include <cmath>

LorentzVector:: LorentzVector() {
	x = y = z = t = 0;
}
LorentzVector:: LorentzVector(double x_, double y_, double z_, double t_) {
	this ->x = x_;
	this->y = y_;
	this->z = z_;
	this->t = t_;
	}
LorentzVector::LorentzVector(double, double, double, double)
{
}
double LorentzVector::get_x() const {
	return this->x;
}
double LorentzVector::get_y() const {
	return this->y;
}
double LorentzVector::get_z() const {
	return this->z;
}
double LorentzVector::get_t() const {
	return this->t;
}

void LorentzVector::set_lv(double x_, double y_, double z_, double t_) {
	this->x = x_;
	this->y = y_;
	this->z = z_;
	this->t = t_;
}

void LorentzVector::read() {
	std::cout << "Input x:"; std::cin >> x;
	std::cout << "Input y:"; std::cin >> y;
	std::cout << "Input z:"; std::cin >> z;
	std::cout << "Input t:"; std::cin >> t;

}

void LorentzVector::print() {
	std::cout << "Lorentz Vector: x = " << this->x << ", y = " << this->y << ", z = " << this->z << ", t = " << this->t;
}


LorentzVector LorentzVector::trans(double betta) {
	LorentzVector buv((x - betta*t)/sqrt(1-betta*betta),y,z,(t - betta*x)/sqrt(1-betta*betta));
	return buv;
}
LorentzVector LorentzVector::operator+(const LorentzVector & other) {
	LorentzVector result(x + other.x, y + other.y, z + other.z, t + other.t);
	return result;
}

void LorentzVector::operator +=(const LorentzVector & other) {
	x += other.x;
	y += other.y;
	z += other.z;
	t += other.t;
}
	
LorentzVector LorentzVector:: operator-(const LorentzVector & other) {
	LorentzVector result(x - other.x, y - other.y, z - other.z, t - other.t);
	return result;
}
	
void LorentzVector::operator -=(const LorentzVector & other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	t -= other.t;
}

LorentzVector LorentzVector::operator* (const LorentzVector & other) {
	LorentzVector result(this->x * other.x, this->y * other.y, this->z * other.z, this->t * -other.t);
	return result;
}

void LorentzVector::operator*= (const LorentzVector & other) {
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	this->t *= -other.t;
}

LorentzVector LorentzVector::operator* (double scalar) {
	LorentzVector result(this->x * scalar, this->y * scalar, this->z * scalar, this->t * scalar);
	return result;
}

LorentzVector operator*(double scalar, const LorentzVector & This) {
	LorentzVector result(This.x * scalar, This.y * scalar, This.z * scalar, This.t * scalar);
	return result;
};

LorentzVector LorentzVector::operator -() {
	this->x = -x;
	this->y = -y;
	this->z = -z;
	this->t = -t;
	return *this;
}

std::istream& operator >> (std::istream& in,LorentzVector& other) {
	in >> other.x;
	in >> other.y;
	in >> other.z;
	in >> other.t;
	return in;
}

std::ostream& operator << (std::ostream& out, const LorentzVector & lv) {
	out << "x = " << lv.x << ", y =  " << lv.y << ", z = " << lv.z << ", t = " << lv.t;
	return out;
}


