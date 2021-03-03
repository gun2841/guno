#include<iostream>
#include<cstdio>
#include<queue>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);

    string a, b;
    cin >> a >> b;
    int ans = 100;
    for (int i = 0; i < b.size() - a.size()+1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != b[i + j]) {
              //  cout << a[j] << " " << b[i + j] << endl;
                cnt++;
            }
        }
        ans = min(ans, cnt);
     //   cout << ans << endl;
    }
    cout << ans;
}