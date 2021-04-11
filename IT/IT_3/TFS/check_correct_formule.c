#include <stdio.h>
#include <string.h>

#define N 100

char s[N];

char *check_bracket_balance(const char *left, const char *right, int *zero_brackets_balance, int *zero_brackets_positions) {
    int bracket_balance = 0, i;
    char *tmp;
    for (tmp = (char *) left, i = 0; tmp <= right; tmp++) {
        if (bracket_balance < 0) {
            return (char *) "NO";
        }
        if (*tmp == '(') {
            bracket_balance++;
        } else if (*tmp == ')') {
            bracket_balance--;
            if (!bracket_balance) {
                zero_brackets_balance[i] = (int) (tmp - left);
                i++;
            }
        }
    }
    if (bracket_balance) {
	    printf("br_bal is not zero: %d\n", bracket_balance);
        return (char *) "NO";
    }
    *zero_brackets_positions = i;
    return (char *) "YES";
}

char *check_formule_IV(const char *left, const char *right) {
    // input : a string, *right != '\0'
    // we need to check:
    // - brackets balance
    // - correct using ! and ->
    int i, zero_brackets_balance[N] = {0}, zero_brackets_positions = 0;
    char *arrow = NULL, *neg = NULL, *tmp;
    
    // the simpliest cases:
    // - ""
    // - "a", "b", ..., "A", "B", ...
    // - "1", ..., "9"
    if ( !strncmp(left, "", 1) || ((int) (left - right) > 0) ||
             (left == right && (('0' <= *left && *left <= '9') ||
                                ('a' <= *left && *left <= 'z') ||
                                ('A' <= *left && *left <= 'Z')   ) ) ) {
        return (char *) "YES1";
    }

    // check brackets balance and find all positions with balance = 0
    if (strcmp(check_bracket_balance(left, right, zero_brackets_balance, &zero_brackets_positions), "YES")) {
        return (char *) "NO1";
    }

    // check correct using of ! and ->
    for (tmp = (char *) left; (neg = strchr(tmp, '!')); tmp = neg + 1) {
        if (*(neg + 1) != '(') {
	        return (char *) "NO2";
	    }
    }
    for (tmp = (char *) left; (arrow = strchr(tmp, '-')); tmp = arrow + 1) {
        if (!((int) (arrow - left))  || 
	        !((int) (right - arrow)) ||
	        *(arrow - 1) != ')'      ||
	        *(arrow + 1) != '>'      ||
	        *(arrow + 2) != '('         ) {
	        return (char *) "NO3";
	    }
    }

    // if (A == "(B)->(C)") then check(B), check(C);
    // find the last position with braket_balance = 1  <--> penult (предпоследняя) position(brack_bal = 0) + 1
    if ((i = zero_brackets_positions - 2) >= 0) {
        int pos = zero_brackets_balance[i]; // penult pos with () balance = 0
	    if (*(left + pos + 1) == '-') {
            char *check_B = NULL, *check_C = NULL;
	        check_B = check_formule_IV(left, left + pos);
            check_C = check_formule_IV(left + pos + 3, right);
            if ((strncmp(check_B, "YES", 3) == 0) &&
                (strncmp(check_C, "YES", 3) == 0)   ) {
                return (char *) "YES2";
	        }
	    }
	    return (char *) "NO4";
    }

    // A = !(B) --> check(B)
    if (*left == '!') {
        //puts("! way");
        return check_formule_IV(left + 1, right);
    }

    // A is correct formule in IV , => (A) -- correct
    // (A) --> brack_bal = 0 only at the last position
    if (zero_brackets_positions == 1) {
        // then last symbol = ')'
        return check_formule_IV(left + 1, right - 1);
    }
    return (char *) "YES";
}

int main() {
    //char s[N];
    if (fgets(s, N, stdin) != NULL) {
        // step 0: delete '\n'
        if (strchr(s, '\n')) {
            *(strchr(s, '\n')) = '\0';
	}
        puts(check_formule_IV(s, s + strlen(s) - 1));
    }
    return 0;
}

