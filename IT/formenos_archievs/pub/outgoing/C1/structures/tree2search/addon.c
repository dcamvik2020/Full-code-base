#include <stdio.h>
#include "list.h"

//repeat structure here
typedef struct Tree Tree;
struct Tree {
	int key;
	double value;
	Tree *left;
	Tree *right;
};

//Depth-first search, DFS
int tree_depth(Tree *tree) {
	int l, r;
	if (!tree)
		return 0;
	l = tree_depth(tree->left);
	r = tree_depth(tree->right);
	return (l > r ? l : r) + 1;
}

void tree_printDX(Tree *item, long x) {
	long i;
	for (i = 0; i < x; i++)
		printf("   ");
	printf("%3i", item->key);
}

//Breadth-first search, BFS
//tree PREFIX_TRAVERSE
void wfs1(Tree *tree) {
	long l = 1, x, oldX;
	Queue queue = NULL;
	if (!tree)
		return;
	x = tree_depth(tree);
	for (; x > 0; x--)
		l *= 2;		// l = 2^x; x = 0
	queue = queue_push(queue, tree); //push root
	queue = queue_push(queue, (void *)(l / 2));
	while (queue) { //while queue is not empty
		Tree *node;
		oldX = x;
		queue = queue_shift(queue, (void **)&node);
		queue = queue_shift(queue, (void **)&x);
		if (x < oldX) { //new level
			printf("\n");
			oldX = 0;
			l /= 2;
		}
//		printf("%i (%lg)\t", node->key, node->value);
		tree_printDX(node, x - oldX - 1);
		if (node->left) {
			queue = queue_push(queue, node->left);
			queue = queue_push(queue, (void *)(x - l / 4));
		}
		if (node->right) {
			queue = queue_push(queue, node->right);
			queue = queue_push(queue, (void *)(x + l / 4));
		}
	}
}

Tree *tree_add(Tree *tree, int key, double value);

Tree *tree_get_test(int test) {
	Tree *root = NULL;
	if (test == 0) {
		root = tree_add(root, 8, 8);
		tree_add(root, 3, 3);
		tree_add(root, 10, 10);
		tree_add(root, 1, 1);
		tree_add(root, 6, 6);
		tree_add(root, 7, 7);
		tree_add(root, 4, 4);
		tree_add(root, 14, 14);
		tree_add(root, 13, 13);
	} else
	if (test == 1) {
		root = tree_add(root, 10, 10.1);
		tree_add(root, 12, 12.1);
		tree_add(root, 9, 9.1);
		tree_add(root, 11, 11.1);
		tree_add(root, 14, 14.1);
		tree_add(root, 8, 8.1);
		tree_add(root, 10, 10.2);
		tree_add(root, 13, 13.1);
		tree_add(root, 9, 9.2);
		tree_add(root, 11, 11.2);
		tree_add(root, 12, 12.2);
		tree_add(root, 13, 13.2);
		tree_add(root, 14, 14.2);
		tree_add(root, 14, 14.3);
	}
	return root;
}
