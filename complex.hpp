#ifndef VMOS_COMPLEX_COMPLEX_HPP
#define VMOS_COMPLEX_COMPLEX_HPP

struct complex_n {
	
	complex_n();
	complex_n(double a, double b);
	complex_n(const complex_n & a);

	complex_n& operator=(const complex_n & other);
	bool operator==(const complex_n & other) const;
	bool operator!=(const complex_n & other) const;

	complex_n& operator+=(const complex_n & other);
	complex_n& operator-=(const complex_n & other);
	complex_n& operator*=(const complex_n & other);
	complex_n& operator/=(const complex_n & other);
	
	complex_n operator-() const;
	complex_n operator*(double other) const;
	complex_n operator+(const complex_n & other) const;
	complex_n operator-(const complex_n & other) const;
	complex_n operator*(const complex_n & other) const;
	complex_n operator/(const complex_n & other) const;
	
	complex_n operator^(const double degree) const;

	complex_n conjugate() const;

	double real() const;
	double imag() const;
	double arg() const;
	double abs() const;
	double sq_abs() const;
	
	~complex_n();

	double re;
	double im;
};

complex_n operator*(double other, const complex_n comp);

#endif	//#define VMOS_COMPLEX_COMPLEX_HPP
