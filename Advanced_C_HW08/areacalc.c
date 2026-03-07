#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef double (*function)(double);

struct data_{																//структура данных (для удобства работы)
	double segment [3][2];													//отрезки оси абсцисс на которых производим поиск корней
	function func_pair[3][2];												//пары указателей на функции (f1,f3), (f2,f3) и (f1,f2)
	double root[3];															//найденные корни пар функций
	int stepcount[3];														//количество итераций, затраченных на поиск корней
	double area[3];															//найденные площади фигур, ограниченных соответствующей функцией и осью абсцисс, а также корнями, принадлежащими данной функции
	double eps1;															//наибольшая допустимая погрешность (желаемая точность) искомых корней
	double eps2;															//наибольшая допустимая погрешность (желаемая точность) искомых площадей
	int progress_root;														//текущий прогресс поиска корней
	int progress_area;														//текущий прогресс поиска площадей фигур
} data;

int signF(function f, function g, double x);
double root(function f, function g, double a, double b, double eps1);
double integral(function f, double a, double b, double eps2);
double f1(double x);
double f2(double x);
double f3(double x);
double test_f1(double x);
double test_f2(double x);
double test_f3(double x);

int main(int argc, char **argv)
{
	int help=0, roots = 0, iterations = 0, test = 0, c;
	data = (struct data_){													//инициализация структуры данных
		.segment = {{0.5, 1}, {3, 3.5}, {3.5, 4}},
		.func_pair = {{f1, f3}, {f2, f3}, {f1, f2}},
		.root = {0},
		.stepcount = {0},
		.area = {0},
		.eps1 = 0.00001,
		.eps2 = 0.00001,
		.progress_root = 0,
		.progress_area = 0 };
	opterr = 0;
	while ((c = getopt(argc, argv, "hrit")) != -1) {						//разбор параметров командной строки библиотечной функцией getopt
		switch (c) {
			case 'h': help = 1; break;
			case 'r': roots = 1; break;
			case 'i': iterations = 1; break;
			case 't': test = 1; break;
		}
	}
	if (help) {																//если задана опция -h программа выведет справку и завершит работу
		printf("This application calculates the area of a figure bounded by the graphs of functions:\n\n");
		printf("f1 = 0.6x + 3\n");
		printf("f2 = (x - 2)(x - 2)(x - 2) - 1\n");
		printf("f3 = 3/x\n\n");
		printf("Please enter key:\n\n");
		printf("-r\tPrints the x-coordinates of the intersection points of pairs of functions.\n");
		printf("-i\tPrints the number of iterations required to find the roots of pairs of functions.\n");
		printf("-t\tTesting the functions for finding roots (root) and calculating definite integrals (integral).\n");
	}
	else if (test) {														//с опцией -t программа выполнит простой тест функций root и integral и завершит работу
		printf("Testing the root search function 'root'::\n");
		printf("Input data: f1(x) = (x - 5)(x - 5) + 3, f2(x) = -(x - 5)(x - 5) + 3, x = [1;7],\n precision = 0.00001, expected result: x = 5.\n");
		data.segment[0][0] = 1;
		data.segment[0][1] = 7;
		root(test_f1, test_f2, data.segment[0][0], data.segment[0][1], 0.00001);
		data.stepcount[0] >= 0 ? printf("Calculation result: x = %lf.\n", data.root[0]) : printf("Calculation result: it is impossible to calculate the root.\n");
		printf("Testing the area calculation function 'integral':\n");
		printf("Input data: f3(x) = x, x = [0;4], precision = 0.00001, expected result: S = 8 sq. units.\n");
		printf("Calculation result: S = %lf sq. units.\n", integral(test_f3, 0, 4, 0.00001));
	}
	else {																	//во всех остальных случаях программа выполнит расчет определенного интеграла
		printf("Calculating the area of a shape. For help, use -h.\n");		//с выводом на экран, в соответствии с заданной опцией командной строки:
		for (int i=0; i < 3; i++) {
			root(data.func_pair[i][0], data.func_pair[i][1], data.segment[i][0], data.segment[i][1], data.eps1);
			if (roots)														//- коодинаты X корней пар функций
				printf("Root x%d = %f\n", i+1, data.root[i]);
			if (iterations)													//- числа итераций, необходимого для вычисления корней пар функций
				printf("Number of iterations for the root x%d = %d\n", i+1, data.stepcount[i]);
		}																	//вычисление площадей фигур от каждой из функций
		if (data.stepcount[0] >= 0 && data.stepcount[1] >= 0 && data.stepcount[2] >= 0) {	//если все корни найдены, выполняем расчёт интегралов
			data.area[0] = integral(f1, data.root[0], data.root[2], data.eps2);
			printf("Integral of the function f1 on the segment [x1; x3]: S1 = %lf sq. units.\n", data.area[0]);
			data.area[1] = integral(f2, data.root[1], data.root[2], data.eps2);
			printf("Integral of the function f2 on the segment [x2; x3]: S2 = %lf sq. units.\n", data.area[1]);
			data.area[2] = integral(f3, data.root[0], data.root[1], data.eps2);
			printf("Integral of the function f3 on the segment [x1; x2]: S3 = %lf sq. units.\n", data.area[2]);
			printf("The area of the shape: S = S1 - S2 - S3 = %f sq. units.\n", data.area[0]-data.area[1]-data.area[2]);	// итоговый результат вычисления площади фигуры, ограниченной функциями f1, f2 и f3
		}
		else
			printf("Error: Not all roots were found. For more details, add the -r -i keys.\n");
	}
	return 0;
}

