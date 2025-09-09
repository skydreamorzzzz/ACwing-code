#include<iostream>
using namespace std;

int main(){
    int tmp, n;
    cin >> n;
    int *f = new int[n];
    for(int i = 0; i < n; i ++){
        cin >> f[i];
        if(i != 0){
            f[i] += f[i-1];
        }
    }
    for(int i = 1; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> tmp;
            if(j == 0){
                f[0] = f[0] + tmp;
            }
            else{
                f[j] = min(f[j-1], f[j]) + tmp;
            }
        }
    }
    cout << f[n-1];
    delete[] f;
    return 0;
}