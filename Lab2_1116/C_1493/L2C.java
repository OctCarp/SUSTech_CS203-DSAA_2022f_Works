package C_1493;

import java.io.*;
import java.util.StringTokenizer;

public class L2C {
    static int num;
    static int[] students;
    static int[] arr;
    static int max;

    public static void main(String[] args) {
        solution();
    }

    static void solution() {
        QReader in = new QReader();
        QWriter out = new QWriter();
        num = in.nextInt();
        students = new int[num];
        for (int i = 0; i < num; i++) {
            students[i] = in.nextInt();
        }
        mySort(students);
        out.println(max);
        out.println(myPrint());
        out.close();
    }

    static String myPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(arr[0]);
        for (int i = 1; i < arr.length; i++) {
            sb.append(String.format(" %d", arr[i]));
        }
        return sb.toString();
    }

    static void mySort(int[] stu) {
        mergeSort(stu, num);
        arr = new int[num];
        int tris = num / 3;
        int mod = num % 3;
        for (int i = 0; i < tris; i++) {
            arr[i * 3] = stu[i];
            arr[i * 3 + 1] = stu[tris + 2 * i];
            arr[i * 3 + 2] = stu[tris + 2 * i + 1];
        }
        max = stu[tris];
        if (mod != 0) {
            arr[num - 1] = stu[num - 1];
            arr[num - 2] = stu[num - 2];
        }
    }

    static void mergeSort(int[] arr, int n) {
        if (n < 2) {
            return;
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
        mergeSort(l, mid);
        mergeSort(r, n - mid);
        merge(arr, l, r);
    }

    static void merge(int[] m, int[] l, int[] r) {
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
