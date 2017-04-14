#include "stdafx.h"

using namespace std;


int x[23]{
	0,0,0,0,0,122,133,140,145,149,153,156,162,167,174,176,180,187,190,193,197,201,208//
	//0,0,0,0,122,133,140,145,149,153,156,162,167,172,176,180,185,187,190,193,197,201,209//																			   
	//0,0,0,0,0,0,0,0,0,0,122,133,140,145,153,165,172,180,187,190,197,201,208//132.52522391637
	//0,122,133,140,145,153,156,159,162,165,170,172,174,176,178,180,182,187,190,198,202,209,209//132.51997165
	//0, 123, 134, 141, 146, 150, 157, 160, 163, 168, 175, 179, 179, 186, 186, 189, 192, 196, 200, 200, 207, 207, 207//132.52707139956
	//0, 123, 134, 141, 146, 150, 157, 160, 163, 168, 175, 177, 179, 183, 186, 189, 192, 195, 199, 199, 205, 205, 207//132.52113261
	//0,0,0,0,0,0,0,0,121, 122, 133, 140, 145, 149, 156, 162, 167, 174, 180, 187, 196, 200, 207 //132.52702504
};

int x1[46];
int x2[46];
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
		for (int i = 0; i < 23; i++)
		{
			x1[i] = x[i] + d[i];
			if (x1[i] > 250)
			{
				x1[i] = 250;
			}
			x1[45 - i] = LUT[x1[i]];
		}

		a = 0;
		for (int i = 0; i < 45; i++)
		{
			a += (x1[i + 1] - x1[i])*(x1[44 - i] + x1[45 - i]);
		}
		a /= 2;
		ll = 0;
		for (int i = 0; i < 22; i++)
		{
			ll += sqrt((x1[i + 1] - x1[i])*(x1[i + 1] - x1[i]) + (x1[44 - i] - x1[45 - i])*(x1[44 - i] - x1[45 - i]));
		}
		ll += ll + sqrt(2*(x1[23] - x1[22])*(x1[23] - x1[22]));

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
		//
		//
		for (int i = 5; i < 31; i++)
		{
			if (d[i] == 2)
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

	} while (d[23] == 0);
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
