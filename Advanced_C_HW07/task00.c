#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
char word[20];
struct list *next;
};

void add_to_list(struct list **data, char *word);
void swap_elements(struct list **data, struct list *node1);	//node1 - первый элемент из двух рядом стоящих элементов
void print_list(struct list *data);
void delete_list(struct list *data);
 
int main(int argc, char **argv)
{
	struct list *data=NULL;
	char word[20], c;
	int i=0;
	while (1)
	{
		c=getchar();
		if (c != ' ' && c != '.')
			word[i++] = c;
		else{
			word[i++] = '\0';
			i=0;
			add_to_list(&data, word);
		}
		if (c == '.') break;
	}
	if (data){
		int flag=1;
		struct list *p=NULL;
		while (flag){
			flag = 0;
			p = data;
			while (p->next){
				if (strcmp(p->word, p->next->word) > 0){
					swap_elements(&data, p);
					flag = 1;
				}
				else
					p = p->next;
			}
		}
	}
	print_list(data);
	delete_list(data);
	return 0;
}

void add_to_list(struct list **data, char *word)
{
	struct list *p = (struct list*)calloc(1, sizeof(struct list));
	p->next = *data;
	strncpy(p->word, word, 19);
	*data = p;
}

void print_list(struct list *data)
{
	for (struct list *p=data; p; p = p->next)
		printf("%s ", p->word);
}

void delete_list(struct list *data)
{
	struct list *p=data, *p1=NULL;
	while (p){
		p1 = p;
		p = p->next;
		free(p1);
	}
}

void swap_elements(struct list **data, struct list *node1)
{
	struct list *node2 = node1->next;
	if (node1 == *data){
		node1->next = node2->next;
		node2->next = node1;
		*data = node2;
	}
	else
		for (struct list *p=*data; p; p = p->next){
			if (p->next == node1){
				p->next = node2;
				node1->next = node2->next;
				node2->next = node1;
				break;
			}
		}
}
