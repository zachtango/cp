#include <iostream>

using namespace std;

#define L_MAX 20

int main(){
    int h, w, n, m;

    cin >> h >> w >> n >> m;

    int img[L_MAX][L_MAX],
        kernel[L_MAX][L_MAX];
    
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> img[i][j];

    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
            cin >> kernel[i][j];

    int len = h - n,
        wid = w - m;

    for(int i = 0; i <= len; i++){
        for(int j = 0; j <= wid; j++){
            int sum = 0;

            for(int k = 0; k < n; k++)
                for(int p = 0; p < m; p++){
                    // cout << '(' << kernel[k][p] << ',' << img[i + k][j + p] << ')' << endl;
                    sum += (kernel[k][p] * img[i + k][j + p]);
                }

            cout << sum << ' ';
        }
        cout << endl;
    }

    return 0;
}
