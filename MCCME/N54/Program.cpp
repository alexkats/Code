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

#define NAME "test"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	string s = "This is an sentence.";
	s.erase (s.begin () + 9);

	out << s;

	return 0;

}	