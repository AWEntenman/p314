// p314.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
/*
int x[36]{ //132.52756044858
	000, 122, 133, 140, 145, 149, 156, 162, 162,
	167, 174, 180, 187, 193, 193, 201, 201, 208,
	000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000
};
*/
/*
int x[36]{//132.5245282500
	000, 123, 134, 140, 145, 150, 157, 160, 163,
	168, 175, 177, 184, 189, 192, 195, 199, 206,
	216, 222, 225, 227, 229, 232, 236, 237, 240,
	242, 243, 244, 246, 247, 248, 249, 250, 250
};


int x1[36];
int x2[36];
double amax = 0;

int d[36]{
	0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0
};

void incD()
{
	double a;
	double ll;
	do
	{
		for (int i = 0; i < 18; i++)
		{
			x1[i] = x[i] + d[i];
			if (x1[i] > 250)
			{
				x1[i] = 250;
			}
			x1[35 - i] = LUT[x1[i]];
		}

		a = 0;
		for (int i = 0; i < 35; i++)
		{
			a += (x1[i + 1] - x1[i])*(x1[34 - i] + x1[35 - i]);
		}
		a /= 2;
		ll = 0;
		for (int i = 0; i < 17; i++)
		{
			ll += sqrt((x1[i + 1] - x1[i])*(x1[i + 1] - x1[i]) + (x1[34 - i] - x1[35 - i])*(x1[34 - i] - x1[35 - i]));
		}
		ll += ll + sqrt((x1[18] - x1[17])*(x1[18] - x1[17]) + (x1[17] - x1[18])*(x1[17] - x1[18]));

		if (a / ll > amax)
		{
			amax = a / ll;
			cout << setprecision(14) << amax << endl;
			for (int i = 0; i < 36; i++)
			{
				x2[i] = x1[i];
				cout << x1[i] << " ";
			}
			cout << endl;
		}

		for (int i = 1; i < 19; i++)
		{
			if (d[i] == 2)
			{
				d[i] = -1;
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
	} while (d[18] != 1);
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
