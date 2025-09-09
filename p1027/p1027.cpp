#include<iostream>
#include<cstring>
using namespace std;

const int N = 15;

int main(){
    int n;
    int f[N][N];
    int dp[2*N][N][N];
    memset(f, 0, N*N);
    memset(dp, 0, 2*N*N*N);
    cin >> n;
    int a, b, c, t;
    while(1){
        cin >> a >> b >> c;
        if(a || b || c){
            f[a][b] = c;
        }
        else{
            break;
        }
    }
    for(int k = 2; k <= 2*n; k ++){
        for(int i1 = 1; i1 <= n; i1 ++){
            for(int i2 = 1; i2 <= n; i2 ++){
                int j1 = k - i1;
                int j2 = k - i2;
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){
                    if(i1 == i2){
                        t = f[i1][j1];
                    }
                    else{
                        t = f[i1][j1] + f[i2][j2];
                    }
                    dp[k][i1][i2] = max(dp[k-1][i1][i2] + t, dp[k][i1][i2]);
                    dp[k][i1][i2] = max(dp[k-1][i1-1][i2] + t, dp[k][i1][i2]); 
                    dp[k][i1][i2] = max(dp[k-1][i1][i2-1] + t, dp[k][i1][i2]); 
                    dp[k][i1][i2] = max(dp[k-1][i1-1][i2-1] + t, dp[k][i1][i2]); 
                }
            }
        }
    }
    cout << dp[2*n][n][n];
    return 0;
}