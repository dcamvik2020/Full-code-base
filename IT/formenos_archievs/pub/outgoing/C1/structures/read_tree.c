#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;
struct Tree {
	int item;
	Tree *child;
	Tree *next;
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
	Tree *res = NULL, *last = NULL;
	//when node at different level read, we must leave current cycle and enter or exit recursion
	//but input line is already read, so we have to skip reading input next time
	static int skip_reading = 0;
	while (read_node(&item, &lev, skip_reading)) {
		skip_reading = 0;
		if (lev == level) { //the same level - neighbor
			//create new node
			Tree *new_node = (Tree *) malloc(sizeof(Tree));
			new_node->item = item;
			new_node->child = NULL;
			new_node->next = NULL;
			//append created node
			if (last) {
				last->next = new_node;
				last = last->next;
			} else //first
				res = last = new_node;
		} else
		if (lev == level + 1) { //enter to child
			if (!last) {
				fprintf(stderr, "No parent node for item = %d on level = %d\n", item, lev);
				break;
			}
			skip_reading = 1;
			last->child = tree_read(level + 1); //recursion!!!
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
	for ( ; tree; tree = tree->next) {
		//print
		for (i = 0; i < level; i++)
			putchar(' ');
		printf("%d\n", tree->item);
		//recursion
		tree_print(tree->child, level + 1);
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
