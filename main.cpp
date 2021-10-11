#include <complex>
#include <iostream>

#include "complex.hpp"

#define EPS 0.00001

void check(double comp_x, double comp_y, double x, double y) {
	if ((abs(comp_x - x) < EPS)&&(abs(comp_y - y) < EPS)) 
		std::cout<<"Accepted"<<std::endl;
	else
		std::cout<<"Failed"<<std::endl;
}

void check_add1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
 	complex_n a = {x1, y1}, b = {x2, y2};
 	comp_a += comp_b;
	a += b;
	std::cout<<"+=: ";
	check(real(comp_a), imag(comp_a), a.re, a.im);
}

void check_dif1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
	complex_n a = {x1, y1}, b = {x2, y2};
	comp_a -= comp_b;
	a -= b;
	std::cout<<"-=: ";
	check(real(comp_a), imag(comp_a), a.re, a.im);
}

void check_mult1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
	complex_n a = {x1, y1}, b = {x2, y2};
	comp_a *= comp_b;
	a *= b;
	std::cout<<"*=: ";
	check(real(comp_a), imag(comp_a), a.re, a.im);
}


void check_div1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
	complex_n a = {x1, y1}, b = {x2, y2};
	comp_a /= comp_b;
	a /= b;
	std::cout<<"/=: ";
	check(real(comp_a), imag(comp_a), a.re, a.im);
}

void check_dif_un(double x, double y) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = -comp_a;
	res = -a;
	std::cout<<"-(unary):  ";
	check(real(comp_res), imag(comp_res), res.re, res.im);
}

void check_add2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
	complex_n a = {x1, y1}, b = {x2, y2}, res;
	comp_res = comp_a + comp_b;
	res = a + b;
	std::cout<<"+:  ";
	check(real(comp_res), imag(comp_res), res.re, res.im);
}

void check_dif2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
 	complex_n a = {x1, y1}, b = {x2, y2}, res;
 	comp_res = comp_a - comp_b;
	res = a - b;
	std::cout<<"-:  ";
 	check(real(comp_res), imag(comp_res), res.re, res.im);
}

void check_mult2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
	complex_n a = {x1, y1}, b = {x2, y2}, res;
 	comp_res = comp_a * comp_b;
	res = a * b;
	std::cout<<"*:  ";
 	check(real(comp_res), imag(comp_res), res.re, res.im);
}


void check_div2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
 	complex_n a = {x1, y1}, b = {x2, y2}, res;
 	comp_res = comp_a / comp_b;
	res = a / b;
	std::cout<<"/:  ";
 	check(real(comp_res), imag(comp_res), res.re, res.im);
}

void check_conj(double x, double y) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = conj(comp_a);
	res = a.conjugate();
	std::cout<<"conjugate: ";
	check(real(comp_res), imag(comp_res), res.re, res.im);
}

void check_multd(double x, double y, double other) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = comp_a * other;
	res = a * other;
	std::cout<<"complex * double: ";
	check(real(comp_res), imag(comp_res), res.re, res.im);
}

void check_dmult(double x, double y, double other) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = other * comp_a;
	res = other * a;
	std::cout<<"double * complex: ";
	check(real(comp_res), imag(comp_res), res.re, res.im);
}

void check_deg(double x, double y, double degree) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = pow(comp_a, degree);
	res = a^degree;
	std::cout<<"^:  ";
	check(real(comp_res), imag(comp_res), res.re, res.im);
}


void test(double x1, double y1, double x2, double y2, double other, double degree) {
	std::cout<<"TEST"<<std::endl;
	check_add1(x1, y1, x2, y2);
	check_dif1(x1, y1, x2, y2);
	check_div1(x1, y1, x2, y2);
	check_mult1(x1, y1, x2, y2);
	
	check_add2(x1, y1, x2, y2);
	check_dif2(x1, y1, x2, y2);
	check_div2(x1, y1, x2, y2);
	check_mult2(x1, y1, x2, y2);
	
	check_dif_un(x1, y1);
	check_conj(x1, y1);

	check_dmult(x1, y1, other);
	check_multd(x1, y1, other);
	check_deg(x1, y1, degree);
	std::cout<<std::endl;
}

int main() {
	
	test(3, 4, 5, -8, 3, 5);
	test(4, 7, 0, -9, -15, 12);	
	test(5, -3, 0, 0, 47, 35);
	test(35, 56, -43, 32, 71, 30);
	return 0;
}
