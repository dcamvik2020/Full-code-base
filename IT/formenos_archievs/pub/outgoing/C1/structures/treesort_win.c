/*
 * test.c
 *
 *  Created on: 14.11.2012
 *      Author: Andrey
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#define SLASH "\\"

typedef struct {
    char *name;
    long long size;
} Data;

typedef struct Tree Tree;
struct Tree {
    Data *data;
    Tree *child;
    Tree *next;
};

Tree *root = NULL;

//tree can be NULL
Tree *tree_append(Tree *tree, Data *data) {
    Tree *head = tree;
    //create tree item
    Tree *new_item = (Tree *) malloc(sizeof(Tree));
    new_item->data = data;
    new_item->child = NULL;
    new_item->next = NULL;
    if (head) {
        //go to the end
        while (tree->next)
            tree = tree->next;
        //append
        tree->next = new_item;
    } else {
        head = new_item; //init (create) tree
    }
    return new_item;
}

//node cannot be NULL
Tree *tree_append_child(Tree *node, Data *data) {
    Tree *new_item = tree_append(node->child, data);
    if (!node->child)
        node->child = new_item;
    return new_item;
}

const int dK = 1024, dM = 1024 * 1024, dG = 1024 * 1024 * 1024;

void print_size(char buf[13], long long size) {
    double d = (double)size;
    char c = ' ';
    if (d >= dG) {
        d /= dG;
        c = 'G';
    } else
    if (d >= dM) {
        d /= dM;
        c = 'M';
    } else
    if (d >= dK) {
        d /= dK;
        c = 'K';
    } else {
        sprintf(buf, "%lg", d);
        return;
    }
    sprintf(buf, "%-6.2lf %c", d, c);
}

//tree traverse
void tree_print(Tree *tree, int level) {
    int i;
    char buf[13];
    while (tree) {
        //fool check
        if (!tree->data) {
            fprintf(stderr, "NULL\n");
            continue;
        }
        //print
//        printf("%-12lli", tree->data->size);
        print_size(buf, tree->data->size);
        printf("%-12s", buf);
        for (i = 0; i < level; i++)
            putchar('\t');
        puts(tree->data->name);
        //recursion
        tree_print(tree->child, level + 1);
        //pass to next item
        tree = tree->next;
    }
}

//tree traverse
void tree_free(Tree *tree) {
    if (tree) {
        //recursion
        tree_free(tree->child);
        //free next item
        tree_free(tree->next);
        //free this item
        if (tree->data) {
            free(tree->data->name);
            free(tree->data);
        }
        free(tree);
    }
}

//merge sort
Tree *sort(Tree *L) {
    int i, n;
    Tree *R, *res, *list;
    //get length of list
    for (R = L, n = 0; R; R = R->next, n++);
    if (n < 2)
        return L;
    //divide list on two parts
    for (R = L, i = 0; i < n / 2 - 1; i++)
        R = R->next;
    res = R; R = R->next; res->next = NULL;
    L = sort(L); //recursively sort left list
    R = sort(R); //recursively sort right list
    //merge left and right lists into result list
    res = list = NULL;
    while (L || R) {
        if (!R || (L && L->data->size >= R->data->size)) {
            if (list) {
                list->next = L;
                list = list->next; //L;
            } else
                res = list = L;
            L = L->next;
        } else {
            if (list) {
                list->next = R;
                list = list->next; //R;
            } else
                res = list = R;
            R = R->next;
        }
    }
    list->next = NULL;
    return res;
}

Tree *tree_sort(Tree *tree) {
    Tree *head;
    head = tree = sort(tree);
    while (tree) {
        //recursion
        tree->child = tree_sort(tree->child);
        //pass to next item
        tree = tree->next;
    }
    return head;
}

void scan_dir(const char *dir, Tree *parent) {
    /*intptr_t*/ long handle;
    struct _finddata_t /*__finddata64_t*/ fileinfo;
    char buf[FILENAME_MAX], filter[FILENAME_MAX];
    Data *data;
    Tree *node;
    strcpy(filter, dir); strcat(filter, SLASH); strcat(filter, "*");
    if ((handle = _findfirst/*64*/(filter, &fileinfo)) != -1) {
        do {
            //skip "." and ".."
            if (!strcmp(fileinfo.name, ".") || !strcmp(fileinfo.name, ".."))
                continue;
            //print
            strcpy(buf, dir); strcat(buf, SLASH); strcat(buf, fileinfo.name);
//            puts(buf);
            //save item to tree structure
            data = (Data *) malloc(sizeof(Data));
            data->name = strdup(fileinfo.name);
            data->size = fileinfo.size;
            node = tree_append_child(parent, data);
            //recursion
            if (fileinfo.attrib & _A_SUBDIR)
                data->size = 0,
                scan_dir(buf, node);
            parent->data->size += data->size;
        } while (_findnext/*64*/(handle, &fileinfo) != -1);
        _findclose(handle);
    }
}

int main(int argc, char *argv[]) {
    char path_buf[256], *path;
    Data *data;
    //get directory name
    if (argc > 1)
        path = argv[1];
    else {
        int n;
        printf("Enter directory path: ");
        if (fgets(path_buf, sizeof path_buf, stdin) == NULL)
            return -1;
        if ((n = strlen(path_buf)) > 0)
            if (path_buf[n-1] == '\n')
                path_buf[n-1] =  '\0';
        path = path_buf;
    }
    //create root node
    data = (Data *) malloc(sizeof(Data));
    data->name = strdup(path);
    data->size = 0;
    root = tree_append(root, data);
    //recursive traverse directories
    scan_dir(path, root);
//    tree_print(root, 0);
    root = tree_sort(root);
    tree_print(root, 0);
    tree_free(root);
    return 0;
}
