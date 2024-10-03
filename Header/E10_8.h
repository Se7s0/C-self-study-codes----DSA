#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
	explicit Complex(double = 0.0, double = 0.0); // constructor
	Complex operator+(const Complex&) const; // addition
	Complex operator-(const Complex&) const; // subtraction
	std::string toString() const = delete;

	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
	Complex operator*(const Complex&) const; // multiplication
	bool operator==(const Complex&) const; // equality
	
	bool operator!=(const Complex& rhs) const {
		
		return !(*this == rhs);
	
	}

private:
	double real; // real part
	double imaginary; // imaginary part
};

#endif