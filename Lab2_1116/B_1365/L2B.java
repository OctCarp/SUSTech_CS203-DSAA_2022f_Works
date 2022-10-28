package B_1365;

import java.io.*;
import java.util.StringTokenizer;

public class L2B {
    static int arrNum;
    static int[][] arrS;

    public static void main(String[] args) {
        qReader();
    }

    static long reverse(int[] arr) {
        return mergeSortTimes(arr, arr.length);
    }

    static long mergeSortTimes(int[] arr, int n) {
        long times = 0L;
        if (n < 2) {
            return 0;
        }
        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n - mid];
        for (int i = 0; i < mid; i++) {
            l[i] = arr[i];
        }
        for (int i = mid; i < n; i++) {
            r[i - mid] = arr[i];
        }
        times += mergeSortTimes(l, mid);
        times += mergeSortTimes(r, n - mid);
        times += mergeTimes(arr, l, r);
        return times;
    }

    static long mergeTimes(int[] m, int[] l, int[] r) {
        long times = 0L;
        int ll = l.length, rl = r.length;
        int i = 0, j = 0, k = 0;
        while (i < ll && j < rl) {
            if (l[i] <= r[j]) {
                m[k++] = l[i++];
            } else {
                times += (long) ll - i;
                m[k++] = r[j++];
            }
        }
        while (i < ll) {
            m[k++] = l[i++];
        }
        while (j < rl) {
            m[k++] = r[j++];
        }
        return times;
    }

    static void qReader() {
        QReader in = new QReader();
        QWriter out = new QWriter();
        arrNum = in.nextInt();
        arrS = new int[arrNum][];
        for (int i = 0; i < arrNum; i++) {
            int l = in.nextInt();
            int[] arr = new int[l];
            for (int j = 0; j < l; j++) {
                arr[j] = in.nextInt();
            }
            arrS[i] = arr;
        }
        for (int i = 0; i < arrNum; i++) {
            out.println(reverse(arrS[i]));
        }
        out.close();
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
