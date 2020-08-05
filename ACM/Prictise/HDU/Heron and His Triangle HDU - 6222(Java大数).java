import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String []args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		
		for(int i = 0;i < t; i++) {
			BigInteger a = input.nextBigInteger();
			BigInteger p = new BigInteger("2");
			BigInteger q = new BigInteger("4");
			BigInteger m = new BigInteger("4");
			BigInteger now = q;
			while(now.compareTo(a) < 0) {
				now = m.multiply(q).subtract(p);
				p = q;
				q = now;
			}
			System.out.println(now);
		}
	}
}