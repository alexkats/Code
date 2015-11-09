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

int n;
int p [100005];
vector < pair <string, string> > s;

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        s.pb (mp (x, y));
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> p [i];
        p [i]--;
    }

    string last = " ";

    for (int i = 1; i <= n; i++)
    {
        string tmp1 = s [p [i]].frs;
        string tmp2 = s [p [i]].snd;
        string res1 = min (tmp1, tmp2);
        string res2 = max (tmp1, tmp2);

        if (res1 > last)
        {
            last = res1;
            continue;
        }

        if (res2 > last)
        {
            last = res2;
            continue;
        }

        puts ("NO");
        return 0;
    }

    puts ("YES");

    return 0;
}
