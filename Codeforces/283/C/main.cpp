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

int n, m;
vs s;

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    cin >> n >> m;
    s.resize (n);

    for (int i = 0; i < n; i++)
        cin >> s [i];

    vc good (m, 1);
    vc checked (n - 1, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < (n - 1); j++)
            if (checked [j] || s [j][i] <= s [j + 1][i])
                continue;
            else
            {
                good [i] = 0;
                break;
            }

        if (good [i])
        {
            for (int j = 0; j < (n - 1); j++)
                if (s [j][i] < s [j + 1][i])
                    checked [j] = 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++)
        if (!good [i])
            ans++;

    cout << ans << endl;

    return 0;
}
