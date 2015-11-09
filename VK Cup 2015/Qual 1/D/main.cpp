#define NAME "d"

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
#include <climits>
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

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 7;
const ll INFLONG = (ll) 1e18 + 7;
const double EPS = 1e-9;

using namespace std;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <char> vc;
typedef vector <string> vs;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

template <typename T>
T sqr (T a)
{
    return a * a;
}

int n, m;
vi a;
vpii b;

int solve (int left, int right)
{
    return -2;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &m);
    a.resize (n);
    b.resize (n);

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &a [i]);
        b [i] = mp (a [i], i);
    }

    sort (b.begin (), b.end ());

    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf ("%d %d", &l, &r);
        printf ("%d\n", solve (--l, --r) + 1);
    }

    return 0;
}
