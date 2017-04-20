/*
Leefter Yao and William A.Sethares;
Nonlinear Parameter Estimation via the Genetic Algorithm
IEEE Transactions on Signal Processing, vol 42, no. 42, April 1994}
*/

#include "stdafx.h"

using namespace std;

#define N         250  //Size of gene pool
#define D         60   //Number of parents
#define Le        15   //Number of generations with no improvement for extinction
#define Lt        100  //Number of generations for convergence
#define Pm        0.01 //Probability of a mutation
#define rho       30   //Number of parents kept for the next generation
#define ggen_size N    //
#define ggen_indx 19   //
double maxSo = 132.520;

struct gen314 {
	double opt;
	unsigned short xy[ggen_indx];
} ggen[ggen_size]{}, tgen[ggen_size]{};

int compareD(const void *i, const void *j) {
	double a, b;
	a = *(double *)i;
	b = *(double *)j;
	if (a>=b)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int compareI(const void *i, const void *j) {
	unsigned short a, b;
	a = *(unsigned short *)i;
	b = *(unsigned short *)j;
	return (int)(a - b);
}

int main()
{
	//srand(12345);
	for (; ;)
	{
		//compute the area/perimeter ratio for all edges
		for (int i = 0; i < ggen_size; i++)
		{
			//populate ggen
			int t1[ggen_indx];
			for (int j = 0; j < ggen_size; j++)
			{
				t1[0] = pr8() / 4;
				//t1[0] = rand() / 4;
				for (int k = 1; k < 7; k++)
				{
					t1[k] = pr8() / 2 + t1[k - 1];
					//t1[k] = rand() / 2 + t1[k - 1];
				}
				for (int k = 7; k < ggen_indx; k++)
				{
					t1[k] = pr8() + t1[k - 1];
					//t1[k] = rand() + t1[k - 1];
				}
				for (int k = 0; k < ggen_indx; k++)
				{
					t1[k] = t1[k] * (xyList - 1);
					t1[k] = t1[k] / t1[ggen_indx - 1];
				}
			}
			//qsort((void *)t1, ggen_indx-1, sizeof(int), compareI);
			copy(begin(t1), end(t1), begin(ggen[i].xy));
			//Build the coefficient list
			int t2[2 * ggen_indx];
			for (int j = 1; j < ggen_indx; j++)
			{
				t2[j] = xy[t1[j-1]][0];
				t2[2 * ggen_indx - 1 - j] = xy[t1[j-1]][1];
			}
			t2[0] = 0;
			t2[2 * ggen_indx - 2] = 250;
			t2[2 * ggen_indx - 1] = 250;
			//compute the objective function
			//  compute the area
			double a = 0;
			for (int j = 0; j < 2*ggen_indx-2; j++)
			{
				a += (t2[j + 1] - t2[j])*(t2[2*ggen_indx-1-j] + t2[2*ggen_indx-2-j]);
			}
			a /= 2;
			//  compute the length
			double ll = 0;
			for (int j = 0; j < ggen_indx-1; j++)
			{
				ll += sqrt((t2[j + 1] - t2[j])*(t2[j + 1] - t2[j])
					+ (t2[2*ggen_indx - 1 - j] - t2[2*ggen_indx - 2 - j])*(t2[2*ggen_indx - 1 - j] - t2[2*ggen_indx - 2 - j]));
			}
			ll += ll;
			ll += sqrt(2 * (t2[ggen_indx] - t2[ggen_indx - 1])*(t2[ggen_indx] - t2[ggen_indx - 1]));
			//store the objective function
			ggen[i].opt=a/ll;
		}
		//sort ggen
		qsort((void *)ggen, ggen_size, sizeof(gen314), compareD);

		//Build the next generation from D parents,
		// keep rho parents.
		for (int i = 0; i < rho; i++)
		{
			tgen[i] = ggen[i];
		}
		// Mate D parents to create D - rho children
		for (int i = rho; i < ggen_size; i+2)
		{
			tgen[i] = ggen[r];


			qsort((void *)tgen[i].xy, ggen_indx - 1, sizeof(int), compareI);




			tgen[i + 1] = ggen[s];
			qsort((void *)tgen[i+1].xy, ggen_indx - 1, sizeof(int), compareI);
		}
		
		






		copy(begin(tgen), end(tgen), begin(ggen));

		//Display ggen
		if (ggen[0].opt > maxSo)
		{
			maxSo = ggen[0].opt;
			for (int k = 0; k < ggen_indx - 1; k++)
			{
				cout << setw(2) << ggen[0].xy[k] << ", ";
			}
			cout << setprecision(12) << ggen[0].opt << endl;
		}
	}
	return 0;

}
