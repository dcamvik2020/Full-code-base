#include <stdio.h>
#include <limits.h>

#include <string.h>

void printBinaryFromFloat (float x);

// 7) experiment
typedef union {
  unsigned u;
  float f;
} bit_float_t;

float bit2float (unsigned u) {
  bit_float_t arg;
  arg.u = u;
  return arg.f;
}


int main () {
  // 1)
  //int x = INT_MIN + 1;
  //printf("x = %d, 2x = %d, ", x, 2 * x);
  //printf("x-2 = %d\n", x - 2);
  
  // 2)
  //x = 1000000;
  // printf("x = %d, x^2 = %d\n", x, x*x);

  /// -1 in bit form: 1111..1111 (n bits)
  /// that's why unsigned(-1) is very big

  //printf("%d\n", (x|-x)>>31);  // == -1 ??? always ? int, unsigned
  
  //float x = 0.0, y = 0.0;
  //printf("%f\n", x / y);

  /* 3)
  float test = 4.7567;
  char result[sizeof(float)];
  memcpy(result, &test, sizeof(test));
    // now result is storing the float,
    // but you can treat it as an array of
    // arbitrary chars
 
    //for example:
  
  for (unsigned n = 0; n < sizeof(float); ++n)
    printf("%x", result[n]);
  printf("\n");
  */

  // 4)
  //printf("%d %d\n", (int)1.4, (int)1.50);

  // 5)
  // float convertion :
  //int x = INT_MIN + 1;
  /*
  int x = 0;
  for ( ; x != INT_MAX; ++x) {     // all x < 0 ... bad conversion
    if (x != (int)((float)x)) {
      printf("x = %d\n", x);
	  //break;
	}
  }
  */

  // 6)
  //printf("sizeof(long double)=%ld\n", sizeof (long double)); // 16

  // 7)
  unsigned u = 5;
  float converted = (float)u;
  float from_func = bit2float(u);
  printf("converted = %lf\nfrom_func = %lf\n",
         converted, from_func);
  return 0;
}

/*
$ gcc -Wall -Wextra -Werror -g experiments.c -c
$ objdump -d experiments.o

experiments.o:     формат файла elf64-x86-64


Дизассемблирование раздела .text:

0000000000000000 <main>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  13:	eb 28                	jmp    3d <main+0x3d>
  15:	f3 0f 2a 45 fc       	cvtsi2ssl -0x4(%rbp),%xmm0
  1a:	f3 0f 2c c0          	cvttss2si %xmm0,%eax
  1e:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  21:	74 16                	je     39 <main+0x39>
  23:	8b 45 fc             	mov    -0x4(%rbp),%eax
  26:	89 c6                	mov    %eax,%esi
  28:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 2f <main+0x2f>
  2f:	b8 00 00 00 00       	mov    $0x0,%eax
  34:	e8 00 00 00 00       	callq  39 <main+0x39>
  39:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  3d:	81 7d fc ff ff ff 7f 	cmpl   $0x7fffffff,-0x4(%rbp)
  44:	75 cf                	jne    15 <main+0x15>
  46:	b8 00 00 00 00       	mov    $0x0,%eax
  4b:	c9                   	leaveq 
  4c:	c3                   	retq   
*/
