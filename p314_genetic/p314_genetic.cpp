// p314_genetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const int ggen_size = 5;

struct gen314 {
	unsigned short opt;
	unsigned short xy[6][2];
} ggen[ggen_size] = {
	{ { 93 },{ { 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 } } },
	{ { 11 },{ { 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 } } },
	{ { 51 },{ { 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 } } },
	{ { 15 },{ { 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 } } },
	{ { 13 },{ { 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 },{ 1,2 } } }
};



int compare(const void *i, const void *j) {
	short a;
	short b;

	a = * (short *) i;
	b = * (short *) j;
	return a - b;
}


int main()
{
	unsigned short n;
	
	for (; ;)
	{
		cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < ggen_size; i++)
			ggen[i].opt = pr8();
		qsort( (void *)ggen, ggen_size, sizeof(gen314), compare);
		cout << "Finished" << endl;
	}
	return 0;

}
