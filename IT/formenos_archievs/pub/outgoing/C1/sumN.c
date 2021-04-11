int sumN(unsigned n, ...) {
	int s = 0, **p;
	for (p = (int **)&n + 1; n > 0; n--, p++)
		s += (int)*p;
	return s;
}
