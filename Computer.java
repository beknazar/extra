import java.util.Scanner;
public class Computer
{
	public static void main(String[] args)
	{
		final int RAM_LENGTH = 1000;
		final int REG_LENGTH = 10;
		int CAS = 0;
		int ram[] = new int[RAM_LENGTH]; 
		int reg[] = new int[REG_LENGTH];
		

		Scanner in = new Scanner(System.in);
		//System.out.print("Cases: ");
		CAS = in.nextInt();  //Number of cases
		int[] cases = new int[CAS];
		in.nextLine();
		in.nextLine();
		for (int c = 0; c < CAS; c++) 
		{
			int count = 0, k = 0, n = 0;
			Boolean finish = false;
			for (int i = 0; i < RAM_LENGTH; i++) ram[i] = 0;
			for (int i = 0; i < REG_LENGTH; i++) reg[i] = 0;

			do
			{
				String s = in.nextLine();
				if (s.trim().isEmpty())
					break;
				n = Integer.parseInt(s);
				ram[k++] = n;

			} while (in.hasNext());

			for (int j = 0; j < k && !finish; j++)
			{
				int digit1 = ram[j] / 100, digit2 = ram[j] / 10 - digit1 * 10, digit3 = ram[j] % 10;
				switch(digit1)
				{
					case 0: //goto the location in register d unless register s contains 0
						if (reg[digit3] != 0) j = reg[digit2] - 1;
						break;
					case 1: //halt
						if (digit2 == 0 && digit3 == 0) finish = true; 
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
						reg[digit2] = ram[reg[digit3]];
						break;
					case 9: // set the value in RAM whose address is in register a to the value of register s
						ram[reg[digit3]] = reg[digit2];
						break;
					default:
						break;
				}
				count++;
			}
			cases[c] = count;
		}
		for (int i = 0; i < CAS; i++)
		{
			System.out.println(cases[i]);
			System.out.println();
		}
	}
}