import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        new Solution();
    }
}

class Solution {
    int num;
    int[] ints;

    Solution() {
        QReader in = new QReader();
        QWriter out = new QWriter();
        num = in.nextInt();
        ints = new int[num];

        for (int i = 0; i < num; i++) {
            ints[i] = in.nextInt();
        }

        mergeSort(ints, num);

        long sum = 0L;
        for (int i = 0; i < num / 2; i++) {
            sum += ((long) ints[i] * ints[num - 1 - i]);
        }

        out.print(sum);

        out.close();
    }

    void mergeSort(int[] arr, int n) {
        if (n < 2) return;

        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n - mid];
        System.arraycopy(arr, 0, l, 0, mid);
        System.arraycopy(arr, mid, r, 0, n - mid);

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

    public void print(Object object) {
        try {
            writer.write(object.toString());
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
