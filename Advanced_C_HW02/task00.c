/*
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct list{
	uint64_t address;
	size_t size;
	char comment[64];
	struct list *next;
} list;

uint64_t findMaxBlock(list *head);
void load(list **head);
	
int main(int argc, char **argv)
{
	list *head=NULL;
	load(&head);
	printf("%lld\n", findMaxBlock(head));
	return 0;
}

void load(list **head)
{
	int n;
	list *p=NULL;
	scanf("%d", &n);
	for (int i=0; i < n; i++){
		p = *head;
		*head = malloc(sizeof(list));
		scanf("%llu%llu", &(*head)->address, &(*head)->size);
		(*head)->next = p;
	}
}
*/
uint64_t findMaxBlock(list *head)
{
	uint64_t p_max=0;
	size_t size_max;
	for (list *p=head; p; p=p->next){
		if (p_max){
			if (size_max < p->size){
				p_max = p->address;
				size_max = p->size;
			}
		}
		else{
			p_max = p->address;
			size_max = p->size;
		}
	}
	return p_max;
}
