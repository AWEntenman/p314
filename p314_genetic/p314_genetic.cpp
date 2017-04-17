// p314_genetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const int ggen_size = 10;
const int ggen_indx = 19;

struct gen314 {
	double opt;
	unsigned short xy[ggen_indx];
} ggen[ggen_size] = {
	{{ 130.11 },{ 0, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,25 }},
	{{ 132.15 },{ 0,21,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,61 }},
	{{ 132.55 },{ 0,31,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,02 }},
	{{ 132.19 },{ 0,41,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,11 }},
	{{ 132.09 },{ 0,51,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,10 }},
	{{ 132.91 },{ 0,61,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,21 }},
	{{ 132.00 },{ 0,71,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,66 }}
};

int compareD(const void *i, const void *j) {
	double a, b;
	a = * (double *) i;
	b = * (double *) j;
	return (int)(a - b);
}

int compareI(const void *i, const void *j) {
	unsigned short a, b;
	a = *(unsigned short *)i;
	b = *(unsigned short *)j;
	return (int)(a - b);
}


int main()
{
	int x1[2*ggen_indx];

	for (; ;)
	{
		//populate ggen
		int t1[ggen_indx];
		for (int j = 0; j < ggen_size; j++)
		{
			t1[0] = pr8() / 2;
			for (int i = 1; i < ggen_indx; i++)
			{
				t1[i] = pr8() + t1[i - 1];
			}
			for (int i = 0; i < ggen_indx; i++)
			{
				t1[i] = t1[i] * xyList;
				t1[i] = t1[i] / t1[ggen_indx - 1];
			}
			copy(begin(t1), end(t1), begin(ggen[j].xy));
		}

		//compute the area/perimeter ratio
		for (int i = 0; i < ggen_size; i++)
		{
			


			ggen[i].opt = sqrt(1.35)*(double)pr8();
		}
		//sort ggen
		qsort( (void *)ggen, ggen_size, sizeof(gen314), compareD);

		cout << "Finished" << endl;
	}
	return 0;

}
