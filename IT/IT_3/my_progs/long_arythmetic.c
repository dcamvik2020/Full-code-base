#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000
#define n 100
#define max(a, b) ( ((a) > (b)) ? (a) : (b) )

void beginner_input(char **a, char **b, char **res);
char num_sort(char **a, char **b);
// order = num_sort(a, b); // 0 --> initial order, 1 --> reverse
void reverse_str(char *s, unsigned long len);
char *sum(char *a, char *b, char *res);
char *sub(char *a, char *b, char *res);
char *mul_by_digit(char *s, char digit, char *res);
char *mul_slow(char *a, char *b, char *res);

int main() {
    char *a = NULL, *b = NULL, *res = NULL;
    beginner_input(&a, &b, &res);
    
    printf("sum = %s\n", sum(a, b, res));
    printf("sub = %s\n", sub(a, b, res));
    printf("mul = %s\n", mul_slow(a, b, res));
    
    free(a);
    free(b);
    free(res);
    return 0;
}

void beginner_input(char **a, char **b, char **res) {
    char *p;
    *a = (char *) malloc(n * sizeof(char));
    *b = (char *) malloc(n * sizeof(char));
    *res = (char *) calloc(N, sizeof(char));
    printf("a = ");
    fgets(*a, n, stdin);
    printf("b = ");
    fgets(*b, n, stdin);
    if ((p = strchr(*a, '\n'))) {
        *p = 0;
    }
    if ((p = strchr(*b, '\n'))) {
        *p = 0;
    }
}

// a, b >= 0 --> make a > b
char num_sort(char **a, char **b) {
    if ((strlen(*a) < strlen(*b)) || (strlen(*a) == strlen(*b) && strcmp(*a, *b) < 0)) {
        char *temp;
        temp = *a;
        *a = *b;
        *b = temp;
        return 1;
    }
    return 0;
}

