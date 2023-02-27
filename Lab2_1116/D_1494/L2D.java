import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        new Solution();
    }
}

class Solution {
    int n;
    int m;
    static int k;
    int[] nums;
    long sum;
    static ArrayList<Integer> swap = new ArrayList<>();

    Solution() {
        QReader in = new QReader();
        QWriter out = new QWriter();
        n = in.nextInt();
        nums = new int[n];
        m = in.nextInt();
        k = in.nextInt();

        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
            sum += (long) nums[i];
            Num x = new Num(nums[i]);
        }

        int[] solutions = swap.stream().mapToInt(x -> x).toArray();
        mergeSort(solutions, solutions.length);

        for (int i = 0; i < m; i++) {
            if (i < solutions.length) {
                sum += solutions[solutions.length - 1 - i];
            } else break;
        }
        out.println(sum);

        out.close();
    }

    void mergeSort(int[] arr, int n) {
        if (n < 2) return;

        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n - mid];
        System.arraycopy(arr, 0, l, 0, mid);
        if (n - mid >= 0) System.arraycopy(arr, mid, r, 0, n - mid);

        mergeSort(l, mid);
        mergeSort(r, n - mid);
        merge(arr, l, r);
    }

    void merge(int[] m, int[] l, int[] r) {
        int ll = l.length, rl = r.length;
        int i = 0, j = 0, k = 0;

        while (i < ll && j < rl) {
            if (l[i] <= r[j]) {
                m[k++] = l[i++];
            } else {
                m[k++] = r[j++];
            }
        }
        while (i < ll) {
            m[k++] = l[i++];
        }
        while (j < rl) {
            m[k++] = r[j++];
        }
    }
}

class Num {
    int[] numArr;
    int len;
    int cost = Solution.k;
    boolean positive;

    Num(int num) {
        String str = String.valueOf(num);
        String s;
        if (num >= 0) {
            s = str;
            positive = true;
        } else {
            s = str.substring(1);
            positive = false;
        }

        len = s.length();
        numArr = new int[len];
        for (int i = 0; i < len; i++) {
            numArr[i] = s.charAt(i) - '0';
        }

        if (positive) {
            searchP();
        } else {
            searchN();
        }
    }

    void searchP() {
        int[] arr = Arrays.copyOf(numArr, len);
        for (int i = 0; i < len - 1; i++) {
            int first = arr[i];
            int max = 0;
            int locate = i;

            for (int j = i + 1; j < len; j++) {
                if (arr[j] >= max) {
                    max = arr[j];
                    locate = j;
                }
            }
            int up = (int) ((max - first) * Math.pow(10, len - i - 1) + (first - max) * Math.pow(10, len - locate - 1)) - cost;
            if (up > 0) {
                Solution.swap.add(up);
                int temp = arr[i];
                arr[i] = arr[locate];
                arr[locate] = temp;
            }
        }
    }

    void searchN() {
        int[] arr = Arrays.copyOf(numArr, len);

        for (int i = 0; i < len - 1; i++) {
            int first = arr[i];
            int min = 9;
            int locate = i;
            for (int j = i + 1; j < len; j++) {
                if (arr[j] <= min) {
                    min = arr[j];
                    locate = j;
                }
            }

            int up = (int) ((first - min) * Math.pow(10, len - i - 1) + (min - first) * Math.pow(10, len - locate - 1)) - cost;

            if (up > 0) {
                Solution.swap.add(up);
                int temp = arr[i];
                arr[i] = arr[locate];
                arr[locate] = temp;
            }
        }
    }
}

class QReader {
    private BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private StringTokenizer tokenizer = new StringTokenizer("");

    private String innerNextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public boolean hasNext() {
        while (!tokenizer.hasMoreTokens()) {
            String nextLine = innerNextLine();
            if (nextLine == null) {
                return false;
            }
            tokenizer = new StringTokenizer(nextLine);
        }
        return true;
    }

    public String next() {
        hasNext();
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}

class QWriter implements Closeable {
    private BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    public void println(Object object) {
        try {
            writer.write(object.toString());
            writer.write("\n");
        } catch (IOException e) {
            return;
        }
    }

    @Override
    public void close() {
        try {
            writer.close();
        } catch (IOException e) {
            return;
        }
    }
}