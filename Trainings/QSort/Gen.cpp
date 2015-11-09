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

int main ()
{

	srand (time (0));

	ofstream out (NAME".in");

	int n = rand () % 100 + 1;
	out << n << endl;
	ll a;	

	for (int i = 0; i < n; i++)
	{
		a = rand () % 1000000000000;
		out << a << " ";
	}	

	out << endl;	

	return 0;

}	