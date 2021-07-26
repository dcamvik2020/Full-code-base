#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return strcmp(*(const char**) a, *(const char**) b);
}

int main(void)
{
    unsigned i, N, l;
    char **s = NULL, buf[1025] = {0};//, *p = NULL;
    FILE *input = NULL, *output = NULL;
    if ((input = fopen("input.txt", "rt")) != NULL)
    {
        if ((output = fopen("output.txt", "wt")) != NULL)
        {
            ///create an array of pointers and read words
            fscanf(input, "%u", &N);               /// fscanf doesn't read '\n'
			if (!fgets(buf, sizeof buf, input))    /// --> need fgets for it
				buf[0] = '\0';                     /// it's a trash, for '\n' only
            s = (char**) malloc(N*sizeof(char*));
            for (i = 0; i < N; i++)
            {
                if (!fgets(buf, sizeof buf, input))
                    buf[0] = '\0';
                ///fgets(buf, 1024, input); ///1024 is incorrect
                //printf("last = %d  , len =  %d   ", buf[strlen(buf)], strlen(buf));
                //puts(buf);
                ///if (p = strrchr(buf, '\n'))   ///  it is very
                ///    *p = 0;                   ///  unsafely
                l = strlen(buf);
                if (l > 0 && buf[l-1] == '\n')   /// it is better
                    buf[l-1] = '\0';             ///
                ///s[i] = (char*) malloc(strlen(buf) + 1);
                ///strcpy(s[i], buf);
                s[i] = strdup(buf); /// 2 last actions in shorter form
            }
            ///sort the array
            qsort(s, N, sizeof(char*), cmp);
            ///print sorted array into output.txt
            for (i = 0; i < N; i++)
            {
                fprintf(output, "%s\n", s[i]);
                free(s[i]);
            }
            free(s);
            fclose(output);
        }
        else
            perror("fopen(output.txt)");
        fclose(input);
    }
    else
        perror("fopen(input.txt)");
    return 0;
}
