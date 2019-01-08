#include "pch.h"
#include <intrin.h>
#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

#define N 100000

void runner() {
	double dx = 1.0 / N;
	double x = 0.0;	
	double start, finish, dif, pi;
	int  Cores = omp_get_max_threads();
	printf("%d\n", Cores);
#ifdef _OPENMP
	printf("OMP mode\n");
#else
	printf("NO OMP mode\n");
#endif
	double s = 0;
	start = omp_get_wtime();
#pragma omp parallel for reduction(+:s)
	for (int i = 0; i < N; i++)
	{
		double x = i * dx;
		s += sqrt(1 - x * x)*dx;		
	}
	pi = 4 * s;
	finish = omp_get_wtime();
	dif = finish - start;
	printf("PI in multithreading OMP mode =%f\n", pi);
	printf("Calculation time =%f\n", dif);

}

