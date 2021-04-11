#include <unistd.h>

int main(void)
{
	write(1, "Hell, Word!\n", 12);
	return 0;
}
