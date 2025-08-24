#include<iostream>
using namespace std;

int main(){
    int t, r, c, tmp;
    cin >> t;
    for(int i = 0; i < t; i ++){
        cin >> r >> c;
        int** matrix = new int*[r];
        for(int j = 0; j < r; j ++){
            matrix[j] = new int[c];
            for(int k = 0; k < c; k++){
                cin >> matrix[j][k];
            }
        }
        
        int** dp = new int*[r];
        for(int j = 0; j < r; j ++){
            dp[j] = new int[c];
        }
        dp[0][0] = matrix[0][0];
        for(int j = 0; j < r; j ++){
            for(int k = 0; k < c; k ++){
                if(k != 0 && j != 0){
                    dp[j][k] = max(dp[j-1][k],dp[j][k-1]) + matrix[j][k];
                }
                else if(k==0 && j==0){
                    continue;
                }
                else if(k == 0){
                    dp[j][k] = matrix[j][k] + dp[j-1][k];
                }
                else{
                    dp[j][k] = matrix[j][k] + dp[j][k-1];
                }
            }
        }
        cout << dp[r-1][c-1] << endl;
        for(int j = 0; j < r; j ++){
            delete[] matrix[j];
            delete[] dp[j];
        }
        delete[] matrix;
        delete[] dp;
    }
    return 0;
}