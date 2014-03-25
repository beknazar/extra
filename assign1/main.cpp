#include <iostream>
#include <string>
using namespace std;

char** table;
int m = 0, n = 0;

bool checkBox (char c, int x, int y) {
	if (x >= 0 && y >= 0 && x < m && y < n) // check if it's inside table
		if (table[x][y] == c) return 1;
	return 0;
}

int find (string text) {
	int len = text.length();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] == text[0]) {
				int index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , --x, --y)) count++; // 1
                if (count == len - 1) return i * 10 + j;
                index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , --x, y)) count++; // 2
                if (count == len - 1) return i * 10 + j;
                index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , --x, ++y)) count++; // 3
                if (count == len - 1) return i * 10 + j;
                index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , x, --y)) count++; // 4
                if (count == len - 1) return i * 10 + j;
                index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , x, ++y)) count++; // 5
                if (count == len - 1) return i * 10 + j;
                index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , ++x, --y)) count++; // 6
                if (count == len - 1) return i * 10 + j;
                index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , ++x, y)) count++; // 7
                if (count == len - 1) return i * 10 + j;
                index = 1, x = i, y = j, count = 0;
				while (index < len && checkBox(text[index++] , ++x, ++y)) count++; // 8
                if (count == len - 1) return i * 10 + j;
			}
		}
	}
	return -1;
}

char toLower(char c) {
	if (c <= 'Z' && c >= 'A') return c - ('Z' - 'z');
	return c;
}
int main() {
	cin >> m >> n;

	table = new char*[m];
	for (int i = 0; i < m; i++) table[i] = new char[n];
	char c;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			table[i][j] = toLower(c);
		}
	}
	
	string str;
	int tries = 0;
	cin >> tries;
	for (int i = 0; i < tries; i++) {
		cin >> str;
		for (int i = 0; i < str.length(); i++) str[i] = toLower(str[i]); // convert to lower case (ex, A -> a)
		int out = find (str);
		if (out == -1) cout << "\nnot found\n";
		else cout << out / 10 + 1 << " " << out % 10 + 1 << endl;
	}
}