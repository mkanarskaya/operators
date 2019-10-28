
#include "pch.h"
#include "LorentzVector.h"

int main()
{
	LorentzVector a, b(2, 3, 4, 7);
	a.read();
	std::cout << "Vector a: ";
	a.print();
	std::cout << "\n";
	std::cout << "Vector b: ";
	b.print();
	std::cout << "\n";
	LorentzVector c(0,0,0,0);
	c += b;
	std::cout << "a+b: ";
	c.print();
	std::cout << "\n";
	c -= b;
	std::cout << "a-b: ";
	c.print();
	std::cout << "\n";
	c *= b;
	std::cout << "a*b: ";
	c.print();
	std::cout << "\n";
	c = c * 10;
	std::cout << "c*const: \n";
	c.print();
	std::cout << "\n";

	c = a.operator-(b);
	std::cout << "a-b: ";
	c.print();
	std::cout << "\n";
	c = a.operator+(b);
	std::cout << "a+b: ";
	c.print();
	std::cout << "\n";

	double scalar;
	std::cout << "Input scalar value:"; std::cin >> scalar;
	c = a.operator*(scalar);
	std::cout << "a*" << scalar << ": ";
	c.print();
	std::cout << "\n";
	double betta;
	std::cout << "Norma a: ";
	double norma;
	norma = a.norm();
	std::cout << norma << "\n";
	std::cout << "Input betta value:"; std::cin >> betta;
	c = c.trans(betta);
	if (abs(betta) >= 1) {
		std::cout << "betta is more 1, error \n";
		c.print();
	}
	else {
		std::cout << "new: \n";
		c.print();
	}
}
