import java.util.*;

public class Main {
	private static int ind;
	private static Stack stackForOut;

	public static int outHelper(String st) {
		int b = 0, a = 1;
		String s = "";
		for (int i = st.length() - 2; i >= 0; --i) {
			char c = st.charAt(i);
			if (c == ')') {
				a++;
				i = outHelper(st.substring(0, i+1)) + 1;
				s = "<E" + (ind--) + '>' + s;
			}
			else if (c == '(') b++;
			else s = c + s;
			if (a == b) { // save for output
				stackForOut.push('(' + s + ')');
				return i;
			}
		}
		return 0;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("> ");

		String in;
		while (s.hasNextLine()) {
			in = s.nextLine();
			stackForOut = new Stack();
			ind = 1;
			/* prepare for output */
			for (int i = 1; i < in.length() - 2; i++) if (in.charAt(i) == '(') ind++;
			/* process the input string using helper function */
			outHelper(in);
			for (int i = 1; !stackForOut.isEmpty(); ++i)
				System.out.println("<E"+(++i)+"> => " + stackForOut.pop());
			System.out.print("> ");
		}
	}
}
