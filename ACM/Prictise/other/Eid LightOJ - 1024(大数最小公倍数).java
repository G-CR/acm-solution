import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for(int tt = 1;tt <= t; tt++) {
			int n = input.nextInt();
			BigInteger ans, m, k;
			m = input.nextBigInteger();
			ans = m;
			for(int i = 1;i < n; i++) {
				m = input.nextBigInteger();
				k = ans.gcd(m);
				ans = ans.multiply(m).divide(k);
			}
			System.out.println("Case "+ tt + ": " + ans);
			System.gc();
		}
	}
}