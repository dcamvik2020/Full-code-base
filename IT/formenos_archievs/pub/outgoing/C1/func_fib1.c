unsigned int fib(unsigned int n) {
	unsigned f1, f2, tmp;
	f1 = 0; f2 = 1;
	for ( ; n > 0; n--) {
		tmp = f1 + f2;
		f1 = f2;
		f2 = tmp;
	}
	return f1;
}
