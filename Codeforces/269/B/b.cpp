#define NAME "b"

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

const int N = 2005;

int n;
pii p [N];

bool cmp (pii a, pii b)
{
    return a.frs < b.frs;
}

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p [i] = mp (x, i);
    }

    sort (p, p + n, cmp);
    int cnt = 0;
    int q [2];

    for (int i = 1; i < n; i++)
    {
        if (p [i - 1].frs == p [i].frs)
            q [cnt++] = i - 1;

        if (cnt == 2)
            break;
    }

    if (cnt < 2)
    {
        puts ("NO");
        return 0;
    }

    puts ("YES");

    for (int i = 0; i < n; i++)
        printf ("%d%c", p [i].snd + 1, " \n" [i == n - 1]);

    swap (p [q [0]], p [q [0] + 1]);

    for (int i = 0; i < n; i++)
        printf ("%d%c", p [i].snd + 1, " \n" [i == n - 1]);

    swap (p [q [1]], p [q [1] + 1]);

    for (int i = 0; i < n; i++)
        printf ("%d%c", p [i].snd + 1, " \n" [i == n - 1]);

    return 0;
}
