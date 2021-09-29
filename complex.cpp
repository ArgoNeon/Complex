#include <complex>
#include "complex.hpp"

#define TEST1 check(res.re,real(comp_res), res.im, imag(comp_res))
#define INIT aa = a;\
comp_aa = comp_a;
#define TEST2 check(aa.re,real(comp_aa), aa.im, imag(comp_aa))

void check(double r1, double r2, double i1, double i2) {
	if ((abs(r1 - r2) < 0.00001)&&(abs(i1 - i2) < 0.00001)) 
		printf("Accepted\n");
	else
		printf("Failed\n");
}

int main() {
	std::complex<double> comp_a = {3, 4}, comp_b = {5, -8}, comp_aa, comp_res;
	complex_n a = {3, 4}, b = {5, -8}, aa, res;
	
	res = -a;
	comp_res = -comp_a;
	TEST1;
	res = a + b;
	comp_res = comp_a + comp_b;
	TEST1;
	res = a - b;
	comp_res = comp_a - comp_b;
	TEST1;
	res = a * b;
	comp_res = comp_a * comp_b;	
	TEST1;
	res = a / b;
	comp_res = comp_a / comp_b;
	TEST1;
	INIT;
	aa += b;
	comp_aa += comp_b;
	TEST2;
	INIT;
	aa -= b;
	comp_aa -= comp_b;
	TEST2;
	INIT;
	aa *= b;
	comp_aa *= comp_b;
	TEST2;
	INIT;
	aa /= b;
	comp_aa /= comp_b;
	TEST2;
	res = 3 * a;
	comp_res = 3.0 * comp_a;
	TEST1;
	res = a * 3;
	comp_res = comp_a * 3.0;
	TEST1;

	return 0;
}
