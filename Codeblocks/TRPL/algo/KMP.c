#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IF(func)        \
    if (!(func)) {      \
        perror(#func);  \
    } else              \

#define BLOCK_OF_LETTERS  10
void get_string_any_length(char **s);
void pref_func(char *s, unsigned *pref_len);
char *kmp(char *s, char *t);

int main() {
    // t - text, s - word for search
    char *s = NULL, *t = NULL;

    get_string_any_length(&s);
    get_string_any_length(&t);

    puts(kmp(s, t));

    free(s);
    free(t);
    return 0;
}

void get_string_any_length(char **s) {
    // the end <--> '\n'
    unsigned i, size = BLOCK_OF_LETTERS;
    char c, *tmp;
    *s = (char *) malloc(size * sizeof(char));
    for (i = 0; (c = getc(stdin)); i++) {
        if (i == size) {
            size += BLOCK_OF_LETTERS;
            tmp = (char *) realloc(*s, size * sizeof(char));
            if (tmp) {              // "tmp" must be used... in other case we
                *s = tmp;           // may meet some problems: let be the
            } else {                // result of realloc = NULL, --> if we
                perror("realloc");  // write:   *s = (...) realloc(*s, ...)
                exit(0);
            }                       // then *s = NULL, but that's wrong
        }
        if (c == '\n') {
            (*s)[i] = '\0';
            break;
        }
        (*s)[i] = c;                // here will be:    (NULL)[i] ... BAD!
    }
}

void pref_func(char *s, unsigned *pref_len) {
    unsigned i, j, x;
    pref_len[0] = 0; // begin from 0, it's pref_len for s[0], 1 letter
    // pref_len[i] --> for 1st   i+1   letters
    //printf("%d ", pref_len[0]);
    for (i = 1; s[i]; i++) {
        x = pref_len[i-1];
        if (s[x] == s[i]) {
            pref_len[i] = x + 1;
        } else {
            // need to find less prefix: it equals some suffix
            // all pref_len[i] <= len(s) --> look at j <= len(s)
            j = (x == 0) ? 0 : pref_len[x-1];
            for ( ; ; j = pref_len[j]) {
                if (s[j] == s[i]) {
                    pref_len[i] = j + 1;
                    break;
                }
                if (j == 0) { // s[0] != s[i]
                    pref_len[i] = 0;
                    break;
                }
            }
        }
        //printf("%d ", pref_len[i]);
    }
    //puts("");
}

char *kmp(char *s, char *t) {
    char *kmp_str_for_pref_func = NULL;
    unsigned len_s = strlen(s), len, i, count = 0, *pref_len = NULL; ;
    len = len_s + strlen(t) + 2; // +2 : '@' and '\0'
    
    IF ((kmp_str_for_pref_func = (char *) malloc(len * sizeof(char)))) {
        
        // make a concatenation
        strcpy(kmp_str_for_pref_func, s);
        strcat(kmp_str_for_pref_func, "@"); // all pref_len[i] <= len(s)
        strcat(kmp_str_for_pref_func, t);
        
        // count prefix function
        pref_len = (unsigned *) malloc(len * sizeof(unsigned));
        pref_func(kmp_str_for_pref_func, pref_len);
        
        // check (s is a part of t)
        for (i = 0; i < len; i++) {
            if (pref_len[i] == len_s) {
                count++;
            }
        }

        free(kmp_str_for_pref_func);
        free(pref_len);
    }
    if (count) {
        printf("count = %d\n", count);
        return "YES";
    } else {
        return "NO";
    }
}

