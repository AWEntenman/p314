// stdafx.cpp : source file that includes just the standard includes
// p314_genetic.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

/* crt_qsort.c
// arguments: every good boy deserves favor

// This program reads the command-line
* parameters and uses qsort to sort them. It
* then displays the sorted arguments.


int compare(const void *arg1, const void *arg2);

int main(int argc, char **argv)
{
int i;
//Eliminate argv[0] from sort:
argv++;
argc--;

// Sort remaining args using Quicksort algorithm:
qsort((void *)argv, (size_t)argc, sizeof(char *), compare);

// Output sorted list:
for (i = 0; i < argc; ++i)
printf(" %s", argv[i]);
printf("\n");
}

int compare(const void *arg1, const void *arg2)
{
// Compare all of both strings:
return _stricmp(*(char**)arg1, *(char**)arg2);
}
*/
