#include <iostream>

using namespace std;

const double PI = 3.1416;

class Shape
{
public:
	virtual void display() const = 0;
};

class Rectangle : public Shape
{
private:
	double a, b;
public:
	Rectangle(double h, double w)
	{
		a = h;
		b = w;
	}
	void display() const;
};

class Circle : public Shape
{
private:
	double r;
public:
	Circle(double rr)
	{
		r = rr;
	}
	void display() const;
};

void Rectangle::display() const
{
	cout << "a = " << a << ", b = " << b << ", area = " << a*b << endl << endl;
}

void Circle::display() const
{
	cout << "r = " << r << ", area = " << PI * r*r << endl << endl;
}


int main()
{
	Shape *p[2];
	p[0] = new Rectangle(3, 4);
	p[1] = new Circle(6);

	cout << "the Rectangle(3, 4):\n";
	p[0]->display();

	cout << "the Circle(6):\n";
	p[1]->display();

	return 0;
}