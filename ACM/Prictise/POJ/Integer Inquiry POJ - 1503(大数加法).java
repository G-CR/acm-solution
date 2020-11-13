import java.util.Scanner;
import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BigInteger zero = new BigInteger("0");
		BigInteger sum = new BigInteger("0");
		while(true) {
			BigInteger a = input.nextBigInteger();
			if(a.equals(zero)) {
				break;
			} 
			sum = sum.add(a);
		}
		System.out.println(sum);
	}
}