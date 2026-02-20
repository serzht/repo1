/*
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int key;
	struct tree *left, *right;
} tree;

void btUpView(tree *root);
void insertNode(tree **root, int key);

int main(int argc, char **argv)
{
	int key;
	tree *root = NULL;
	while(1){
		scanf("%d", &key);
		if (key == 0) break;
		insertNode(&root, key);
	}
	btUpView(root);
	return 0;
}

void insertNode(tree **root, int key)
{
	if (*root){
		if (key < (*root)->key)
			insertNode(&((*root)->left), key); 
		else
			insertNode(&((*root)->right), key); 
	}
	else{
		*root = calloc(1, sizeof(tree));
		(*root)->key = key;
	}
}
*/
void btUpView(tree *root)
{
	int arr[1000] = {0}, counter=0;
	if (root){
		if (root->left){
			for (tree *tr=root->left; tr; tr = tr->left)
				arr[counter++] = tr->key;
			for (int i=counter-1; i >= 0; i--)
				if (arr[i]) printf("%d ", arr[i]);
		}
		printf("%d ",root->key);
		if (root->right){
			for (tree *tr=root->right; tr; tr = tr->right)
				printf("%d ",tr->key);
		}
	}
}
