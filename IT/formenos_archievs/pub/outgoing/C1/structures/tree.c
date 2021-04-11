#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

typedef struct Tree Tree;
struct Tree {
	char item[N];
	Tree *child;
	Tree *parent;
	Tree *previous;
	Tree *next;
};

//tree can be NULL
Tree *tree_append(Tree *tree, char *item) {
	//create tree node
	Tree *new_node = (Tree *) malloc(sizeof(Tree));
	strncpy(new_node->item, item, N); new_node->item[N-1] = '\0';
	new_node->child = NULL;
	new_node->parent = NULL;
	new_node->previous = NULL;
	new_node->next = NULL;
	if (tree) {
		//go to the end
		while (tree->next)
			tree = tree->next;
		//append
		tree->next = new_node;
		new_node->previous = tree;
		new_node->parent = tree->parent;
	}
	return new_node;
}

//node cannot be NULL
Tree *tree_append_child(Tree *node, char *item) {
	Tree *new_node = tree_append(node->child, item);
	if (!node->child) {
		node->child = new_node;
		new_node->parent = node;
	}
	return new_node;
}

//tree traverse
void tree_print(Tree *tree, int level, Tree *current) {
	int i;
	while (tree) {
		//print
		if (tree == current)
			printf("> ");
		else
			printf("  ");
		for (i = 0; i < level; i++)
			putchar('\t');
		puts(tree->item);
		//recursion
		tree_print(tree->child, level + 1, current);
		//pass to next node
		tree = tree->next;
	}
}

//tree traverse
void tree_destroy(Tree *tree) {
	if (tree) {
		//free next node (with all its children)
		tree_destroy(tree->next);
		//recursion - free children
		tree_destroy(tree->child);
		//free this node
		printf("DEBUG: free %s\n", tree->item);
		free(tree);
	}
}

//node cannot be NULL
Tree *tree_del(Tree *node) {
	Tree *res = NULL;
	//exclude node (with all its subtree) from tree
	//check link from parent to child
	if (node->parent) {
		if (node->parent->child == node)
			node->parent->child = node->next;
		res = node->parent;
	}
	//remove from double-linked list of children
	if (node->previous) {
		node->previous->next = node->next;
		res = node->previous;
	}
	if (node->next) {
		node->next->previous = node->previous;
		res = node->next;
	}
	//destroy this node and all its subtree
	node->next = NULL; //don't touch neighbors!
	tree_destroy(node);
	return res;
}

/*char *my_gets(char *s, int n) {
	if (!fgets(s, n, stdin)) {
		s[0] = '\0';
		return NULL;
	}
	if (strlen(s) > 0)
		if (s[strlen(s)-1] == '\n')
			s[strlen(s)-1] =  '\0';
	return s;
}*/

int main(void) {
	int choice;
	char s[N];
	Tree *root = NULL, *current = NULL, *node;
	do {
		printf("MENU:\n"
				"0. Exit\t\t\t\tNavigate tree:\n"
				"1. Add sibling node\t\t6. Move to prev sibling node\n"
				"2. Add child   node\t\t7. Move to next sibling node\n"
				"3. Del current node\t\t8. Enter to child node\n"
				"4. Get current node\t\t9. Exit to parent node\n"
				"5. Set current node\n"
				"Enter your choice: "
				);
		if (scanf("%i", &choice) != 1)
			choice = 0;
		if (!current && choice != 0 && choice != 1) {
			printf("ERROR! Current node is not set.\n");
			continue;
		}
		switch (choice) {
		case 1:
			printf("Enter word: ");
			scanf("%s", s);
			node = tree_append(current, s);
			if (!root)
				root = current = node;
			break;
		case 2:
			printf("Enter word: ");
			scanf("%s", s);
			tree_append_child(current, s);
			break;
		case 3:
			node = tree_del(current);
			if (current == root)
				root = node;
			current = node;
			break;
		case 4:
			printf("Current node = %s\n", current->item);
			break;
		case 5:
			printf("Enter word: ");
			scanf("%s", s);
			strncpy(current->item, s, N); current->item[N-1] = '\0';
			break;
		case 6:
			if (current->previous)
				current = current->previous;
			else
				printf("ERROR! There is no previous sibling node.\n");
			break;
		case 7:
			if (current->next)
				current = current->next;
			else
				printf("ERROR! There is no next sibling node.\n");
			break;
		case 8:
			if (current->child)
				current = current->child;
			else
				printf("ERROR! There is no child node.\n");
			break;
		case 9:
			if (current->parent)
				current = current->parent;
			else
				printf("ERROR! There is no parent node.\n");
			break;
		}
		tree_print(root, 0, current);
	} while (choice);
	tree_destroy(root);
	return 0;
}