void reverse_str(char *s, unsigned long len) {
    char c;
    unsigned long i;
    for (i = 0; i < len / 2; i++) {
        c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
}

char *sum(char *a, char *b, char *res) {
    unsigned long i, len_a, len_b, len_res;
    char digit_sum = 0, rest = 0;
    if (a[0] == '-' && b[0] == '-') {
        // a <0, b < 0
        res[0] = '-';
        sum(a+1, b+1, res+1);
        // here we can't return, because it will be written at res+1, but not res
    } else if (a[0] != '-' && b[0] == '-') {
        // a > 0, b < 0
        sub(a, b+1, res);
    } else if (a[0] == '-' && b[0] != '-') {
        // a < 0, b > 0
        sub(b, a+1, res);
    } else {
        //a > 0, b > 0
        num_sort(&a, &b);
        len_a = strlen(a);
        len_b = strlen(b);
        for (i = 0; i < len_a; i++) {
            if (i < len_b) { // i < len_b <= len_a
                digit_sum = a[len_a - i - 1] + b[len_b - i - 1] - 2 * '0' + rest;
            } else if (i < len_a) { // len_b <= i < len_a
                digit_sum = a[len_a - i - 1] - '0' + rest;
            }
            rest = digit_sum / 10;
            res[i] = digit_sum % 10 + '0';
            //printf("d_s = %d, rest = %d, res[i] = %c\n", digit_sum, rest, res[i]);
        }
        if (rest) { // i = len_a
            res[i] = rest + '0';
            i++;
        }
        
        // delete unnessary zeroes
        // i --> after all digits --> check from (i - 1)
        for ( ; i > 1 && res[i - 1] == '0'; i--);
        res[i] = '\0';
        len_res = i;
        reverse_str(res, len_res);
    }
    return res;
}

char *sub(char *a, char *b, char *res) {
    unsigned long i, len_a, len_b, len_res;
    char digit_sub, credit = 0, order;
    char *copy_a = NULL, *copy_b = NULL;
    if (a[0] == '-' && b[0] == '-') {
        // a < 0, b < 0
        sum(b+1, a+1, res);
    } else if (a[0] == '-' && b[0] != '-') {
        // a < 0, b >= 0
        res[0] = '-';
        sum(a+1, b, res+1);
    } else if (a[0] != '-' && b[0] == '-') {
        // a >= 0, b < 0
        sum(a, b+1, res);
    } else {
        // a >= 0, b >= 0
        copy_a = strdup(a);
        copy_b = strdup(b);
        //copy_a[strlen(a)] = 0;
        order = num_sort(&copy_a, &copy_b);
        // we've sorted a, b --> len_a >= len_b
        len_a = strlen(copy_a);
        len_b = strlen(copy_b);
        for (i = 0; i < len_a; i++) {
            if (i < len_b) { // look at i < len_b last digits
                if (copy_a[len_a - i - 1] < copy_b[len_b - i - 1]) {
                    int x = len_a - i - 2;
                    //take extra 10 from the next level
                    if (x >= 0) {
                        credit = 10;
                    }
                    // it can be 0 --> search first > 0, all 0 --> 9
                    while (x > 0 && copy_a[x] == '0') {
                        copy_a[x] = '9';
                        x--;
                    } // now we have found not zero digit
                    copy_a[x]--;
                }
                digit_sub = copy_a[len_a - i - 1] + credit - copy_b[len_b - i - 1];
            } else {
                digit_sub = copy_a[len_a - i - 1] - '0' ;
            }
            res[i] = digit_sub + '0';
            credit = 0; // every time we need to take new credit
        }
        res[i] = '\0';
        while (i > 1 && res[i - 1] == '0') {
            i--;
        }
        if (order) {
            res[i] = '-';
            i++;
        }
        res[i] = '\0';
        len_res = i;
        reverse_str(res, len_res);
        free(copy_a);
        free(copy_b);
    }
    return res;
}

// mul s by digit and return it
char *mul_by_digit(char *s, char digit, char *res) {
    unsigned long i, len_s = strlen(s);
    char bonus = 0, digit_mul;
    for (i = 0; i < len_s || bonus; i++) {
        if (i < len_s) {
            digit_mul = (s[len_s - i - 1] - '0') * digit;
        } else {
            digit_mul = 0;
        }
        res[i] = '0' + (bonus + digit_mul) % 10;
        bonus = (bonus + digit_mul) / 10;
    }
    res[i] = '\0';
    reverse_str(res, strlen(res));
    return res;
}

char *mul_slow(char *a, char *b, char *res) {
    unsigned long i, len_b;
    char *tmp = NULL, *buf = NULL;
    // tmp = digit * string
    // buf = sum of (10^k * tmp), k = i (look down)
    
    if (a[0] == '-' && b[0] == '-') {
        // a < 0, b < 0
        mul_slow(a+1, b+1, res);
    } else if (a[0] == '-' && b[0] != '-') {
        // a < 0, b >= 0
        res[0] = '-';
        mul_slow(a+1, b, res+1);
    } else if (a[0] != '-' && b[0] == '-') {
        // a >= 0, b < 0
        res[0] = '-';
        mul_slow(a, b+1, res+1);
    } else {
        // a > 0, b > 0
        num_sort(&a, &b);
        len_b = strlen(b);

        // now len_a >= len_b
        tmp = (char *) malloc(n * sizeof(char));
        buf = (char *) malloc(N * sizeof(char));
        strcpy(res, ""); // for this calculation
        for (i = 0; i < len_b; i++) {
            unsigned long j, zeroes = len_b - i - 1;
            char digit = b[i] - '0';
            
            mul_by_digit(a, digit, tmp);
            for (j = 0; j < zeroes; j++) {
                strcat(tmp, "0");
            }
            strcpy(buf, res);    // buf res
            sum(tmp, buf, res);  // res += tmp, tmp = digit * a * 10^zeroes
        }

        free(tmp);
        free(buf);
    }
    return res;
}
