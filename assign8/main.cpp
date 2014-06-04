#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int T;
	string s;
	getline(cin, s);
	istringstream tmp(s);
	tmp >> T;

	int cases[T];
	getline(cin, s);
	for (int i = 0; i < T; i++) {
		// getline(cin, s);
		int reg[10], RAM[1000], k = 0, count = 0;
		for (int j = 0; j < 1000; j++) RAM[j] = 0;
		for (int j = 0; j < 10; j++) reg[j] = 0;

		while (getline(cin, s)) { // geting instructions codes into array RAM
			if (s.empty()) {
				break;
			}
			istringstream tmp(s);
			int n;
			tmp >> n;
			RAM[k++] = n;
		}
		bool stop = 0;
		for (int j = 0; j < k && !stop; j++) { //  decoding instructions and counting
			int digit1 = RAM[j] / 100, digit2 = RAM[j] / 10 - digit1 * 10, digit3 = RAM[j] % 10;
			
			// cout << digit1 << digit2 << digit3 << endl;
			switch (digit1) {
				case 0: // goto the location in register d unless register s contains 0
					if (reg[digit3] != 0) j = reg[digit2] - 1;
					break;
				case 1: // halt
					if (digit2 == 0 && digit3 == 0) stop = 1; 
					break;
				case 2: // set register d to n
					reg[digit2] = digit3;
					break;
				case 3: // add n to register d
					reg[digit2] = (reg[digit2] + digit3) % 1000;
					break;
				case 4: // multiply register d by n
					reg[digit2] = (reg[digit2] * digit3) % 1000;
					break;
				case 5: // set register d to the value of register s
					reg[digit2] = reg[digit3];
					break;
				case 6: // add the value of register s to register d
					reg[digit2] = (reg[digit2] + reg[digit3]) % 1000;
					break;
				case 7: // multiply register d by the value of register s
					reg[digit2] = (reg[digit2] * reg[digit3]) % 1000;
					break;
				case 8: // set register d to the value in RAM whose address is in register a
					reg[digit2] = RAM[reg[digit3]];
					break;
				case 9: // set the value in RAM whose address is in register a to the value of register s
					RAM[reg[digit3]] = reg[digit2];
					break;
				default:
					break;
			}
			count++;
		}

		cases[i] = count;
	}

	for (int i = 0; i < T; i++) {
		cout << cases[i] << endl << endl;
	}
}