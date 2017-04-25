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
#define c0 2000
#define r0 0
#define s0 0
#define m0 15
#define b  161 //must be an odd number
#define m  181 // m mod 4 = 1

	static unsigned __int8 S[256];
	static unsigned __int8 r;
	static unsigned __int8 s;
	static bool started = false;

	unsigned __int8 t1;

	if (!started) {
		//initialize S using a linear congruential pseudorandom number generator
		S[0] = m0;
		for (int i = 1; i < 256; i++)
		{
			S[i] = b + m*S[i - 1];
		}
		r = r0;
		s = s0;
		//remove any initialization regularities, if any.
		for (int i = 0; i < c0; i++)
		{
			r = r + 1;
			s = s + S[r];
			t1 = S[s];
			S[s] = S[r];
			S[r] = t1;
		}
		started = true;
	}
	//compute the next PR byte using the RC4 encryption algorithm
	r = r + 1;
	s = s + S[r];
	t1 = S[s];
	S[s] = S[r];
	S[r] = t1;
	t1 += S[s];
	return S[t1];
}
