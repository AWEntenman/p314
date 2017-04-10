#include "stdafx.h"

using namespace std;


int LUT[220]{
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
	250, 250, 250, 250, 250, 250, 250, 250, 250, 249,
	249, 249, 249, 249, 249, 249, 249, 249, 248, 248,
	248, 248, 248, 248, 247, 247, 247, 247, 246, 246,
	246, 246, 245, 245, 245, 245, 244, 244, 244, 243,
	243, 243, 242, 242, 242, 241, 241, 240, 240, 240,
	239, 239, 238, 238, 237, 237, 236, 236, 235, 235,
	234, 234, 233, 233, 232, 232, 231, 230, 230, 229,
	228, 228, 227, 226, 226, 225, 224, 223, 223, 222,
	221, 220, 220, 219, 218, 217, 216, 215, 214, 213,
	212, 211, 210, 209, 208, 207, 206, 205, 204, 203
};

int x[19]{
	0, 120, 133, 140, 146, 154, 160, 163, 168, 171,
	173, 177, 184, 189, 192, 195, 199, 204, 208
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
		for (int i = 1; i < 22; i++)
		{
			if (d[i] == 1)
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
