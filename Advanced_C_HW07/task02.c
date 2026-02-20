/*
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int key;
	struct tree *left, *right;
	struct tree *parent;
} tree;

tree *findBrother(tree *root, int key);
void insertNode(tree **root, tree *parent, int key);

int main(int argc, char **argv)
{
	int key;
	tree *root = NULL;
	while(1){
		scanf("%d", &key);
		if (key == 0){
			scanf("%d", &key);
			break;
		}
		insertNode(&root, NULL, key);
	}
	tree *brother = findBrother(root, key);
	printf("%d\n", brother ? brother->key : 0);
	return 0;
}

void insertNode(tree **root, tree *parent, int key)
{
	if (*root){
		if (key < (*root)->key)
			insertNode(&((*root)->left), *root, key); 
		else
			insertNode(&((*root)->right), *root, key); 
	}
	else{
		*root = calloc(1, sizeof(tree));
		(*root)->key = key;
		(*root)->parent = parent;
	}
}
*/
tree *findBrother(tree *root, int key)
{
	static tree *brother=NULL;
	if (brother)
		return brother;
	if (!root)
		return NULL;
	else if (root->key == key && root->parent){
		if (root->parent->left == root && root->parent->right){
			brother = root->parent->right;
			return brother;
		}
		else if (root->parent->right == root && root->parent->left){
			brother = root->parent->left;
			return brother;
		}
	}
	else{
		if (root->left)
			findBrother(root->left, key);
		if (root->right)
			findBrother(root->right, key);
	}
	return brother;
}
