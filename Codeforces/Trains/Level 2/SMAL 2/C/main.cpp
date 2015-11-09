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

const int N = 100005;
const int mod = 10007;

int a [N];
int t [N * 4];

void build (int v, int l, int r)
{
    if (l == r)
        t [v] = a [l];
    else
    {
        int m = (l + r) >> 1;
        build (v * 2, l, m);
        build (v * 2 + 1, m + 1, r);
        t [v] = t [v * 2] * t [v * 2 + 1];
        t [v] %= mod;
    }
}

int get (int v, int l, int r, int left, int right)
{
    if (left > right)
        return 1;

    if (l == left && r == right)
        return t [v];

    int m = (l + r) >> 1;
    int ans = get (v * 2, l, m, left, min (m, right)) * get (v * 2 + 1, m + 1, r, max (m + 1, left), right);
    ans %= mod;
    return ans;
}

int main ()
{
    srand (time (0));

    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n;
    scanf ("%d", &n);

    for (int i = 0; i < n; i++)
        scanf ("%d", &a [i]);

    build (1, 0, n - 1);
    int q;
    scanf ("%d", &q);

    for (int i = 0; i < q; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        x--;
        y--;
        printf ("%d\n", get (1, 0, n - 1, x, y));
    }

    return 0;
}
