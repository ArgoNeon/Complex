#include <cmath>
#include <cstdio>

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

void complex_n::print() const {
	if (im >= 0) { 
		printf("%lf+%lfi\n", re, im);
	} else {
		printf("%lf%lfi\n", re, im);
	}
}

double complex_n::real() const {return re;}

double complex_n::imag() const {return im;}

double complex_n::arg() const {return atan(im / re);}

double complex_n::abs() const {return sqrt(re * re + im * im);}

double complex_n::sq_abs() const {return re * re + im * im;}

complex_n complex_n::conjugate() const {return {re, -im};}

complex_n complex_n::ln() const {
	
	return {log(abs()), arg()};

}

complex_n complex_n::power(double degree) const{	
	double arg_this = this->arg() * degree;
	double pow_this = pow(this->abs(), degree);
	return {pow_this * cos(arg_this), pow_this * sin(arg_this)};
}

complex_n complex_n::power(const complex_n degree) const{
	complex_n deg;
	double ex;
	deg = degree * ln();
	ex = pow(M_E, deg.re);
	return {ex * cos(deg.im), ex * sin(deg.im)};
}

complex_n& complex_n::operator+=(const complex_n &other) {
	re += other.re;
	im += other.im;
	return *this;
}

complex_n& complex_n::operator+=(double other) {
	re += other;
	return *this;
}

complex_n& complex_n::operator-=(const complex_n &other) {
	re -= other.re;
	im -= other.im;
	return *this;
}

complex_n& complex_n::operator-=(double other) {
	re -= other;
	return *this;
}

complex_n& complex_n::operator*=(const complex_n &other) {
	double n_re = re; 
	re = re * other.re - im * other.im;  
	im = im * other.re + n_re * other.im;
	return *this;
}

complex_n& complex_n::operator*=(double other) {
	re = re * other;
	im = im * other;
	return *this;
}

complex_n& complex_n::operator/=(const complex_n &other) {
	double n_re = re;
	re = (re * other.re + im * other.im) / other.sq_abs();
	im = (im * other.re - n_re * other.im) / other.sq_abs();
	return *this;
}

complex_n& complex_n::operator/=(double other) {
	re = re / other;
	im = im / other;
	return *this;
}

complex_n complex_n::operator-() const{
	
	return {-re, -im};
}

complex_n complex_n::operator+(double other) const{

	return {re + other, im};
}

complex_n complex_n::operator-(double other) const{
	
	return {re - other, im};
}

complex_n complex_n::operator*(double other) const{
	
	return {re * other, im * other};
}

complex_n complex_n::operator/(double other) const{

	return {re / other, im / other};
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
	double sqabs = other.sq_abs();
	return {(re * other.re + im * other.im) / sqabs, (im * other.re - re * other.im) / sqabs};
}

complex_n operator+(double other, const complex_n comp) {

	return {other + comp.re, comp.im};
}

complex_n operator-(double other, const complex_n comp) {

	return {other - comp.re, comp.im};
}

complex_n operator*(double other, const complex_n comp) {

	return {other * comp.re, other * comp.im};
}

complex_n operator/(double other, const complex_n comp) {
	double sqabs = comp.sq_abs();
	return {(other * comp.re) / sqabs, (- other * comp.im) / sqabs};
}
