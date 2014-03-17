#include <iostream>
#include <stdio.h>
using namespace std;

#define SIZE 100
struct data {
	int id, n, time;
};

data* arr;

void merge(int l, int r, int mid) {
	data* temp = new data[r - l + 1];
	int i = l, j = mid + 1, k = 0;
	for (; i <= mid && j <= r; ) {

		if (arr[i].n > arr[j].n) temp[k++] = arr[i++];
		else if (arr[i].n < arr[j].n) temp[k++] = arr[j++];
		else {
			if (arr[i].time <= arr[j].time) temp[k++] = arr[i++];
			else if (arr[i].time > arr[j].time) temp[k++] = arr[j++];
		}
	}

	for (; i <= mid;) temp[k++] = arr[i++];
	for (; j <= r; ) temp[k++] = arr[j++];

	for (int b = l; b <= r; b++) arr[b] = temp[b - l];
}

void merge_sort(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(l, mid);
		merge_sort(mid + 1, r);
		merge(l, r, mid);
	}
}

int main() {
	int cases = 0, n, pb, t;
	char c;
	cin >> cases;

	arr = new data[SIZE + 1]; // arr[0] is not used data: 101 * 4 * 2

	for (int i = 1; i < SIZE + 1; i++) {
		arr[i].n = 0;
		arr[i].time = 0;
	}
	char input[SIZE];
	for (int i = 0; i < cases; i++) {
		while (fgets(input, SIZE, stdin) != NULL) {
			cin >> n >> pb >> t >> c;
			if (c == 'C') {
				arr[n].time += t;
				arr[n].n++;
				arr[n].id = n;
			}
			else if (c == 'I') {
				arr[n].time += 20;
			}
		}
		merge_sort(1, SIZE);
		for (int i = 0; i <= SIZE; i++) {
			if (arr[i].n != 0) {
				cout << arr[i].id << " " << arr[i].n << " " << arr[i].time << endl;
			}
		}
	}


}