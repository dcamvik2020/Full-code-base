#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;
struct Tree {
	int item;
	Tree *left;
	Tree *right;
};

//reads next input line, parse it and returns value in "*item" and offset (spaces) in "*level"
//if "cache" then return previous read (cached) values
//returns true (1) if all OK and false (0) otherwise
int read_node(int *item, int *level, int cache) {
	char buf[1024];
	if (item && level) {
		static int saved_item = 0;
		static int saved_level = 0;
		if (cache) {
			*item = saved_item;
			*level = saved_level;
			return 1;
		}
		if (fgets(buf, sizeof buf, stdin)) {
			int n, x, lev;
			//remove "\r\n" from string
			for (n = 0; buf[n]; n++); //n = strlen(buf);
			while (n > 0 && (buf[n-1] == '\r' || buf[n-1] == '\n'))
				buf[--n] = '\0';
			//count the number of spaces (=level)
			for (lev = 0; buf[lev] == ' '; lev++);
			//parse
			if (sscanf(buf + lev, "%d", &x) == 1) {
				*item = saved_item = x;
				*level = saved_level = lev;
				return 1;
			} else
				fprintf(stderr, "Wrong format of string: %s\n", buf + lev);
		}
	}
	return 0;
}

Tree *tree_read(int level) {
	int item, lev;
	Tree *res = NULL, *node;
	//when node at different level read, we must leave current cycle and enter or exit recursion
	//but input line is already read, so we have to skip reading input next time
	static int skip_reading = 0;
	while (read_node(&item, &lev, skip_reading)) {
		skip_reading = 0;
		if (lev == level) {
			if (res) { //the same level - neighbor - so, exit to link to parent and will enter once again
				skip_reading = 1;
				break;
			}
			//create new node
			res = (Tree *) malloc(sizeof(Tree));
			res->item = item;
			res->left = NULL;
			res->right = NULL;
			//exit to parent (or grand parent...)
			//break;
		} else
		if (lev == level + 1) { //enter to child
			if (!res) {
				fprintf(stderr, "No parent node for item = %d on level = %d\n", item, lev);
				break;
			}
			if (res->left && res->right) {
				fprintf(stderr, "Too much children (item = %d on level = %d) for parent node (item = %d on level = %d)\n", item, lev, res->item, level);
				break;
			}
			skip_reading = 1;
			node = tree_read(level + 1); //recursion!!!
			if (!res->left)
				res->left = node;
			else
				res->right = node;
		} else
		if (lev < level) { //exit to parent (or grand parent...)
			skip_reading = 1;
			break;
		} else { // lev > level + 1
			fprintf(stderr, "No parent node for item = %d on level = %d\n", item, lev);
			break;
		}
	}
	return res;
}

//tree traverse
void tree_print(Tree *tree, int level) {
	int i;
	if (tree) {
		//print
		for (i = 0; i < level; i++)
			putchar(' ');
		printf("%d\n", tree->item);
		//recursion
		tree_print(tree->left, level + 1);
		tree_print(tree->right, level + 1);
	}
}

//tree traverse
void tree_destroy(Tree *tree) {
	if (tree) {
		//recursion - free children
		tree_destroy(tree->left);
		tree_destroy(tree->right);
		//free this node
		printf("DEBUG: free %d\n", tree->item);
		free(tree);
	}
}

int main(void) {
	Tree *root;
	root = tree_read(0);
	puts("");
	tree_print(root, 0);
	puts("");
	tree_destroy(root);
	return 0;
}
