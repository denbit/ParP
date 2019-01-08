#include "pch.h"
#include <math.h>
#include <stdio.h>
#include <omp.h>
#include <intrin.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#define N 100000



struct task {
	double step;
	int from;
	int to;
	double res;
};


DWORD WINAPI ThreadFunc(PVOID point)
{
	task* task_unit = (task*)point;
	double s = 0, x, dx;
	dx = task_unit->step;

	for (int i = task_unit->from; i < task_unit->to; i++)
	{
		x = i * dx;
		s += sqrt(1 - x * x)*dx;
	}
	task_unit->res = s;
	return 0;
}

void runner_api() {
	double dx = 1.0 / N;
	double x = 0.0;
	double s = 0.0;	
	double start, finish, dif, pi;
	int mas[4];
	int Cores=omp_get_max_threads();
	printf(" Number of Cores is %d\n", Cores);
	s = 0;
	int Theads = Cores;
	HANDLE* ph = new HANDLE[Theads];
	DWORD* pid = new DWORD[Theads];
	task* pt = new task[Theads];

	start = omp_get_wtime();
	int amount = N / Theads;
	for (int i = 0; i < Theads; i++)
	{
		(pt + i)->res = 0.0;
		(pt + i)->step = 1.0 / N;		
		(pt + i)->from = i * amount;
		(pt + i)->to = (pt + i)->from + amount;
		*(ph + i) = CreateThread(0, 0, ThreadFunc, (task*)pt + i, 0, pid + i);
	}
	WaitForMultipleObjects(Theads, ph, true, INFINITE);
	for (int i = 0; i < Theads; i++)
	{
		CloseHandle(ph[i]);
		s += (pt + i)->res;
	}
	pi = 4 * s;
	finish = omp_get_wtime();
	dif = finish - start;
	printf("PI in multithreading mode WIN API  mode =%f\n", pi);
	printf("Calculation time =%f\n", dif);
	delete[] ph,pid,pt;	
}


