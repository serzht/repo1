#include <stdio.h>

int main(int argc, char **argv)
{
	char c;
	int openParentheses=0;
	while ((c=getchar())!='.')
	{
		switch (c)
		{
			case '(':
				openParentheses++; break;
			case ')':
				openParentheses--;
		}
		if (openParentheses < 0) break;
	}
	printf(openParentheses==0 ? "YES" : "NO");
	return 0;
}

