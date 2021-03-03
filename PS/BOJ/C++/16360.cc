#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while (n--) {
		string str, ans;
		cin >> str;
		ans = str;
	int 	i = str.length() - 1;
	ans.erase(i);
	if (str[i] == 'a')
		ans += "as";
	else if (str[i] == 'i' || str[i] == 'y')
		ans += "ios";
	else if (str[i] == 'l')
		ans += "les";
	else if (str[i] == 'n')
		ans += "anes";
	else if(str[i] == 'e') {
		if (i > 0) {
			if (str[i - 1] == 'n') {
				ans.erase(i - 1);
				ans += "anes";
			}
			else
			{
				ans = str;
				ans += "us";
			}
		}
	}
	else if (str[i] == 'o')
		ans += "os";
	else if (str[i] == 'r')
		ans += "res";
	else if (str[i] == 't')
		ans += "tas";
	else if (str[i] == 'u')
		ans += "us";
	else if (str[i] == 'v')
		ans += "ves";
	else if (str[i] == 'w')
		ans += "was";
	else {
		ans = str;
		ans += "us";
	}
		cout << ans << endl;
	}
}
