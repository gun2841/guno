#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> arr;
int ans[2] = { 0,0 };
void quad(int x, int y, int size)
{
    int cur = arr[x][y];
    bool check = true;
    for (int i = x; (i < x + size) && check; i++)
        for (int j = y; (j < y + size) && check; j++)
            if (cur != arr[i][j]) check = false;

    if (check) ans[cur]+=1;
    else {
        quad(x, y, size / 2);
        quad(x + size / 2, y, size / 2);
        quad(x, y + size / 2, size / 2);
        quad(x + size / 2, y + size / 2, size / 2);
    }
}

vector<int> solution(vector<vector<int>> ar) {
    vector<int> answer;
    int n = ar.size();
    arr = ar;
    quad(0, 0, n);
    answer.push_back(ans[0]);
    answer.push_back(ans[1]);
    return answer;
}

