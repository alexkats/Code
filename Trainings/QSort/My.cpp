#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>

#define NAME "sort"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n;
ll a [100];

void QSort (int l, int r)
{
	int i = l;
	int j = r;
	int x = a [rand () % (r - l + 1) + l];

	while (i <= j)
	{
		while (a [i] < x)
			i++;

		while (a [j] > x)
			j--;

		if (i <= j)
		{
			swap (a [i], a [j]);
			i++;
			j--;
		}
	}

	if (l < j)
		QSort (l, j);

	if (i < r)
		QSort (i, r);
}

bool check ()
{
	for (int i = 1; i < n; i++)
		if (a [i - 1] > a [i])
			return false;

	return true;
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i];

	QSort (0, (n - 1));

	for (int i = 0; i < n; i++)
		out << a [i] << " ";

	out << endl;

	if (check ())
		out << "TRUE" << endl;
	else
		out << "FALSE" << endl;	

	return 0;

}	