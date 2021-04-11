#ifndef PASCAL_H_
#define PASCAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define begin {
#define BEGIN int main(void) {

#define end }
#define END return 0; }

typedef int boolean, Boolean, BOOLEAN; // FIXME: or char / signed char / unsigned char ??

#define false 0
#define true 1

typedef char Char, CHAR;
typedef char *pchar, *PChar, *PCHAR;
typedef signed char shortint, Shortint, ShortInt, SHORTINT;
typedef unsigned char byte, Byte, BYTE;
typedef short int smallint, Smallint, SmallInt, SMALLINT; // FIXME: confusing "short int" and "shortint" - should be it the same?
typedef unsigned short int word, Word, WORD;
typedef int integer, Integer, INTEGER;
typedef unsigned int cardinal, Cardinal, CARDINAL;
typedef long int longint, Longint, LongInt, LONGINT;
typedef unsigned long int longword, Longword, LongWord, LONGWORD;
typedef long long int int64, Int64, INT64;
typedef float single, Single, SINGLE;
typedef double real, Real, REAL; // FIXME: well, this is not perfect match
typedef double Double, DOUBLE;
typedef long double extended, Extended, EXTENDED;
typedef char shortstring[256], Shortstring[256], ShortString[256], SHORTSTRING[256];
typedef ShortString string, String, STRING; // FIXME: this is also some cheat
typedef void *pointer, *Pointer, *POINTER;

#define nil NULL

#define type typedef

#define record struct

#define array
#define of

#define var

#define not !
//#define not ~    // FIXME: Confusing! "Not" may be bitwise operator as well as logic
#define and &&
//#define and &    // FIXME: Confusing! "And" may be bitwise operator as well as logic
#define or ||
//#define or |    // FIXME: Confusing! "Or" may be bitwise operator as well as logic

#define xor ^
#define shl <<
#define shr >>

#define inc ++
#define dec --

#define div /
#define mod %

//NOTE: this discards C-style "if" !
#define if if (
#define then )
#define Else else

//NOTE: this discards C-style "while" !
#define while while (
//NOTE: this discards C-style "do - while" !
#define do )

//NOTE: this discards C-style "for" !
#define for for (
#define to ;
#define downto ;

//FIXME: to make "repeat" working, comment out "#define do )" and change to "#define Do )", "#define DO )"
#define repeat do
//NOTE: it's a pity, but "until" must go with "( )"
#define until(x) while !(x) )

#define function
#define procedure void

#define exit return
#define halt _exit(-1)

#define forward

typedef int program, Program, PROGRAM;
typedef int library, Library, LIBRARY;
typedef int unit, Unit, UNIT;
#define interface
#define implementation

// I/O
// This is subject to change

#define read scanf
//#define readln read
#define readln gets

#define write printf
//#define writeln write
#define writeln puts

// strings

#define chr
#define ord

#define length strlen

#define pos(t, s) (strstr((s), (t)) - (s) + 1)
//#define pos(c, s) (strchr(s, c) + 1)    // for char's

//#define str(i, s) itoa(i, s, 10)
#define str(i, s) sprintf(s, "%d", i)
#define val(s, i, j) (i = atoi(s))

// math

#define sqr(x) ((x) * (x))

#define ln log

#define arctan atan

#define pi M_PI

#define round(x) ((int) ((x) + ((x) > 0 ? 0.5 : -0.5)))
#define trunc(x) ((int) (x))

#include "pascapital.h"

#endif /* PASCAL_H_ */
