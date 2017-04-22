/*
Leefter Yao and William A.Sethares;
Nonlinear Parameter Estimation via the Genetic Algorithm
IEEE Transactions on Signal Processing, vol 42, no. 42, April 1994}
*/

#include "stdafx.h"

using namespace std;

#define N         1000  //Size of gene pool
#define D         60   //Number of parents
#define Le        15   //Number of generations with no improvement for extinction
#define Lt        100  //Number of generations for convergence
#define Pm        4    //Probability / 256 of a mutation
#define rho       30   //Number of parents kept for the next generation
#define ggen_size N    //
#define ggen_indx 19   //
double maxSo = 132.20;

struct gen314 {
	double opt;
	unsigned short xy[ggen_indx];
} ggen[ggen_size]{}, tgen[D]{};

int compareD(const void *i, const void *j) {
	double a, b;
	a = *(double *)i;
	b = *(double *)j;
	if (a < b)
	{
		return 1;
	}
	else if (a == b)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int compareI(const void *i, const void *j) {
	unsigned short a, b;
	a = *(unsigned short *)i;
	b = *(unsigned short *)j;
	if (a > b)
	{
		return 1;
	}
	else if (a == b)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int main()
{
	// *********************************************************************************
	//
	// Create the initial population
	//
	// *********************************************************************************
	for (int i = 0; i < ggen_size; i++)
	{
		int t1[ggen_indx];
		int t2[2 * ggen_indx];
		double a = 0;
		double ll = 0;
		//srand(12345);
		//populate ggen
		{
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
			copy(begin(t1), end(t1), begin(ggen[i].xy));
		}
		//Build the coefficient list
		{
			for (int j = 1; j < ggen_indx; j++)
			{
				t2[j] = xy[t1[j - 1]][0];
				t2[2 * ggen_indx - 1 - j] = xy[t1[j - 1]][1];
			}
			t2[0] = 0;
			t2[2 * ggen_indx - 2] = 250;
			t2[2 * ggen_indx - 1] = 250;
		}//compute the objective function
		 //  compute the area
		{
			for (int j = 0; j < 2 * ggen_indx - 2; j++)
			{
				a += (t2[j + 1] - t2[j])*(t2[2 * ggen_indx - 1 - j] + t2[2 * ggen_indx - 2 - j]);
			}
			a /= 2;
		}
		//  compute the length
		{
			for (int j = 0; j < ggen_indx - 1; j++)
			{
				ll += sqrt((t2[j + 1] - t2[j])*(t2[j + 1] - t2[j])
					+ (t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j])*(t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j]));
			}
			ll += ll;
			ll += sqrt(2 * (t2[ggen_indx] - t2[ggen_indx - 1])*(t2[ggen_indx] - t2[ggen_indx - 1]));
		}
		//store the objective function
		ggen[i].opt = a / ll;
	}
	//sort ggen
	qsort((void *)ggen, ggen_size, sizeof(gen314), compareD);


	for (; ;)
	{
		// *********************************************************************************
		//
		// The main iterative loop here.
		//
		// *********************************************************************************
		int k_loop = 0; //counter to check for no improvement in 1 generation
		int m_loop = 0; //counter to check if a solution has been found.

		//Build the next generation from D parents,
		// copy best D parents to tgenn for mating
		for (int i = 0; i < D; i++)
		{
			tgen[i] = ggen[i];
		}
		// Mate D parents to create (N - D + rho) children
		// keep rho parents.
		for (int i = rho; i < ggen_size; i += 2)
		{
			//Place 2 children into ggen from 2 parents in tgen
			//Use crossover and mutation
			int r, s, t;
			//make 2 vars 0 <= r,s < D to pick 2 parents
			r = D*pr8() >> 8;
			s = D*pr8() >> 8;
			//make crossover point
			t = (ggen_indx - 1)*pr8() >> 8;
			for (int j = 0; j < t; j++)
			{
				ggen[i].xy[j] = tgen[r].xy[j];
				if (pr8() < Pm)
				{
					short g = pr8();
					if (g < 64)
					{
						g = tgen[r].xy[j] + 1;
					}
					else if (g < 128)
					{
						g = tgen[r].xy[j] + 2;
					}
					else if (g < 192)
					{
						g = tgen[r].xy[j] - 1;
					}
					else
					{
						g = tgen[r].xy[j] - 2;
					}
					if ((g < ggen_indx) && (g >= 0))
					{
						ggen[i].xy[j] = g;
					}
				}
				ggen[i + 1].xy[j] = tgen[s].xy[j];
				if (pr8() < Pm)
				{
					short g = pr8();
					if (g < 64)
					{
						g = tgen[s].xy[j] + 1;
					}
					else if (g < 128)
					{
						g = tgen[s].xy[j] + 2;
					}
					else if (g < 192)
					{
						g = tgen[s].xy[j] - 1;
					}
					else
					{
						g = tgen[s].xy[j] - 2;
					}
					if ((g < ggen_indx) && (g >= 0))
					{
						ggen[i + 1].xy[j] = g;
					}
				}
			}

			for (int j = t; j < ggen_indx; j++)
			{
				ggen[i].xy[j] = tgen[s].xy[j];
				if (pr8() < Pm)
				{
					short g = pr8();
					if (g < 64)
					{
						g = tgen[s].xy[j] + 1;
					}
					else if (g < 128)
					{
						g = tgen[s].xy[j] + 2;
					}
					else if (g < 192)
					{
						g = tgen[s].xy[j] - 1;
					}
					else
					{
						g = tgen[s].xy[j] - 2;
					}
					if ((g < ggen_indx) && (g >= 0))
					{
						ggen[i].xy[j] = g;
					}
				}
				ggen[i + 1].xy[j] = tgen[r].xy[j];
				if (pr8() < Pm)
				{
					short g = pr8();
					if (g < 64)
					{
						g = tgen[r].xy[j] + 1;
					}
					else if (g < 128)
					{
						g = tgen[r].xy[j] + 2;
					}
					else if (g < 192)
					{
						g = tgen[r].xy[j] - 1;
					}
					else
					{
						g = tgen[r].xy[j] - 2;
					}
					if ((g < ggen_indx) && (g >= 0))
					{
						ggen[i].xy[j] = g;
					}
				}
			}
			qsort((void *)ggen[i].xy, ggen_indx - 1, sizeof(unsigned short), compareI);
			qsort((void *)ggen[i + 1].xy, ggen_indx - 1, sizeof(unsigned short), compareI);
			// *******************************************************************************
			//
			//compute area/perimeter ratio for ggen[i].opt
			//
			// *******************************************************************************
			//Build the coefficient list
			int t2[2 * ggen_indx];
			for (int j = 1; j < ggen_indx; j++)
			{
				t2[j] = xy[ggen[i].xy[j - 1]][0];
				t2[2 * ggen_indx - 1 - j] = xy[ggen[i].xy[j - 1]][1];
			}
			t2[0] = 0;
			t2[2 * ggen_indx - 2] = 250;
			t2[2 * ggen_indx - 1] = 250;
			//compute the objective function
			//  compute the area
			double a = 0;
			for (int j = 0; j < 2 * ggen_indx - 2; j++)
			{
				a += (t2[j + 1] - t2[j])*(t2[2 * ggen_indx - 1 - j] + t2[2 * ggen_indx - 2 - j]);
			}
			a /= 2;
			//  compute the length
			double ll = 0;
			for (int j = 0; j < ggen_indx - 1; j++)
			{
				ll += sqrt((t2[j + 1] - t2[j])*(t2[j + 1] - t2[j])
					+ (t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j])*(t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j]));
			}
			ll += ll;
			ll += sqrt(2 * (t2[ggen_indx] - t2[ggen_indx - 1])*(t2[ggen_indx] - t2[ggen_indx - 1]));
			//store the objective function
			ggen[i].opt = a / ll;
			// *******************************************************************************
			//
			//compute area/perimeter ratio for ggen[i+1].opt
			//
			// *******************************************************************************
			//Build the coefficient list
			for (int j = 1; j < ggen_indx; j++)
			{
				t2[j] = xy[ggen[i + 1].xy[j - 1]][0];
				t2[2 * ggen_indx - 1 - j] = xy[ggen[i + 1].xy[j - 1]][1];
			}
			t2[0] = 0;
			t2[2 * ggen_indx - 2] = 250;
			t2[2 * ggen_indx - 1] = 250;
			//compute the objective function
			//  compute the area
			a = 0;
			for (int j = 0; j < 2 * ggen_indx - 2; j++)
			{
				a += (t2[j + 1] - t2[j])*(t2[2 * ggen_indx - 1 - j] + t2[2 * ggen_indx - 2 - j]);
			}
			a /= 2;
			//  compute the length
			ll = 0;
			for (int j = 0; j < ggen_indx - 1; j++)
			{
				ll += sqrt((t2[j + 1] - t2[j])*(t2[j + 1] - t2[j])
					+ (t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j])*(t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j]));
			}
			ll += ll;
			ll += sqrt(2 * (t2[ggen_indx] - t2[ggen_indx - 1])*(t2[ggen_indx] - t2[ggen_indx - 1]));
			//store the objective function
			ggen[i + 1].opt = a / ll;
		}
		// quick sort the next generation
		qsort((void *)ggen, ggen_size, sizeof(gen314), compareD);

		if (ggen[0].opt == ggen[ggen_size-1].opt)
		{
			for (int i = 2; i < ggen_size; i++)
			{
				int t1[ggen_indx];
				int t2[2 * ggen_indx];
				double a = 0;
				double ll = 0;
				//srand(12345);
				//populate ggen
				{
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
					copy(begin(t1), end(t1), begin(ggen[i].xy));
				}
				//Build the coefficient list
				{
					for (int j = 1; j < ggen_indx; j++)
					{
						t2[j] = xy[t1[j - 1]][0];
						t2[2 * ggen_indx - 1 - j] = xy[t1[j - 1]][1];
					}
					t2[0] = 0;
					t2[2 * ggen_indx - 2] = 250;
					t2[2 * ggen_indx - 1] = 250;
				}//compute the objective function
				 //  compute the area
				{
					for (int j = 0; j < 2 * ggen_indx - 2; j++)
					{
						a += (t2[j + 1] - t2[j])*(t2[2 * ggen_indx - 1 - j] + t2[2 * ggen_indx - 2 - j]);
					}
					a /= 2;
				}
				//  compute the length
				{
					for (int j = 0; j < ggen_indx - 1; j++)
					{
						ll += sqrt((t2[j + 1] - t2[j])*(t2[j + 1] - t2[j])
							+ (t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j])*(t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j]));
					}
					ll += ll;
					ll += sqrt(2 * (t2[ggen_indx] - t2[ggen_indx - 1])*(t2[ggen_indx] - t2[ggen_indx - 1]));
				}
				//store the objective function
				ggen[i].opt = a / ll;
			}
			qsort((void *)ggen, ggen_size, sizeof(gen314), compareD);
		}

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
