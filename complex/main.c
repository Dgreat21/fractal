#include "complex.h"
#include <stdio.h>

void test(float x, float y)
{
	t_complex a, b;

	a = set_complex(x, y);

	b = cmplx_pow(a, 3);
	printf("%5.2f %5.2f\t", a.re, a.im);
	printf("angle: %5.2f\n", cmplx_arg(a) * 180 / M_PI);
	printf("%5.2f %5.2f\t", b.re, b.im);
	printf("abs: %f\n\n", cmplx_abs_num(a));
}

int main()
{
	test(1,1);
	test(1,0);
	test(0,1);
	test(2,2);
	test(2,-2);
	test(-2,2);
	test(-2,-2);
	return (0);
}
