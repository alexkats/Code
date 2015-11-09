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
//#define NAME "a"

typedef long long LL;

using namespace std;

int n, k;

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n >> k;

	for (int i = 1; i <= k; i++)
		cout << n - i + 1 << " ";

	for (int i = 1; i <= (n - k); i++)
		cout << i << " ";	

	return 0;

}	