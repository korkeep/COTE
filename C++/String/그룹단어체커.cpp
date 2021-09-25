#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	bool flag;
	int n, i, j, k, cnt;
	char temp;
	string str;
	vector<char> v;

	cnt = i = 0;
	
	cin >> n;
	if (n > 100 || n <= 0) return 0;

	for (; i < n; i++) {
		flag = true;
		v.clear();
		temp = 0;
		str = "";
		cin >> str;
		for (j = 0; j < str.length(); j++) {
			temp = str.at(j);
			for (k = 0; k < v.size(); k++) {
				if (v.at(k) == temp) {
					if (v.size() > 1 && str.at(j - 1) != temp)
						flag = false;
					break;
				}
			}
			if (flag) v.push_back(temp);
			else break;
		}
		if (flag) cnt++;
	}

	cout << cnt << endl;
	return 0;
}