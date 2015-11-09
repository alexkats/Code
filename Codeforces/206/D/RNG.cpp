#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF (1<<29)

int N;
string board[30];

int dp[42][(1<<20)];
int mask[42][30];

int func(int i, int j, int c, bool first){
    if(dp[i][j] != 10000) return dp[i][j];
    
    int next;
    int ans = -INF;
    
    if(i == 2*(N-1)){
        ans = 0;
    } else {
        REP(next,26){
            int i2 = i + 1;
            int j2 = (mask[i+1][next] & (j | (j << 1)));
            if(j2 != 0) ans = max(ans, -func(i2, j2, next, !first));
        }
    }
    
    if(first){
        if(c == 0) ans++; else if(c == 1) ans--;
    } else {
        if(c == 0) ans--; else if(c == 1) ans++;
    }
    
//  cout << i << ' ' << j << ' ' << ans << endl;
    
    return dp[i][j] = ans;
}

int main(void){
    int i,j,k;
    
    cin >> N;
    REP(i,N) cin >> board[i];
    
    REP(i,2*N) REP(j,26) REP(k,N){
        int x = k;
        int y = i-x;
        if(y >= 0 && y < N && board[x][y] - 'a' == j) mask[i][j] |= (1<<k);
    }
    
    REP(i,2*N) REP(j,(1<<N)) dp[i][j] = 10000;
    int ans = func(0, 1, board[0][0] - 'a', false);
    if(ans < 0) cout << "FIRST" << endl;
    if(ans == 0) cout << "DRAW" << endl;
    if(ans > 0) cout << "SECOND" << endl;
    
    return 0;
}