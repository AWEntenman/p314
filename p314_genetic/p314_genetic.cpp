// p314_genetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const int ggen_size = 30000;
const int ggen_indx = 19;

struct gen314 {
	double opt;
	unsigned short xy[ggen_indx];
} ggen[ggen_size] = {
	{{ 130.11 },{ 0, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 }},
	{{ 132.15 },{ 0,21,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,61 }},
	{{ 132.55 },{ 0,31,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,02 }},
	{{ 132.19 },{ 0,41,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,11 }},
	{{ 132.09 },{ 0,51,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,10 }},
	{{ 132.91 },{ 0,61,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,21 }},
	{{ 132.00 },{ 0,71,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,66 }}
};

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
	for (; ;)
	{
		//compute the area/perimeter ratio for all edges
		for (int i = 0; i < ggen_size; i++)
		{
			//populate ggen
			int t1[ggen_indx];
			for (int j = 0; j < ggen_size; j++)
			{
				//t1[0] = pr8() / 2;
				for (int k = 0; k < 7; k++)
				{
					t1[k] = pr8()/3 + t1[k - 1];
				}
				for (int k = 7; k < ggen_indx; k++)
				{
					t1[k] = pr8() + t1[k - 1];
				}
				for (int k = 0; k < ggen_indx; k++)
				{
					t1[k] = t1[k] * (xyList - 1);
					t1[k] = t1[k] / t1[ggen_indx - 1];
				}
			}
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
			double a = 0;
			for (int j = 0; j < 2*ggen_indx-2; j++)
			{
				a += (t2[j + 1] - t2[j])*(t2[2*ggen_indx-1-j] + t2[2*ggen_indx-2-j]);
			}
			a /= 2;
			double ll = 0;
			for (int j = 0; j < ggen_indx-1; j++)
			{
				ll += sqrt((t2[j + 1] - t2[j])*(t2[j + 1] - t2[j])
					+ (t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j])*(t2[2 * ggen_indx - 1 - j] - t2[2 * ggen_indx - 2 - j]));
			}
			ll += ll;
			ll += sqrt(2 * (t2[ggen_indx] - t2[ggen_indx - 1])*(t2[ggen_indx] - t2[ggen_indx - 1]));
			//store the objective function
			ggen[i].opt=a/ll;
		}
		//sort ggen
		qsort((void *)ggen, ggen_size, sizeof(gen314), compareD);

		cout << setprecision(12) << ggen[0].opt << " Finished" << endl;
	}
	return 0;

}
