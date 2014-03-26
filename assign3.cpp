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
	cout << "N: " << N << endl;

	for (int i = 0; i < N; i++)
	{
		int number = 0, count = 0, len = 0;
		cin >> number;
		ReversibleInteger obj(number);
		cout << "number: " << obj.getValue() << endl;
		ReversibleInteger reverseOfObj = obj.reverse();
		cout << "Reverse number is: " << reverseOfObj.getValue() << endl;
		ReversibleInteger sumOfThem = obj.add(reverseOfObj);
		cout << "Addition of org and rev: " << sumOfThem.getValue() << endl;

	/*	//Number of digits which addition has, START!
		int sum = obj.add(number, obj.reverse(number));
		while(sum > 0) 
		{
			int digit = sum % 10; 
			sum = sum / 10;
			len++;
		} //Number of digits which addition has, END!
		cout << len << endl;

		//Putting addition into arrays, START!
		int count2 = len;
		int sum2 = obj.add(number, obj.reverse(number));
		int* arr = new int[len];
		for (int a = 0; a < len; a++)
		{
			int ten = pow(10,(count2-1));
			arr[a] = sum2 / ten;
			cout << a << " : " << arr[a] << endl;
			sum2 = sum2 % ten;
			count2--;
		} //Putting addition into arrays, END!
		cout << "Len: " << len << endl;
		
		//BEK, PROBLEM STARTS HERE!
		//If not palindrome, reverse again, START!
		for (int a = 0; a < len / 2; a++)
		{
			while (arr[a] != arr[len - a - 1])
			{
				obj.add(obj.add(number, obj.reverse(number)), obj.reverse(obj.add(number, obj.reverse(number))));
				count++;
			}
		} //If not palindrome, reverse again, END!
		//BEK, UNTIL HERE, I GUESS!
		cout << count << " " << obj.add(number, obj.reverse(number)) << endl;*/
	}
	return 0;
}