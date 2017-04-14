#include "stdafx.h"
/*
using namespace std;


int x[19]{
	0, 118, 118, 118, 118, 122, 133, 140, 145, 149, 156, 162, 167, 174, 180, 187, 193, 201, 208
};

int x1[37];
int x2[37];
double amax = 0;

int d[30]{
	0,0,0,0,0, 0,0,0,0,0,
	0,0,0,0,0, 0,0,0,0,0,
	0,0,0,0,0, 0,0,0,0,0
};

void incD()
{
	double a;
	double ll;
	do
	{
		for (int i = 0; i < 19; i++)
		{
			x1[i] = x[i] + d[i];
			if (x1[i] > 250)
			{
				x1[i] = 250;
			}
			x1[37 - i] = LUT[x1[i]];
		}

		a = 0;
		for (int i = 0; i < 37; i++)
		{
			a += (x1[i + 1] - x1[i])*(x1[36 - i] + x1[37 - i]);
		}
		a /= 2;
		ll = 0;
		for (int i = 0; i < 18; i++)
		{
			ll += sqrt((x1[i + 1] - x1[i])*(x1[i + 1] - x1[i]) + (x1[36 - i] - x1[37 - i])*(x1[36 - i] - x1[37 - i]));
		}
		ll += ll + sqrt((x1[19] - x1[18])*(x1[19] - x1[18]) + (x1[18] - x1[19])*(x1[18] - x1[19]));

		if (a / ll > amax)
		{
			amax = a / ll;
			cout << setprecision(14) << amax << endl;
			for (int i = 0; i < 38; i++)
			{
				x2[i] = x1[i];
				cout << x1[i] << " ";
			}
			cout << endl;
		}
		//3^18 = 387,420,489 counts, 113.717 seconds
		//3,406,883 interations/second
		//4^18 = 68,739,476,736 counts, 19983/19812 seconds
		//
		for (int i = 6; i < 22; i++)
		{
			if (d[i] == 4)
			{
				d[i] = -2;
				break;
			}
			else if (d[i] == -1)
			{
				d[i] = 0;
			}
			else
			{
				d[i] += 1;
				break;
			}
		}

	} while (d[19] == 0);
	return;
}

int main()
{
	char ch[50];

	clock_t t;
	double timeSec;

	for (;;)
	{
		//start timing
		t = clock();
		incD();

		//stop timing
		t = clock() - t;//log current time
		timeSec = double(t) / CLOCKS_PER_SEC;
		//cout << "****** COMPUTATION READY *******\n";
		cout << "computer time = " << timeSec << " seconds" << endl;

		cout << setprecision(14) << amax << endl;

		cout << "Enter 'q' to quit, any other to continue ->";
		cin >> ch;
		cout << endl;
		if (ch[0] == 'q')
			return 0;
	}
	return 0;
}
*/