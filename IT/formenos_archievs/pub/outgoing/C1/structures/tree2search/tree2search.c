#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Tree Tree;
struct Tree {
	int key;
	double value;
	Tree *left;
	Tree *right;
};

//INSERT
//return pointer to new node
Tree *tree_add(Tree *tree, int key, double value) {
	Tree *node;
	if (!tree) {
		//create tree node
		node = (Tree *) malloc(sizeof(Tree));
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if (key < tree->key) {
		//recursively add to left subtree
		node = tree_add(tree->left, key, value);
		if (!tree->left) //if child, then update link
			tree->left = node;
		return node;
	} else {
		//recursively add to right subtree
		node = tree_add(tree->right, key, value);
		if (!tree->right) //if child, then update link
			tree->right = node;
		return node;
	}
}

//REMOVE
//return NULL if this node was removed
Tree *tree_del(Tree *tree, int key) {
	Tree *node, *parent;
	if (!tree)
		return NULL;
	if (key < tree->key)
		//recursively remove from left subtree
		tree->left = tree_del(tree->left, key);
	else
	if (key > tree->key)
		//recursively remove from right subtree
		tree->right = tree_del(tree->right, key);
	else
	if (key == tree->key) {
		//no children - simple delete and set parent's link to NULL
		if (!tree->left && !tree->right) {
			free(tree);
			return NULL;
		} else
		//only one child - copy child to parent and remove child node
		if (!tree->left && tree->right) {
			node = tree->right;
			*tree = *node;
			free(node);
		} else
		if (tree->left && !tree->right) {
			node = tree->left;
			*tree = *node;
			free(node);
		} else {
//		if (tree->left && tree->right) { //two children
			//search most left from right subtree
			parent = tree;
			node = tree->right;
			while (node->left) {
				parent = node;
				node = node->left;
			}
			//copy data
			tree->key = node->key;
			tree->value = node ->value;
			//recursively delete found node and update parent's link
			if (parent == tree)
				parent->right = tree_del(node, node->key);
			else
				parent->left = tree_del(node, node->key);
		}
	}
	return tree;
}

//FIND
Tree *tree_find(Tree *tree, int key) {
	if (!tree)
		return NULL;
	if (key == tree->key)
		return tree;
	if (key < tree->key)
		return tree_find(tree->left, key);
	else
		return tree_find(tree->right, key);
}

/*
//Depth-first search, DFS
//tree PREFIX_TRAVERSE
void tree_print(Tree *tree, int level) {
	int i;
	if (tree) {
		//print
		for (i = 0; i < level; i++)
			putchar('\t');
		printf("%i (%lg)\n", tree->key, tree->value);
		//recursion
		tree_print(tree->left, level + 1);
		tree_print(tree->right, level + 1);
	}
}
*/

//Depth-first search, DFS
//tree PREFIX_TRAVERSE
void traverse(Tree *tree, void (*f)(Tree *item, int depth), int level) {
	if (tree) {
		//go to node
		f(tree, level);
		//recursion
		traverse(tree->left, f, level + 1);
		traverse(tree->right, f, level + 1);
	}
}

void tree_print(Tree *item, int depth) {
	int i;
	for (i = 0; i < depth; i++)
		putchar('\t');
	printf("%i (%lg)\n", item->key, item->value);
}

//Depth-first search, DFS
//tree PREFIX_TRAVERSE
void dfs(Tree *tree) {
	Stack stack = NULL;
	if (!tree)
		return;
	stack = stack_push(stack, tree); //push root
	while (stack) { //while stack is not empty
		Tree *node;
		stack = stack_pop(stack, (void **)&node);
		tree_print(node, 0);
		if (node->right)
			stack = stack_push(stack, node->right);
		if (node->left)
			stack = stack_push(stack, node->left);
	}
}

//Breadth-first search, BFS
//tree PREFIX_TRAVERSE
void wfs(Tree *tree) {
	Queue queue = NULL;
	if (!tree)
		return;
	queue = queue_push(queue, tree); //push root
	while (queue) { //while queue is not empty
		Tree *node;
		queue = queue_shift(queue, (void **)&node);
		tree_print(node, 0);
		if (node->left)
			queue = queue_push(queue, node->left);
		if (node->right)
			queue = queue_push(queue, node->right);
	}
}

void wfs1(Tree *tree);
Tree *tree_get_test(int test);

//Depth-first search, DFS
//tree POSTFIX_TRAVERSE
void tree_destroy(Tree *tree) {
	if (tree) {
		//recursion - free children
		tree_destroy(tree->left);
		tree_destroy(tree->right);
		//free this node
		printf("DEBUG: free %i (%lg)\n", tree->key, tree->value);
		free(tree);
	}
}

int main(void) {
	int choice, key, view = 0, test = 0;
	double value;
	Tree *root = NULL, *node;
	do {
		printf("MENU:\n"
				"0. Exit\n"
				"1. Add  node\n"
				"2. Del  node\n"
				"3. Find node\n"
				"4. Change view\n"
				"5. Fill test tree\n"
				"Enter your choice: "
				);
		if (scanf("%i", &choice) != 1)
			choice = 0;
		switch (choice) {
		case 1:
			printf("Enter key: ");
			scanf("%i", &key);
			printf("Enter value: ");
			scanf("%lf", &value);
			node = tree_add(root, key, value);
			if (!root)
				root = node;
			break;
		case 2:
			printf("Enter key: ");
			scanf("%i", &key);
			root = tree_del(root, key);
			break;
		case 3:
			printf("Enter key: ");
			scanf("%i", &key);
			node = tree_find(root, key);
			if (node)
				printf("key = %i\nvalue = %lg\n", node->key, node->value);
			else
				puts("Not Found!");
			break;
		case 4:
			view = (view + 1) % 4;
			break;
		case 5:
			tree_destroy(root);
			root = tree_get_test(test);
			test = (test + 1) % 2;
			break;
		}
		//print
		switch (view) {
		case 0:
			puts("Breadth-first search, BFS (IMPROVED):");
			wfs1(root);
			puts("");
			break;
		case 1:
			puts("Depth-first search, DFS (Recursion):");
			//tree_print(root, 0);
			traverse(root, tree_print, 0);
			break;
		case 2:
			puts("Depth-first search, DFS (Stack):");
			dfs(root);
			break;
		case 3:
			puts("Breadth-first search, BFS (Queue):");
			wfs(root);
			break;
		}
	} while (choice);
	tree_destroy(root);
	return 0;
}
