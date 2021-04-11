#include "pascal.h"

program g2;

Var
	Array of Integer A[238][238];

Integer function q(Integer n, Integer k)
Begin
var
	Integer i, res = 0;

	if n == 0 or k == 0 then
		exit 0;
	if k > n then
		k = n;
	if A[n][k] >= 0 then
		exit A[n][k];
	if k == n then
	begin
		res++;
	end;
	for i = k to i > 0 ; i-- do
		res += q(n - i, i - 1);
	A[n][k] = res;
	exit res;
End;

BEGIN
VAR
	Integer i, j, n;
/*	string s;
	Real f1 = 1.3, f2 = 1.5, f3 = 1.7, f4 = -1.3, f5 = -1.5, f6 = -1.7, f7 = 0;*/

	For i = 0 To i < 238 ; i++ Do
		for j = 0 to j < 238 ; j++ do
		begin
			A[i][j] = -1;
		end;
//	repeat
		Read("%d", &n);
//	until (n != 0);

/*	// Tests
	Str(n, s);
	WriteLn(s);
	Write("Pos: %d\n", Pos("5", s));
	Val(s, i, 0);
	Write("%d * %d = %d\n", i, i, Sqr(i));
	Write("Round: %d, %d, %d, %d, %d, %d, %d\n", Round(f1), Round(f2), Round(f3), Round(f4), Round(f5), Round(f6), Round(f7));
	Write("Trunc: %d, %d, %d, %d, %d, %d, %d\n", Trunc(f1), Trunc(f2), Trunc(f3), Trunc(f4), Trunc(f5), Trunc(f6), Trunc(f7));
	*/

	Write("%d\n", q(n, n));
END
