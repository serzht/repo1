#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

struct stack_t{
	int *data;
	int size;
	int  max_size;
} stack={NULL, 0, 0};

void push(int data);
int pop();

int main(int argc, char **argv)
{
	char c, num_flag=0;
	int num=0, a, b;
	while ((c=getchar()) != '.'){
		if (c >= '0' && c <= '9'){
			num = num*10 + (c - '0');
			num_flag = 1;
		}
		else{
			switch (c){
			case '+': push(pop() + pop());
				break;
			case '-': b = pop(), a = pop(), push(a-b);
				break;
			case '*': push(pop() * pop());
				break;
			case '/': b = pop(), a = pop(), push(a/b);
				break;
			case '%': b = pop(), a = pop(), push(a%b);
				break;
			case '^': b = pop(), a = pop(), push(pow(a, b));
				break;
			case ' ':
				if (num_flag){
					push(num);
					num=0;
					num_flag=0;
				}
				break;
			}
		}
	}
	printf("%d\n", pop());
	return 0;
}

void push(int data)
{
	if (stack.max_size == stack.size){
		stack.max_size += SIZE;
		stack.data = realloc(stack.data, stack.max_size*sizeof(int));
	}
	stack.data[stack.size] = data;
	stack.size++;
}

int pop()
{
	if (stack.max_size - stack.size >= 2*SIZE){
		stack.max_size -= SIZE;
		stack.data = realloc(stack.data, stack.max_size*sizeof(int));
	}
	if (stack.size == 0) return -1;
	stack.size--;
	return stack.data[stack.size];
}
