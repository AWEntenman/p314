#include "stdafx.h"

using namespace std;
/*
int x[30]{ //132.52756425686
	0, 122, 133, 140, 145, 149, 156, 162, 167, 174,
	180, 187, 193, 201, 208, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int x1[30];
int x2[30];
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
		for (int i = 0; i < 15; i++)
		{
			x1[i] = x[i] + d[i];
			if (x1[i] > 250)
			{
				x1[i] = 250;
			}
			x1[29 - i] = LUT[x1[i]];
		}

		a = 0;
		for (int i = 0; i < 29; i++)
		{
			a += (x1[i + 1] - x1[i])*(x1[28 - i] + x1[29 - i]);
		}
		a /= 2;
		ll = 0;
		for (int i = 0; i < 14; i++)
		{
			ll += sqrt((x1[i + 1] - x1[i])*(x1[i + 1] - x1[i]) + (x1[28 - i] - x1[29 - i])*(x1[28 - i] - x1[29 - i]));
		}
		ll += ll + sqrt((x1[15] - x1[14])*(x1[15] - x1[14]) + (x1[14] - x1[15])*(x1[14] - x1[15]));

		if (a / ll > amax)
		{
			amax = a / ll;
			cout << setprecision(14) << amax << endl;
			for (int i = 0; i < 30; i++)
			{
				x2[i] = x1[i];
				cout << x1[i] << " ";
			}
			cout << endl;
		}
		//5^14 = 6,103,515,625 counts, 1413.924 seconds
		//4,316,721 interations/second
		for (int i = 1; i < 22; i++)
		{
			if (d[i] == 2)
			{
				d[i] = -2;
				break;
			}
			else if (d[i]==-1)
			{
				d[i] = 0;
			}
			else
			{
				d[i] += 1;
				break;
			}
		}

	} while (d[15] != 1);
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