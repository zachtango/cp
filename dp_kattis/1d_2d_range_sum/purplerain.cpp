#include <iostream>
#include <string>

using namespace std;

int main() {

    /*
        Define M[i] as the maximum difference between
        num of Rs - num of Bs.
        M[i] = max(M[i - 1] + A[i], A[i])
            A[i] == 1 if S[i] == r
                    0 if S[i] == b
    */

    string s;

    cin >> s;

    int n = s.size();
    
    int R[n], B[n], Pr[n], Pb[n];
    for(int i = 0; i < n; i++) {
        Pr[i] = i;
        Pb[i] = i;

        if(s[i] == 'R') {
            R[i] = 1;
            B[i] = -1;
        } else {
            R[i] = -1;
            B[i] = 1;
        }
    }

    int Mr[n], Mb[n];
    Mr[0] = R[0];
    Mb[0] = B[0];

    int m_r = 0, m_b = 0;
    for(int i = 1; i < n; i++) {
        Mr[i] = max(Mr[i - 1] + R[i], R[i]);
        Mb[i] = max(Mb[i - 1] + B[i], B[i]);

        if(Mr[i - 1] + R[i] >= R[i])
            Pr[i] = Pr[i - 1];
        if(Mb[i - 1] + B[i] >= B[i])
            Pb[i] = Pb[i - 1];

        if(Mr[i] > Mr[m_r])
            m_r = i;
        if(Mb[i] > Mb[m_b])
            m_b = i;
    }

    if(Mr[m_r] > Mb[m_b])
        cout << Pr[m_r] + 1 << ' ' << m_r + 1;
    else if(Mr[m_r] < Mb[m_b])
        cout << Pb[m_b] + 1 << ' ' << m_b + 1;
    else if(Pr[m_r] < Pb[m_b])
        cout << Pr[m_r] + 1 << ' ' << m_r + 1;
    else if(Pr[m_r] > Pb[m_b])
        cout << Pb[m_b] + 1 << ' ' << m_b + 1;
    else
        cout << Pr[m_r] + 1 << min(m_r, m_b) + 1;
    
    return 0;
}