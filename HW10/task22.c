#include <stdio.h>

#define SIZE 21

int main(int argc, char **argv)
{
	char s[SIZE], *sp=s, current_char=0;
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%s", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f) {
			if (*sp) {
				while (*++sp) {
					switch (*sp) {
						case'a':case'e':case'h':case'i':case'o':case'u':case'w':case'y':
							*sp = ' '; break;
						case'b':case'f':case'p':case'v':
							*sp = '1'; break;
						case'c':case'g':case'j':case'k':case'q':case's':case'x':case'z':
							*sp = '2'; break;
						case'd':case't':
							*sp = '3'; break;
						case'l':
							*sp = '4'; break;
						case'm':case'n':
							*sp = '5'; break;
						case'r':
							*sp = '6'; break;
						default:
							*sp = ' ';					
					}
					if (*sp != ' ') {
						if (*sp == current_char)
							*sp = ' ';
						else
							current_char = *sp;
					}
				}
				sp = s + 1;
				while (*sp) {
					if (*sp == ' ') {
						*sp = *(sp + 1);
						*(sp + 1) = ' ';
						if (*sp == '\0') sp = s;
					}
					sp++;
				}
				if (sp - s < 4)
					for (;sp < s+4; sp++) {
						*(sp+1) = *sp;
						*sp = '0';
					}
				else
					*(s + 4) = '\0';
			}
			fprintf(f, "%s\n", s);
			fclose(f);
		}
	}
	return 0;
}

