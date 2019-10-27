
#include "pch.h"
#include "LorentzVector.h"

int main()
{
	LorentzVector a, b(2, 3, 4, 7);
	a.read();
	std::cout << "Vector a: \n";
	a.print();
	std::cout << "Vector b: \n";
	b.print();
	LorentzVector c(0,0,0,0);
	c += b;
	std::cout << "a+b: \n";
	c.print();

	c -= b;
	std::cout << "a-b: \n";
	c.print();
	c *= b;
	std::cout << "a*b: \n";
	c.print();
	c = c * 10;
	std::cout << "c*const: \n";
	c.print();

	c = a.operator-(b);
	std::cout << "a-b: \n";
	c.print();
	c = a.operator+(b);
	std::cout << "a+b: \n";
	c.print();

	double scalar;
	std::cout << "Input scalar value:"; std::cin >> scalar;
	c = a.operator*(scalar);
	std::cout << "a*" << scalar << ": \n";
	c.print();
	double betta;
	std::cout << "Input betta value:"; std::cin >> betta;
	c = c.trans(betta);
	std::cout << "new: \n";
	c.print();

}
