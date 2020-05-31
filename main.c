#include <stdio.h>
#include <stdlib.h>

struct tnode{
	int value;
	struct tnode *left;
	struct tnode *right;
	struct tnode *parent;
};

struct tnode *create_leaf(int wartosc, struct tnode *mom){

	struct tnode *leaf;
	leaf =(struct tnode *)malloc(sizeof(struct tnode)); 
	
	leaf->value = wartosc;
	leaf->parent = mom;
	leaf->left = NULL;
	leaf->right = NULL;
	
	return leaf;
}

void add_leaf(int wartosc, struct tnode **head, struct tnode *mom){

	if(*(head) == NULL){
		(*head) = create_leaf(wartosc, mom);
		return;
	}
	if(wartosc > (*head)->value){
		add_leaf(wartosc, &((*head)->right), *head);
	}else{
		add_leaf(wartosc, &((*head)->left), *head);
	}
	return;
}

void in_order_print(struct tnode *head){
	if(head->left != NULL){
		in_order_print(head->left);
	}
	printf("%d ", head->value);
	if(head->right != NULL){
		in_order_print(head->right);
	}

}

void pre_order_print(struct tnode *head){
	printf("%d ", head->value);
	if(head->left != NULL){
		in_order_print(head->left);
	}
	if(head->right != NULL){
		in_order_print(head->right);
	}
	return;
}

void free_tree(struct tnode *head){
	
	if(head != NULL){
		free_tree(head->left);
		free_tree(head->right);
		free(head);
	}
}

int main(void) {

	struct tnode *tree = NULL;

	int tab[]={15, 5, 16, 20, 3, 12, 18, 23, 10, 13, 6, 7};

	for(int i=0; i<sizeof(tab)/sizeof(tab[0]); i++){
	add_leaf(tab[i], &tree, tree);
	}
	
	printf("Drzewo wypisane metdoą in-order\n");
	in_order_print(tree);
	printf("\nDrzewo wypisane metdoą pre-order\n");
	pre_order_print(tree);
	printf("\n");

	free_tree(tree);

	return 0;
}