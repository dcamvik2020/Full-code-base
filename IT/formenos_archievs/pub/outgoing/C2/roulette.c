#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *spisok[] = {"example", "Ablov", "Alekseev", "Alfimov",
                  "Bityutskiy", "Burovin", "Vashchilko", "Zhelezniak",
                  "Melnikov", "Mironov", "Natalchenko", "Pavlivskiy",
                  "Penkin", "Tarasov", "Fedin"};

unsigned tasks[15][3];

unsigned check_dup(unsigned idx)
{
  unsigned i;
  for (i = 0; i < idx; i++)
//    if (tasks[i] == tasks[idx]) // wrong !!!
    if ((tasks[i][0] == tasks[idx][0] && tasks[i][1] == tasks[idx][1]) ||
        (tasks[i][1] == tasks[idx][1] && tasks[i][2] == tasks[idx][2]) ||
        (tasks[i][2] == tasks[idx][2] && tasks[i][0] == tasks[idx][0]))
      return i + 1;
  return 0;
}

//is this task assigned to anybody?
unsigned check_mis(unsigned task, unsigned val)
{
  unsigned i;
  for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    if (tasks[i][task] == val)
      return i + 1;
  return 0;
}

int main(void)
{
  unsigned i, flag;
  srand((unsigned)time(NULL));
/*  for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    printf("%u) %s: %u-%u-%u\n", i, spisok[i], rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1);*/
  do
  {
    flag = 0;
    for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    {
      tasks[i][0] = 1 + (unsigned) (6 * (rand() / (RAND_MAX + 1.0)));
      tasks[i][1] = 1 + (unsigned) (6 * (rand() / (RAND_MAX + 1.0)));
      tasks[i][2] = 1 + (unsigned) (6 * (rand() / (RAND_MAX + 1.0)));
      if (check_dup(i))
        i--;
    }

    //fix the situation, when there is variants assigned to nobody
    for (i = 1; i <= 6; i++)
      if (!check_mis(0, i) || !check_mis(1, i) || !check_mis(2, i))
        flag = 1;
  } while (flag);

  for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    printf("%2u) %-13s: %u-%u-%u\n", i, spisok[i], tasks[i][0], tasks[i][1], tasks[i][2]);
  return 0;
}
