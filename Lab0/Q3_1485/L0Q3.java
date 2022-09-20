package Q3_1485;

import java.math.BigInteger;
import java.util.Scanner;

public class L0Q3 {
    static long horizontal;
    static long vertical;
    static int divisor;
    static long steps;

    public static void main(String[] args) {
        initial();
        System.out.println(answer());
    }

    static void initial() {
        Scanner sc = new Scanner(System.in);
        long x1 = sc.nextLong();
        long y1 = sc.nextLong();
        long x2 = sc.nextLong();
        long y2 = sc.nextLong();
        divisor = sc.nextInt();
        horizontal = x2 - x1;
        vertical = y2 - y1;
        steps = horizontal + vertical;
    }

    static int answer() {
        BigInteger bi = combinations(horizontal, steps);
        bi = bi.mod(BigInteger.valueOf(divisor));
        return bi.intValue();
    }

    static BigInteger combinations(long m, long n) {
        BigInteger bi = BigInteger.valueOf(1);
        bi = bi.multiply(factorial(n));
        bi = bi.divide(factorial(n - m));
        bi = bi.divide(factorial(m));
        return bi;
    }

    static BigInteger factorial(long num) {
        BigInteger bi = BigInteger.valueOf(1);
        for (int i = 2; i <= num; i++) {
            bi = bi.multiply(BigInteger.valueOf(i));
        }
        return bi;
    }
}
