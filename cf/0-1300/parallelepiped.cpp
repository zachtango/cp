#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;

    int a = sqrt(A1 * A2 / A3);
    int b = sqrt(A1 * A3 / A2);
    int c = A3 / b;

    cout << (4 * (a + b + c));

    return 0;
}