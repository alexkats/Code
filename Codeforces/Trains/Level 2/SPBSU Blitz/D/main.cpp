#define NAME "cows"

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

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 7;

using namespace std;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <char> vc;

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

int n, k;
vi a;

char good (int curr)
{
    int q = 1;
    int next = 0;

    while (1)
    {
        if (q == k)
            break;

        int res = 0;

        for (int i = next + 1; i < n; i++)
            if ((a [i] - a [next]) < curr)
                continue;
            else
            {
                res = i;
                break;
            }

        if (res == 0)
            break;

        q++;
        next = res;
    }

    return (q == k);
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &k);
    a.resize (n);

    for (int i = 0; i < n; i++)
        scanf ("%d", &a [i]);

    int left = 0;
    int right = INF;
    int ans = 0;

    while (right - left > 1)
    {
        int middle = (left + right) >> 1;

        if (good (middle))
            left = middle;
        else
            right = middle;
    }

    if (good (right))
        ans = right;
    else
        ans = left;

    printf ("%d\n", ans);

    return 0;
}
