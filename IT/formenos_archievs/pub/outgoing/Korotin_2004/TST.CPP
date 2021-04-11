#include <iostream.h>
void main(int n,char* s[])
{	cout << s[0]; int i=1;
	while(i<n)    cout << ' ' << s[i++];
	cout << '\n';
}