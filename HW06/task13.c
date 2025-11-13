#include <stdio.h>

float cosinus (float x);
double power(float n, int p);
long long factorial (int n);
float ABS(float n);

int main(int argc, char **argv)
{
	float x;
	scanf("%f", &x);
	printf("%.3f", cosinus(x));
	return 0;
}

float cosinus (float x)
{
	float t, sum=0, arg=x*3.1416/180;
	for (int i=0;;i++)
	{
		t = (float)power(-1, i)*power(arg, 2*i)/factorial(2*i);
		if (ABS(t) < 0.001)
			break;
		sum += t;
	}
	return sum;
}

double power(float n, int p)
{
	double result=1.0;
	if (p > 0) 
		for (int i=1; i<=p; i++)
			result*=n;
	return result;
}

long long factorial (int n)
{
	long long result=1;
	for (int i=1; i<=n; i++)
		result*=i;
	return result;
}

float ABS(float n)
{
	return n < 0 ? -n : n;
}
