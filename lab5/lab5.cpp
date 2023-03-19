#include <iostream>
#include <omp.h>
#include <chrono>

int main()
{
	const int N = 10;
	int output = 0;
	int i = 0;
	int* a, * b;
	a = new int[N];
	b = new int[N];

	for (i = 0; i < N; i++) {
		a[i] = 2;
		b[i] = 3;
	}
#pragma omp parallel for shared(a, b, N) private(i) reduction(+:output)
	for (i = 0; i < N; i++) {
		output += a[i] * b[i];
		//std::cout << omp_get_thread_num() << std::endl;
	}

	std::cout << "output:: " << output << std::endl;

	delete[] a;
	delete[] b;
}
