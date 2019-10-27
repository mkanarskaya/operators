#pragma once
#include <iostream>

class LorentzVector {
private: 
	double x, y, z, t;
public:
	LorentzVector();
	LorentzVector(double, double, double, double);
	double get_x() const;
	double get_y() const;
	double get_z() const;
	double get_t() const;

	void set_lv(double, double, double, double);

	void read();
	void print();
	LorentzVector trans(double);
	LorentzVector operator+(const LorentzVector &);
	void operator +=(const LorentzVector &);
	LorentzVector operator-(const LorentzVector &);
	void operator -=(const LorentzVector &);

	LorentzVector operator*(const LorentzVector &);

	LorentzVector operator*(double);
	friend LorentzVector operator*(double, const LorentzVector &);

	void operator*=(const LorentzVector &);
	
	LorentzVector operator -();
	friend std::istream& operator << (std::istream& in,LorentzVector& );

	friend std::ostream& operator << (std::ostream& in, const LorentzVector &);
};
