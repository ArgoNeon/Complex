#include <cmath>

#include "complex.hpp"

complex_n::complex_n(): re(0), im(0){};

complex_n::complex_n(double a, double b): re(a), im(b){};

complex_n::complex_n(const complex_n & a): re(a.re), im(a.im){};

complex_n::~complex_n(){};

complex_n& complex_n::operator=(const complex_n &other) {
	re = other.re;
	im = other.im;	
	return *this;
}

bool complex_n::operator==(const complex_n &other) const {

	return (re == other.re) && (im == other.im);	
}

 bool complex_n::operator!=(const complex_n &other) const {

	return (re != other.re) || (im != other.im);
}

double complex_n::real() const {return re;}

double complex_n::imag() const {return im;}

double complex_n::arg() const {return atan(im / re);}

double complex_n::abs() const {return sqrt(re * re + im * im);}

double complex_n::sq_abs() const {return re * re + im * im;}

complex_n complex_n::conjugate() const {return {re, -im};}

complex_n& complex_n::operator+=(const complex_n &other) {
	re += other.re;
	im += other.im;
	return *this;
}

complex_n& complex_n::operator-=(const complex_n &other) {
	re -= other.re;
	im -= other.im;
	return *this;
}

complex_n& complex_n::operator*=(const complex_n &other) {
	double n_re = re; 
	re = re * other.re - im * other.im;  
	im = im * other.re + n_re * other.im;
	return *this;
}

complex_n& complex_n::operator/=(const complex_n &other) {
	double n_re = re;
	re = (re * other.re + im * other.im) / other.sq_abs();
	im = (im * other.re - n_re * other.im) / other.sq_abs();
	return *this;
}

complex_n complex_n::operator-() const{
	
	return {-re, -im};
}

complex_n complex_n::operator*(double other) const{
	
	return {re * other, im * other};
}

complex_n complex_n::operator+(const complex_n &other) const{

	return {re + other.re, im + other.im};
}

complex_n complex_n::operator-(const complex_n &other) const{
	
	return {re - other.re, im - other.im};
}

complex_n complex_n::operator*(const complex_n &other) const{
	
        return {re * other.re - im * other.im, im * other.re + re * other.im};
}

complex_n complex_n::operator/(const complex_n &other) const{
	
	return {(re * other.re + im * other.im) / other.sq_abs(), (im * other.re - re * other.im) / other.sq_abs()};
}

complex_n complex_n::operator^(const double degree) const{
	
	return {pow(this->abs(), degree) * cos(this->arg() * degree), pow(this->abs(), degree) * sin(this->arg() * degree)}; 
}

complex_n operator*(double other, const complex_n comp) {

	return {other * comp.re, other * comp.im};
}
