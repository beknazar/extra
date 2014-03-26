#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ReversibleInteger 
{
private:
	int lastdigit;
public:
	int reverse(int num)
	{
		int revNum = 0;
		while(num > 0) //Reversing the number
		{   
			lastdigit = num % 10;
			revNum = revNum * 10 + lastdigit; 
			num = num / 10;
		}
		return revNum;
	}
	int add(int a, int b)
	{
		int sum = 0;
		sum = a + b;
		//cout << a << " + " << b << " = " << sum << endl;
		return sum;
	}
	int getValue();
};

int main()
{
	ReversibleInteger obj;

	int N;
	cin >> N;
	cout << "N: " << N << endl;

	for (int i = 0; i < N; i++)
	{
		int number = 0, count = 0, len = 0;
		cin >> number;
		cout << "number: " << number << endl;
		cout << "Reverse number is: " << obj.reverse(number) << endl;
		
		cout << "Addition of org and rev: " << obj.add(number, obj.reverse(number)) << endl;

		//Number of digits which addition has, START!
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
		cout << count << " " << obj.add(number, obj.reverse(number)) << endl;
	}
	return 0;
}