#ifndef VMOS_COMPLEX_COMPLEX_HPP
#define VMOS_COMPLEX_COMPLEX_HPP

struct complex_n {
	
	complex_n();
	complex_n(double, double);
	complex_n(const complex_n &);

	complex_n& operator=(const complex_n &);
	bool operator==(const complex_n &) const;
	bool operator!=(const complex_n &) const;

	complex_n& operator+=(const complex_n &);
	complex_n& operator-=(const complex_n &);
	complex_n& operator*=(const complex_n &);
	complex_n& operator/=(const complex_n &);
	
	complex_n operator-() const;
	complex_n operator*(double) const;
	complex_n operator+(const complex_n &) const;
	complex_n operator-(const complex_n &) const;
	complex_n operator*(const complex_n &) const;
	complex_n operator/(const complex_n &) const;
	
	complex_n operator^(const double) const;

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

complex_n operator*(double, const complex_n);

#endif
