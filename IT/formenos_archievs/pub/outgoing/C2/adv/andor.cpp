#include <stdio.h>

int main(void)
<%
	char c = getchar();
	if (((c >= 'a') and (c <= 'z')) or ((c >= 'A') and (c <= 'Z')))
	<%
		printf("Literal\n");
	%>
	return 0;
%>
