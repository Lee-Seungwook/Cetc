#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX_DEGREE 10

typedef struct
{
	int degree;
	int coef[MAX_DEGREE];
} poly;

poly poly_add1(poly A, poly B)
{
	int i;
	poly C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree, degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	while (C.coef[0] == 0)
	{
		for (i = 0; i < C.degree; i++)
		{
			C.coef[i] = C.coef[i + 1];
		}
		C.degree--;

	}
	return C;
}
void print_poly1(poly p)
{

	int i;
	int exponent = p.degree;

	for (i = 0; i <= p.degree; i++)
	{
		if (p.coef[i] != 0)
			printf("%dx^%d ", p.coef[i], exponent);
		exponent--;
	}printf("\n");
}
int main(void) {
	poly a = { 3,{ 4, 0, 1, 7} };
	poly b = { 2, {2, 1,0} };
	poly c;
	c = poly_add1(a, b);
	printf("a = "); print_poly1(a);
	printf("b = "); print_poly1(b);
	printf("a + b = c = "); print_poly1(c);
	printf("CÀÇ Â÷¼ö:%d\n", c.degree);
}




