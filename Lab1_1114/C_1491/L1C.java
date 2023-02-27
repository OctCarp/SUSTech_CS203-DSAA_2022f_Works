import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Solution();
    }
}

class Solution {
    long students;
    int cakesNum;
    ArrayList<Integer> cakesSquare;
    int maxCake = 0;
    final double eps = 1e-9;

    Solution() {
        read();
        System.out.printf("%.7f", divide());
    }

    void read() {
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

    double divide() {
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
}