double f1(double x) {														//заданная функция f1
	return 0.6*x + 3;
}

double f2(double x) {														//заданная функция f2
	return (x - 2)*(x - 2)*(x - 2) - 1;
}

double f3(double x) {														//заданная функция f3
	return 3/x;
}

double test_f1(double x) {													//функция для тестирования root
	return (x - 5)*(x - 5) + 3;
}

double test_f2(double x) {													//функция для тестирования root
	return -(x - 5)*(x - 5) + 3;
}

double test_f3(double x) {													//функция для тестирования integral
	return x;
}

int signF(function f, function g, double x) {								//вычисление знака (+1, -1 или 0) разности значений двух функций в точке х
	return f(x) - g(x) > 0 ? 1 : (f(x) - g(x) < 0 ? -1 : 0);
}

double root(function f, function g, double a, double b, double eps1)		//вычисление координаты х точки пересечения двух функций с точностью eps1 на отрезке [a; b]
{
	data.progress_root++;													//счётчик корней
	
	int stepcount =0;														//счётчик итераций вычисления корня
	double xm;																//середина текущего отрезка
	if (!signF(f, g, a)){													//если начало отрезка (a) является корнем пары функций
		data.root[data.progress_root-1] = a;								//записываем его как найденный корень
		data.stepcount[data.progress_root-1] = stepcount;					//а также число итераций, затраченных на его поиск
		return a;															//и выходим из функции
	}
	else if (!signF(f, g, b)){												//аналогично поступаем с концом отрезка (b)
		data.root[data.progress_root-1] = b;
		data.stepcount[data.progress_root-1] = stepcount;
		return b;
	}
	else if (signF(f, g, a) == signF(f, g, b)) {							//если на концах отрезка [a; b] разность пары функций имеет один и тот же знак (не ноль), значит:
		while (fabs(a-b) > eps1) {											// - функции могут иметь один корень, лишь касаясь друг друга (в точке экстремума на данном отрезке)
			stepcount++;
			xm = (a + b)/2;
			if (signF(f, g, a) != signF(f, g, xm) || signF(f, g, xm) == 0)	//здесь первая часть условия прерывает цикл из-за неопределенности в вычислении корня, вторая же, наоборот, поскольку корень найден
				break;
			else
				fabs(f(a)-g(a)) < fabs(f(b)-g(b)) ? (b = xm) : (a = xm);	//если расстояние между графиками на концах отрезка одинаково или больше для (a), то двигаем (a), иначе двигаем (b)
		}
		if (fabs(f(xm)-g(xm)) > eps1) {										// - или могут не иметь корней или иметь больше одного корня (здесь fabs(f(xm)-g(xm)) > eps1 - минимальное (не абсолютное) условие наличия корня)
			printf("Within the segment [%f, %f], the function exhibits either no roots, multiple roots, or a discontinuity.\n", data.segment[0][0], data.segment[0][1]);
			data.stepcount[data.progress_root-1] = -1;						//"-1" это признак ошибки вычисления корня для текущей пары функций
			return 0;
		}
	}
	else {																	//данный блок хоть и похож на предыдущий, но имеет другой контекст входа: здесь функции обязательно пересекаются
		while (fabs(a-b) > eps1) {											//и их разность на концах отрезка [a; b] имеет разный знак
			stepcount++;
			xm = (a + b)/2;
			if (signF(f, g, xm) == 0)										//если значения обеих функций совпадают
				break;														//выходим - корень найден
			if (signF(f, g, a) != signF(f, g, xm))							//иначе, двигаем (a) или (b) ближе к корню, пока их разность по модулю не станет меньше допустимой погрешности eps1
				b = xm;
			else
				a = xm;
		}
	}
	data.root[data.progress_root-1] = xm;
	data.stepcount[data.progress_root-1] = stepcount;
	return xm;
}

double integral(function f, double a, double b, double eps2)				//вычисление определенного интеграла функции (f) с точностью eps2 на отрезке [a; b] 
{
	data.progress_area++;													//счётчик интегралов
	
	int  num_steps = 100;													//начальное количество шагов расчета - отрезков разбиения нашей фигуры по оси абсцисс
	double area = eps2 + 1, area1 = 0, step;								//предыдущее значение площади (area), текущее значение площади (area1), шаг рачета по оси абсцисс (step). area = eps2 + 1 - для корректного входа в цикл.
	if (a == b)																//если a == b мы имеем дело с площадью,
		return 0;															//вырожденной в линию => площадь равна нулю
	else if (a > b) {
		step = a;															//по определению a < b, а если это не так,
		a = b;																//меняем их местами, а в качестве буфера возьмем
		b = step;															//пока что не задействованную переменную step
	}
	while (fabs(area1-area) > eps2) {										//выполняем цикл до тех пор, пока разность между прошлым и текущим
		area = area1;														//значениями площади не будет меньше или равна eps2
		area1 = 0;
		step=(b-a)/num_steps;												//шаг расчёта для текущего цикла
		for (int i=0; i < num_steps; i++)
			area1 += 0.5*(f(a + i*step) + f(a + (i+1)*step))*step;			//здесь в качестве аргументов функции f: X(i) = a + i*step и X(i+1) = a + (i+1)*step
		num_steps *= 2;														//удваиваем количество разбиений для следующего цикла
	}
	return area1;
}
