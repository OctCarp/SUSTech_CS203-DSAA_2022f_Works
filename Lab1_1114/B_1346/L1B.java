package B_1346;

import java.util.Scanner;

public class L1B {
    static int l;
    static int sum;
    static int[] nums;
    static long ways;
    static int last;

    public static void main(String[] args) {
        read();
        search();
        System.out.println(ways);
    }

    static void search() {
        for (int i = 0; i < l && nums[i] * 3 <= sum; ) {
            int a = nums[i];
            int endA = upper(a, i, last);
            int aS = endA - i + 1;
            if (a * 3 == sum && aS >= 3) {
                ways += comb(aS, 3);
                break;
            } else {
                for (int j = endA + 1; j < l && nums[j] + a * 2 <= sum; ) {
                    int b = nums[j];
                    int endB = upper(b, j, last);
                    int bS = endB - j + 1;
                    if (aS >= 2 && b + a * 2 == sum) {
                        ways += comb(aS, 2) * bS;
                    } else if (bS >= 2 && b * 2 + a == sum) {
                        ways += aS * comb(bS, 2);
                    } else {
                        int c = sum - a - b;
                        int indexC = myBinarySearch(sum - a - b, endB + 1, last);
                        if (indexC != -1) {
                            int startC = lower(c, endB + 1, indexC);
                            int endC = upper(c, indexC, last);
                            int cS = endC - startC + 1;
                            ways += aS * bS * cS;
                        }
                    }
                    j = endB + 1;
                }
            }
            i = endA + 1;
        }
    }

    static int myBinarySearch(int tar, int start, int end) {
        if (start <= end) {
            int mid = (end + start) / 2;
            if (nums[mid] < tar) {
                return myBinarySearch(tar, mid + 1, end);
            } else if (nums[mid] > tar) {
                return myBinarySearch(tar, start, mid - 1);
            } else {
                return mid;
            }
        }
        return -1;
    }

    static int lower(int tar, int start, int end) {
        int mid = (end + start) / 2;
        while (end >= start) {
            if (nums[mid] == tar) {
                if (nums[mid - 1] != tar) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            } else if (nums[mid] < tar) {
                if (nums[mid + 1] == tar) {
                    return mid + 1;
                } else {
                    start = mid + 1;
                }
            }
            mid = (start + end) / 2;
        }
        return mid + 1;
    }

    static int upper(int tar, int start, int end) {
        int mid = (end + start) / 2;
        while (end >= start) {
            if (mid < last) {
                if (nums[mid] == tar) {
                    if (nums[mid + 1] == tar) {
                        start = mid + 1;
                    } else {
                        return mid;
                    }
                } else if (nums[mid] > tar) {
                    if (nums[mid - 1] > tar) {
                        end = mid - 1;
                    } else {
                        return mid - 1;
                    }
                }
            } else return last;
            mid = (start + end) / 2;
        }
        return mid;
    }

    static void read() {
        Scanner sc = new Scanner(System.in);
        l = sc.nextInt();
        last = l - 1;
        sum = sc.nextInt();
        nums = new int[l];
        for (int i = 0; i < l; i++) {
            nums[i] = sc.nextInt();
        }
        sc.close();
    }

    static long comb(int m, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return m;
        }
        if (n > m / 2) {
            return comb(m, m - n);
        }
        if (n > 1) {
            return comb(m - 1, n - 1) + comb(m - 1, n);
        }
        return -1;
    }
}