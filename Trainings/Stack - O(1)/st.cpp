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

#define NAME "st"
#define maxn 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

stack < pair <int, int> > st;

int n, new_element, a [maxn];

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
	{
		in >> new_element;
		int minima = st.empty () ? new_element : min (new_element, st.top ().second);
		st.push (make_pair (new_element, minima));
	}

	out << st.top ().second << endl;	

	return 0;

}	