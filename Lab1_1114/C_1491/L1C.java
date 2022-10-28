package C_1491;

import java.util.ArrayList;
import java.util.Scanner;

public class L1C {
    static long students;
    static int cakesNum;
    static ArrayList<Integer> cakesSquare;
    static int maxCake = 0;
    static final double eps = 1e-9;

    public static void main(String[] args) {
        read();
        System.out.printf("%.7f", divide());
    }

    static double divide() {
        double min = 0.0;
        double max = maxCake * maxCake;
        double mid = 0;
        while (max - min > eps) {
            mid = (max + min) / 2;
            long divideNum = 0;
            for (int i = 0; i < cakesNum; i++) {
                int square = cakesSquare.get(i);
                divideNum += Math.floor(square / mid);
            }
            if (divideNum < students) {
                max = mid;
            } else min = mid;
        }
        return mid * Math.PI;
    }


    static void read() {
        Scanner sc = new Scanner(System.in);
        students = sc.nextInt();
        cakesNum = sc.nextInt();
        cakesSquare = new ArrayList<>();
        for (int i = 0; i < cakesNum; i++) {
            int moonCake = sc.nextInt();
            if (moonCake > maxCake) {
                maxCake = moonCake;
            }
            cakesSquare.add(moonCake * moonCake);
        }
        sc.close();
    }
}
