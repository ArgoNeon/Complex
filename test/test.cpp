#include <complex>
#include <iostream>

#include "../complex.hpp"
#include "test.hpp"

#define EPS 0.00001

bool check(double comp_x, double comp_y, double x, double y) {
	return ((abs(comp_x - x) < EPS)&&(abs(comp_y - y) < EPS));
}

bool check_double(double x, double y) {
	return ((abs(x - y) < EPS));
}

void check_add1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
 	complex_n a = {x1, y1}, b = {x2, y2};
 	comp_a += comp_b;
	a += b;
	if (!check(real(comp_a), imag(comp_a), a.re, a.im))
		std::cout<<"+=: Failed\n";
}

void check_dif1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
	complex_n a = {x1, y1}, b = {x2, y2};
	comp_a -= comp_b;
	a -= b;
	if (!check(real(comp_a), imag(comp_a), a.re, a.im))
		std::cout<<"-=: Failed\n";
}

void check_mult1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
	complex_n a = {x1, y1}, b = {x2, y2};
	comp_a *= comp_b;
	a *= b;
	if (!check(real(comp_a), imag(comp_a), a.re, a.im))
		std::cout<<"*=: Failed\n";
}


void check_div1(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2};
	complex_n a = {x1, y1}, b = {x2, y2};
	comp_a /= comp_b;
	a /= b;
	if (!check(real(comp_a), imag(comp_a), a.re, a.im))
		std::cout<<"/=: Failed\n";
}

void check_dif_un(double x, double y) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = -comp_a;
	res = -a;
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"-(unary): Failed\n";
}

void check_add2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
	complex_n a = {x1, y1}, b = {x2, y2}, res;
	comp_res = comp_a + comp_b;
	res = a + b;
	if(!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"+: Failed\n";
}

void check_dif2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
 	complex_n a = {x1, y1}, b = {x2, y2}, res;
 	comp_res = comp_a - comp_b;
	res = a - b;
 	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"-: Failed\n";
}

void check_mult2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
	complex_n a = {x1, y1}, b = {x2, y2}, res;
 	comp_res = comp_a * comp_b;
	res = a * b;
 	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		 std::cout<<"*: Failed\n";
}


void check_div2(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
 	complex_n a = {x1, y1}, b = {x2, y2}, res;
 	comp_res = comp_a / comp_b;
	res = a / b;
 	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"/: Failed\n";
}

void check_conj(double x, double y) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = conj(comp_a);
	res = a.conjugate();
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"conj: Failed\n";
}

void check_multd(double x, double y, double other) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = comp_a * other;
	res = a * other;
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"complex * double: Failed\n";
}

void check_divd(double x, double y, double other) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = comp_a / other;
	res = a / other;
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"complex / double: Failed\n";
}

void check_dmult(double x, double y, double other) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = other * comp_a;
	res = other * a;
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"double * complex: Failed\n";
}

void check_ddiv(double x, double y, double other) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = other / comp_a;
	res = other / a;
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"double / complex: Failed\n";
}

void check_ln(double x, double y) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = log(comp_a);
	res = a.ln();
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"ln: Failed\n";
}

void check_pow(double x, double y, double degree) {
	std::complex<double> comp_a = {x, y}, comp_res;
	complex_n a = {x, y}, res;
	comp_res = pow(comp_a, degree);
	res = a.power(degree);
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"pow: Failed\n";
}

void check_comp_pow(double x1, double y1, double x2, double y2) {
	std::complex<double> comp_a = {x1, y1}, comp_b = {x2, y2}, comp_res;
	complex_n a = {x1, y1}, b = {x2, y2}, res;
	comp_res = pow(comp_a, comp_b);
	res = a.power(b);
	if (!check(real(comp_res), imag(comp_res), res.re, res.im))
		std::cout<<"comp_pow: Failed\n";
}

void check_arg(double x, double y) {
	std::complex<double> comp_a = {x, y};
	double comp_res, res;
	complex_n a = {x, y};
	comp_res = arg(comp_a);
	res = a.arg();
	if (!check_double(comp_res, res))
		std::cout<<"arg: Failed\n";
}
	
void check_abs(double x, double y) {
	std::complex<double> comp_a = {x, y};
	double comp_res, res;
	complex_n a = {x, y};
	comp_res = abs(comp_a);
	res = a.abs();
	if (!check_double(comp_res, res))
		 std::cout<<"abs: Failed\n";
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
	check_arg(x1, y1);
	check_abs(x1, y1);
	check_conj(x1, y1);
	check_ln(x1, y1);

	check_dmult(x1, y1, other);
	check_multd(x1, y1, other);
	check_ddiv(x1, y1, other);
	check_divd(x1, y1, other);

	check_pow(x1, y1, degree);
	check_comp_pow(x1, y1, x2, y2);
}

void unit_test() {
	test(3, 4, 5, -8, 3, 5);
	test(4, 7, 0, -9, -15, 12);
	test(5, -3, 0, 0, 47, 35);
	test(35, 56, -43, 32, 71, 30);
}
