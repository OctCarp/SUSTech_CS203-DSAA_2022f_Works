package A_1490;

import java.util.Scanner;

public class L1A {
    static int lengthA;
    static int lineNum;
    static int[] arrA;
    static int[] bounds;

    public static void main(String[] args) {
        readArr();
        results();
    }

    static void readArr() {
        Scanner sc = new Scanner(System.in);
        lengthA = sc.nextInt();
        lineNum = sc.nextInt();
        arrA = new int[lengthA];
        for (int i = 0; i < lengthA; i++) {
            arrA[i] = sc.nextInt();
        }
        bounds = new int[lineNum * 2];
        for (int i = 0; i < lineNum; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            bounds[2 * i] = x;
            bounds[2 * i + 1] = y;
        }
        sc.close();
    }

    static void results() {
        for (int i = 0; i < bounds.length; i += 2) {
            printArr(bounds[i], bounds[i + 1]);
        }
    }

    static int searchMin(int tar) {
        int start = 0;
        int end = arrA.length - 1;
        int mid = (start + end) / 2;
        if (arrA[end] <= tar) {
            return -1;
        } else {
            if (arrA[0] > tar) {
                return 0;
            } else {
                while (end - start > 1) {
                    if (tar > arrA[mid]) {
                        start = mid;
                    } else if (tar < arrA[mid]) {
                        end = mid;
                    } else {
                        while (arrA[mid + 1] == arrA[mid]) {
                            mid += 1;
                        }
                        return mid + 1;
                    }
                    mid = (start + end) / 2;
                }
                if (arrA[end] == tar) {
                    return start;
                } else return end;
            }
        }
    }

    static int searchMax(int tar) {
        int start = 0;
        int end = arrA.length - 1;
        int mid = (start + end) / 2;
        if (arrA[start] >= tar) {
            return -1;
        } else {
            if (arrA[lengthA - 1] < tar) {
                return lengthA - 1;
            }
            while (end - start > 1) {
                if (tar > arrA[mid]) {
                    start = mid;
                } else if (tar < arrA[mid]) {
                    end = mid;
                } else {
                    while (arrA[mid - 1] == arrA[mid]) {
                        mid -= 1;
                    }
                    return mid - 1;
                }
                mid = (start + end) / 2;
            }
            if (arrA[start] == tar) {
                return end;
            } else return start;
        }
    }

    static void printArr(int x, int y) {
        int min = searchMin(x);
        int max = searchMax(y);
        if (x == y) {
            System.out.println("NO");
        } else if (min == -1 || max == -1) {
            System.out.println("NO");
        } else {
            int num = max - min;
            if (num < 0) {
                System.out.println("NO");
            } else {
                System.out.println(String.format("YES %d",num + 1));
            }
        }
    }
}
