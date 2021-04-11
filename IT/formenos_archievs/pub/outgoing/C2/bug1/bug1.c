#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *hFile;
  char *user_pass;
  char *real_pass;
  user_pass = (char*) malloc(100);
  real_pass = (char*) malloc(100);

  hFile = fopen("pass.txt", "r");
  fgets(real_pass, 100, hFile);
  
  printf("Enter Your Password: ");
  fgets(user_pass, 100, stdin);
  if (strcmp(user_pass, real_pass))
  {
    printf("Invalid password: ");
    printf(user_pass);
  } else
    printf("Password ok\n");

  fclose(hFile);
  free(real_pass);
  free(user_pass);
  return 0;
}
