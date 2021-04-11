#include <unistd.h>

char buf[10];
ssize_t len;

int main(void)
{
	len = read(0, buf, sizeof buf);
	write(1, buf, len);
	return 0;
}
