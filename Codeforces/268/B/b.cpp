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

int p, q, left, right;
pii a [1005];
pii b [1005];
char used1 [1005];
char used2 [1005];

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used1, 0, sizeof (used1));
    memset (used2, 0, sizeof (used2));

    scanf ("%d %d %d %d", &p, &q, &left, &right);

    for (int i = 0; i < p; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        a [i] = mp (x, y);
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        b [i] = mp (x, y);
    }

    int curr = 0;

    for (int i = 0; i < 1001; i++)
    {
        if (curr >= p)
            break;

        if (a [curr].frs <= i && a [curr].snd >= i)
        {
            used1 [i] = 1;
            continue;
        }

        if (a [curr].frs > i)
            continue;

        curr++;

        if (a [curr].frs <= i)
        {
            used1 [i] = 1;
            continue;
        }
    }

    curr = 0;

    for (int i = 0; i < 1001; i++)
    {
        if (curr >= q)
            break;

        if (b [curr].frs <= i && b [curr].snd >= i)
        {
            used2 [i] = 1;
            continue;
        }

        if (b [curr].frs > i)
            continue;

        curr++;

        if (b [curr].frs <= i)
        {
            used2 [i] = 1;
            continue;
        }
    }

    for (int t = left; t <= right; t++)
    {


    return 0;
}
