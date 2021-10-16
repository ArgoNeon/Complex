#include "complex.hpp"
#include "test/test.hpp"

int main() {
	test(3, 4, 5, -8, 3, 5);
	test(4, 7, 0, -9, -15, 12);	
	test(5, -3, 0, 0, 47, 35);
	test(35, 56, -43, 32, 71, 30);
	return 0;
}
