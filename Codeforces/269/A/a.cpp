#define NAME "a"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

//const int INF = (int) 1e9 + 7;
//const ll INFLONG = (ll) 1e18 + 7;
//const double EPS = 1e-9;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <bool> vb;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

template <typename T>
T sqr (T a)
{
    return a * a;
}

int a [6];

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    for (int i = 0; i < 6; i++)
        cin >> a [i];

    sort (a, a + 6);

    if (a [0] == a [3])
    {
        if (a [4] == a [5])
            puts ("Elephant");
        else
            puts ("Bear");

        return 0;
    }

    if (a [1] == a [4])
    {
        if (a [0] == a [5])
            puts ("Elephant");
        else
            puts ("Bear");
    
        return 0;
    }

    if (a [2] == a [5])
    {
        if (a [0] == a [1])
            puts ("Elephant");
        else
            puts ("Bear");

        return 0;
    }

    puts ("Alien");

    return 0;
}
