//
// deterministic random bit generator (DRBG)
//
// r = 0, s = 0, s0 = 15, b = 43, m = 181
// first 10 chars; 88, 194, 163, 211, 240, 8, 37, 177, 252, 94, 183
//
#include "stdafx.h"

using namespace std;

unsigned short pr8()
{
	static unsigned short S[256];
	static unsigned short r = 0;
	static unsigned short s = 0;
	unsigned short t1;
	static bool started = false;
	const unsigned short s0 = 15;
	const unsigned short b = 43;// must be odd
	const unsigned short m = 181;// m mod 4 = 1

	if (!started) {
		//initialize S
		S[0] = s0;
		for (int i = 1; i < 256; i++)
		{
			S[i] = (b + m*S[i - 1]) & 0xff;
		}
		r = 0;
		s = 0;
		started = true;
	}
	//
	r = (r + 1) & 0xff;
	s = (s + S[r]) & 0xff;
	t1 = S[s];
	S[s] = S[r];
	S[r] = t1;
	return S[(S[r] + S[s]) & 0xff];
}
