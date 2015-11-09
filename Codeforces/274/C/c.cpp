#define NAME "c"

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

int n;
pii a [5005];

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        a [i] = mp (x, y);
    }

    sort (a, a + n);

    int ans = a [n - 1].snd;

    for (int i = n - 2; i > -1; i--)
    {
        if (a [i].snd <= a [i + 1].snd)
            continue;
        else
        {
            ans = a [n - 1].frs;
            break;
        }
    }

    printf ("%d\n", ans);

    return 0;
}
