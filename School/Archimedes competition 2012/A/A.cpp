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

int a, b;

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> a >> b;

	if (a < 3 && b > 4)
		cout << 1 << endl;
	else
		cout << 0 << endl;	

	return 0;

}	