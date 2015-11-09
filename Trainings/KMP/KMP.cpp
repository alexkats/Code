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
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "kmp"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

vector <int> kmp_function (string s)
{
	int n = (int) s.length ();
	vector <int> kmp (n);

	for (int i = 1; i < n; i++)
	{
		int j = kmp [i - 1];

		while (j > 0 && s [i] != s [j])
			j = kmp [j - 1];

		if (s [i] == s [j])
			j++;

		kmp [i] = j;
	}

	return kmp;
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	string s;
	vector <int> kmp;

	in >> s;

	kmp = kmp_function (s);

	for (int i = 0; i < (int) s.length (); i++)
		out << kmp [i] << endl;

	return 0;

}	