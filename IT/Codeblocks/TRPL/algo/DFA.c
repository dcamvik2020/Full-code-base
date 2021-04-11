#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DFA --> graph with directions: Q, F, q0, d, S
// d --> jump rules
// S --> alphabet

#define SOME_LETTERS 5

struct jump {
    unsigned from;
    char letter;
    unsigned to;
};

void input(unsigned *Q, unsigned *F, unsigned **final, unsigned *q0,
	   char **SIGMA, unsigned *alphabet, struct jump *rules) {
    char *tmp = NULL, letter;
    unsigned i;
    //input: Q, F
    printf("All conditions: ");
    scanf("%u", Q);
    printf("Final conditions: ");
    scanf("%u", F);
    if (*F > *Q) {
        puts("Wrong quantity of final conditions!");
        exit(0);
    }
    printf("List of final conditions:");
    *final = (unsigned *) malloc((*F) * sizeof(unsigned));
    for (i = 0; i < *F; i++) {
        scanf("%u", &(*final)[i]);
	if ((*final)[i] >= *Q) {
            printf("Wrong condition: %u\n", (*final)[i]);
	    exit(0);
	}
    }
    printf("Enter the start condition: ");
    scanf("%u", q0);
    if (*q0 >= *Q) {
        puts("Wrong start condition!");
        exit(0);
    }
    
    
                                   /*
    
    puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

    //input: alphabet SIGMA
    puts("Enter the alphabet: ");
    //exit(0);
    puts("");
    *SIGMA = (char *) malloc ((*alphabet) * sizeof(char));
    for (i = 0; ; ) {
        scanf("%c", &letter); 
        printf("letter = %d\n", letter);
        if (i == *alphabet) {
            *alphabet += SOME_LETTERS;
            tmp = (char *) realloc(*SIGMA, (*alphabet) * sizeof(char));
            if (tmp) {
                *SIGMA = tmp;
            } else {
                perror("realloc(for SIGMA)");
                exit(0);
            }
        }
        if (letter == '\n') {
            (*SIGMA)[i] = '\0';
            break;
        } else if (letter != ' ') {
            (*SIGMA)[i] = letter;
            i++;
        }
    }
    puts("Scanfed alphabet od DFA:");
    for (i = 0; (*SIGMA)[i]; i++) {
        printf("%c ", (*SIGMA)[i]);
    }
    puts("");

    // input: jump rules
    //puts("Enter the transition rules");
    
    
                                     */

}

int main() {
    unsigned Q, F, q0; // size of Q, F (see higher), start (q0)
    unsigned *final = NULL, alphabet = SOME_LETTERS, i;
    char *SIGMA = NULL, letter;
    struct jump *rules = NULL;
    
    input(&Q, &F, &final, &q0, &SIGMA, &alphabet, rules);
    

    

    //puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    //fflush(stdin);
    //fflush(stdout);

    //input: alphabet SIGMA
    puts("Enter the alphabet: ");
    //exit(0);
    puts("");
    SIGMA = (char *) malloc ((alphabet) * sizeof(char));
    for (i = 0; ; ) {
        scanf("%c", &letter); 
        printf("letter = %d\n", letter);
        if (i == alphabet) {
            char *tmp;
            alphabet += SOME_LETTERS;
            tmp = (char *) realloc(SIGMA, (alphabet) * sizeof(char));
            if (tmp) {
                SIGMA = tmp;
            } else {
                perror("realloc(for SIGMA)");
                exit(0);
            }
        }
        if (letter == '\n') {
            (SIGMA)[i] = '\0';
            break;
        } else if (letter != ' ') {
            (SIGMA)[i] = letter;
            i++;
        }
    }
    puts("Scanfed alphabet od DFA:");
    for (i = 0; (SIGMA)[i]; i++) {
        printf("%c ", (SIGMA)[i]);
    }
    puts(""); 







    free(final);
    free(SIGMA);
    // free(rules); for (i=0, ...
    return 0;
}
