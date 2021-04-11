extern int puts(const char *s);

int check(char *pass);
int bruteforce(char *s, unsigned n) {
 int i = 0;
 char c;
 for (c = ' '; c <= '~'; c++) {
  for (i = 0; i < 6; i++)
   s[i] = c;
  s[i] = '\0';
  if (check(s))
   return 1;
 }
 return 0;
}
int main(void) {
 char buf[6 +1];
 if (bruteforce(buf, sizeof buf))
  puts(buf);
 return 0;
}
