#ifndef VMOS_COMPLEX_TEST_HPP
#define VMOS_COMPLEX_TEST_HPP

bool check(double comp_x, double comp_y, double x, double y);
bool check_double(double x, double y);

void check_add1(double x1, double y1, double x2, double y2);
void check_dif1(double x1, double y1, double x2, double y2);
void check_mult1(double x1, double y1, double x2, double y2);
void check_div1(double x1, double y1, double x2, double y2);

void check_dif_un(double x, double y);
void check_add2(double x1, double y1, double x2, double y2);
void check_dif2(double x1, double y1, double x2, double y2);
void check_mult2(double x1, double y1, double x2, double y2);
void check_div2(double x1, double y1, double x2, double y2);

void check_multd(double x, double y, double other);
void check_divd(double x, double y, double other);
void check_dmult(double x, double y, double other); 
void check_ddiv(double x, double y, double other);

void check_ln(double x, double y); 
void check_pow(double x, double y, double degree);
void check_comp_pow(double x1, double y1, double x2, double y2);
void check_arg(double x, double y);	
void check_abs(double x, double y);

void test(double x1, double y1, double x2, double y2, double other, double degree);
void unit_test();

#endif  //#define VMOS_COMPLEX_TEST_HPP
