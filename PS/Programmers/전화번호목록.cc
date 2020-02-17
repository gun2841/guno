#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

struct Trie {
	Trie* go[10];
	bool output;
	bool goexist;
	Trie() {
		fill(go, go + 10, nullptr);
		output = goexist = false;
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
			if (go[i]) delete go[i];
	}
	bool insert(const char* key)
	{
		if (*key == '\0') { output = true; return !goexist; }
		else {
			int next = *key - '0';
			if (!go[next]) go[next] = new Trie;
			goexist = true;
			return (!output && go[next]->insert(key + 1));
			
		}
	}
};
bool solution(vector<string> phone_book) {
	bool answer = true;
	Trie* root = new Trie;
	for (int i = 0; i < phone_book.size(); i++)
	{
		char ch[22];
		strcpy(ch, phone_book[i].c_str());
		if (!root->insert(ch)) return false;
	}
	delete root;
	return true;
}