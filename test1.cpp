#include <iostream>
const int MAX = 100;
int ckn[MAX][MAX];
int C(int k, int n) {
if (k == n || k == 0) return 1;
if (ckn[k][n] == -1)
ckn[k][n] = C(k-1, n-1) + C(k, n-1);
return ckn[k][n];
}
int main() {
for (int i = 0; i < MAX; i++)
for (int j = 0; j < MAX; j++) ckn[i][j] = -1;
std::cout << C(100,200);
}
