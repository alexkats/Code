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
//#define NAME "c"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

ull q;
int n, a [300010];

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a [i];

	sort (a + 1, a + n + 1);
	q = 0;

	for (int i = 1; i <= n; i++)
		q += abs (a [i] - i);

	cout << q << endl;	

	return 0;

}	