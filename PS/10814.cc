#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace::std;

struct student {
	int age;
	string name;
	int num;
	bool operator < (const student &s) const {
		if (age < s.age)
			return true;
		else if (age == s.age)
			return (num < s.num);
		else  return false;
	}
};
int main()
{
	vector<student> vt;
	string name; int i;
	int T;
	cin >> T;
	for(int j = 0;j<T;j++){
		
		cin >> i >> name;
		vt.push_back({ i,name,j });
			}
	sort(vt.begin(),vt.end());
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i].age << " " << vt[i].name << "\n";
	}
}