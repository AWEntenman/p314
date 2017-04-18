// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <search.h>
#include <stdlib.h>
#include <string.h>

unsigned short pr8();

const unsigned short xyList = 53;

const unsigned short xy[xyList][2]{
	{ 122, 250 },{ 133, 249 },{ 134, 249 },{ 140, 248 },{ 145, 247 },{ 149, 246 },{ 153, 245 },
	{ 156, 244 },{ 159, 243 },{ 160, 243 },{ 162, 242 },{ 165, 241 },{ 167, 240 },{ 168, 240 },
	{ 169, 239 },{ 170, 239 },{ 172, 238 },{ 174, 237 },{ 176, 236 },{ 178, 235 },{ 180, 234 },
	{ 182, 233 },{ 183, 233 },{ 183, 232 },{ 184, 232 },{ 185, 232 },{ 185, 231 },{ 187, 230 },
	{ 188, 230 },{ 188, 229 },{ 190, 228 },{ 191, 228 },{ 191, 227 },{ 193, 226 },{ 194, 226 },
	{ 194, 225 },{ 196, 224 },{ 197, 223 },{ 198, 223 },{ 198, 222 },{ 200, 221 },{ 201, 220 },
	{ 202, 220 },{ 202, 219 },{ 203, 219 },{ 203, 218 },{ 204, 218 },{ 204, 217 },{ 207, 215 },
	{ 208, 214 },{ 209, 213 },{ 210, 212 },{ 211, 211 }
};
