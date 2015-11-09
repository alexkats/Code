#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <time.h>
#include <cassert>
#include <assert.h>

#define DEBUG
#define ASSERT
//#define NAME "b"

typedef long long LL;

using namespace std;

string s [15];
int x [15], y [15];

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 1; i < 11; i++)
	{
		cin >> x [i] >> y [i];

		if (x [i] < 40)
			a++;

		if (x [i] > 40 && x [i] < 80)
			b++;

		if (x [i] > 80)
			c++;
	}

	s [1] = "2-5-3";
	s [2] = "3-5-2";
	s [3] = "3-4-3";
	s [4] = "4-5-1";
	s [5] = "4-4-2";
	s [6] = "4-3-3";
	s [7] = "5-5-0";
	s [8] = "5-4-1";
	s [9] = "5-3-2";
	s [10] = "5-2-3";

	if (a == 2)
	{
		cout << 6 << endl << s [1] << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl;
		return 0;
	}

	if (a == 3 && b == 5)
	{
		cout << 10 << endl << s [1] << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [7] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 3)
	{
		cout << 9 << endl << s [1] << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 4 && b == 5)
	{
		cout << 10 << endl << s [1] << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [7] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 4 && b == 4)
	{
		cout << 10 << endl << s [1] << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [7] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 4)
	{
		cout << 9 << endl << s [1] << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 5 && b == 5)
	{
		cout << 6 << endl << s [2] << endl << s [4] << endl << s [5] << endl << s [7] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 5 && b == 4)
	{
		cout << 8 << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 5 && b == 3)
	{
		cout << 9 << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [7] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}

	if (a == 5)
	{
		cout << 8 << endl << s [2] << endl << s [3] << endl << s [4] << endl << s [5] << endl << s [6] << endl << s [8] << endl << s [9] << endl << s [10] << endl;
		return 0;
	}	

	return 0;

}	