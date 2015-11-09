#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6;
const int inf = 1e9;
int a[maxn];
int b[maxn];
int go[maxn];
 
int main()
{
  freopen("i.in", "r", stdin);
  freopen("right.out", "w", stdout);
  int n, m, k, cur, w, t;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < m; i++)
    scanf("%d", &b[i]);
  cur = n - 1;
  w = 0;
  for (int i = n - 1; i >= 0; i--){
    for (; cur >= 0 && w <= k; cur--)
      w += a[cur];
    go[i] = cur + 1;
    w -= a[i];
  }
  cur = 0;
  t = 1;
  b[m++] = inf * 2;
//  for (int i = 0; i < n; i++)
//    cerr << go[i] << " ";
//  cerr << endl;
 
  for (int i = 0; i < m; i++){
//    cerr << "do " << cur << endl;
    cur += b[i] - t;
//    cerr << cur << endl;
    if (cur >= n){
      cout << b[i] - (cur - n) - 1 << endl;
      return 0;
    }
    if (cur != 0)
        cur = go[cur - 1];
    t = b[i] + 1;
  }
 
 
 
 
  return 0;
}