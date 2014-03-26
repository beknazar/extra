#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAXDIGITS 10

class ReversibleInteger 
{
private:
	char digits[MAXDIGITS]; /* represent the number */
	int lastdigit; /* index of high-order digit */

public:

	ReversibleInteger (int n=0) {
		lastdigit = log10(n); // finding length - 1 of number; e.g. lastdigit for "786" = 2, "1000" = 3 ...
		for (int i = 0; i <= lastdigit; i++)
		{   
			digits[lastdigit - i] = n % 10;
			n = n / 10;
		}
	}
	ReversibleInteger reverse() {
		int len = lastdigit, revNum = 0;
		for (int i = 0; i <= lastdigit; i++) {
			revNum += digits[len] * pow(10, len--); // 786 -> 687
		}
		ReversibleInteger rev(revNum);
		return rev;
	}
	ReversibleInteger add(ReversibleInteger arg) {
		int sum = getValue() + arg.getValue();
		ReversibleInteger s(sum);
		return s;
	}
	int getValue() {
		int value = 0, len = lastdigit;
		for (int i = 0; i <= lastdigit; i++) {
			value += digits[i] * pow(10, len--); // conversion from char to int
		}
		return value;
	}
};

int main()
{
	int N;
	cin >> N;
	// cout << "N: " << N << endl;

	for (int i = 0; i < N; i++)
	{
		int number = 0, count = 0;
		cin >> number;
		ReversibleInteger obj(number);
		// cout << "number: " << obj.getValue() << endl;
		ReversibleInteger reverseOfObj = obj.reverse();
		// cout << "Reverse number is: " << reverseOfObj.getValue() << endl;
		ReversibleInteger sumOfThem = obj.add(reverseOfObj);
		// cout << "Addition of org and rev: " << sumOfThem.getValue() << endl;

		do {
			obj = obj.add(reverseOfObj);
			reverseOfObj = obj.reverse();
			count++;
			// cout << obj.getValue() << endl;
		} while (obj.getValue() != reverseOfObj.getValue());
		cout << count << " " << obj.getValue() << endl;
	}
	return 0;
}