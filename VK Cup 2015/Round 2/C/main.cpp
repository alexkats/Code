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

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    int x1, y1, x2, y2;
    scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 < x2 && y1 < y2)
    {
        puts ("Polycarp");
        return 0;
    }

    if (x1 == x2 && y1 < y2)
    {
        puts ("Polycarp");
        return 0;
    }

    if (x1 < x2 && y1 == y2)
    {
        puts ("Polycarp");
        return 0;
    }

    if (x1 >= x2 && y1 >= y2)
    {
        puts ("Vasiliy");
        return 0;
    }

    if (x1 > x2 && y1 < y2)
    {
        int y = y2 - y1;
        
        if (x1 > y)
            puts ("Vasiliy");
        else
            puts ("Polycarp");

        return 0;
    }

    if (x1 < x2 && y1 > y2)
    {
        int x = x2 - x1;

        if (y1 > x)
            puts ("Vasiliy");
        else
            puts ("Polycarp");

        return 0;
    }

    return 0;
}
