import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for(int i = 0;i < t; i++) {
			BigInteger a = input.nextBigInteger();
			BigInteger b = input.nextBigInteger();
			BigInteger c = input.nextBigInteger();
			BigInteger d = input.nextBigInteger();
			BigInteger sum = new BigInteger("0");
			sum = sum.add(a); sum = sum.add(b);
			sum = sum.add(c); sum = sum.add(d);
			System.out.println(sum);
		}
	}
}