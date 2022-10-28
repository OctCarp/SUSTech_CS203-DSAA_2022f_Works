package A_1169;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class L0A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        ArrayList<Cube> Cubes = new ArrayList<>();
        for (int i = 0; i < number; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            Cubes.add(new Cube(a, b, c));
        }
        sc.close();
        for (int i = 0; i < number; i++) {
            Cubes.get(i).print();
        }
    }
}

class Cube {
    int l;
    int w;
    int h;
    char[][] threeD;

    public Cube(int a, int b, int c) {
        l = a;
        w = b;
        h = c;
        initial();
        top();
        front();
        side();
        bottom();
    }

    private void initial() {
        threeD = new char[2 * (h + w) + 1][];
        for (int i = 0; i < 2 * (h + w) + 1; i++) {
            char[] initialLine = new char[2 * (l + w) + 1];
            Arrays.fill(initialLine, '.');
            threeD[i] = initialLine;
        }

    }

    private void top() {
        for (int i = 0; i < 2 * w; i += 2) {
            threeD[i][2 * w - i] = '+';
            threeD[i + 1][2 * w - i - 1] = '/';
            for (int j = 2 * w - i + 1; j < 2 * (l + w) - i + 1; j += 2) {
                threeD[i][j] = '-';
                threeD[i][j + 1] = '+';
                threeD[i + 1][j - 1] = '.';
                threeD[i + 1][j] = '/';
            }
        }
    }

    private void front() {
        for (int i = 2 * w; i < 2 * (h + w); i += 2) {
            threeD[i][0] = '+';
            threeD[i + 1][0] = '|';
            for (int j = 1; j <= 2 * l; j += 2) {
                threeD[i][j] = '-';
                threeD[i][j + 1] = '+';
                threeD[i + 1][j] = '.';
                threeD[i + 1][j + 1] = '|';
            }
        }
    }

    private void side() {
        for (int j = 2 * (l + w); j > l * 2; j -= 2) {
            for (int i = 2 * (l + w) - j + 1; i < 2 * (l + w) - j + 2 * h + 1; i += 2) {
                threeD[i][j] = '|';
                threeD[i + 1][j] = '+';
                threeD[i + 1][j - 1] = '.';
                threeD[i + 2][j - 1] = '/';
            }
        }
    }

    public void bottom() {
        int last = threeD.length - 1;
        threeD[last][0] = '+';
        for (int i = 1; i < 2 * l; i += 2) {
            threeD[last][i] = '-';
            threeD[last][i + 1] = '+';
        }
    }

    public String toString(char[] line) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < line.length; i++) {
            sb.append(line[i]);
        }
        return sb.toString();
    }

    public void print() {
        for (int i = 0; i < threeD.length; i++) {
            System.out.println(toString(threeD[i]));
        }
    }
}
