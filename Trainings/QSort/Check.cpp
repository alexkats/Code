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

#define NAMEIN "sort"
#define NAMEOUT "true_sort"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n;
ll a [100];

int main ()
{

	ifstream in (NAMEIN".in");
	ofstream out (NAMEOUT".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i];

	sort (a, a + n);

	for (int i = 0; i < n; i++)
		out << a [i] << " ";

	out << endl;
	out << "TRUE" << endl;	

	return 0;

}	