import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}

class Solution {
    private int n;
    private int m;
    private int q;
    private final Node head = new Node(0);

    Solution() {
        QReader in = new QReader();
        QWriter out = new QWriter();
        n = in.nextInt();
        m = in.nextInt();
        q = in.nextInt();
        fakeHead();
        Node pU = head.r;
        Node pL = head.d;
        Node p;
        for (int i = 0; i < n - 1; i++) {
            Node first = new Node(in.nextInt());
            p = first;
            pU.d = p;
            pL.r = p;
            for (int j = 0; j < m - 1; j++) {
                Node input = new Node(in.nextInt());
                pU = pU.r;
                pU.d = input;
                p.r = input;
                p = p.r;
            }
            p.r = new Node(0);
            pU = pL.r;
            pL = pL.d;
        }
        Node first = new Node(in.nextInt());
        p = first;
        pU.d = p;
        pL.r = p;
        p.d = new Node(0);
        for (int i = 0; i < m - 1; i++) {
            Node input = new Node(in.nextInt());
            pU = pU.r;
            pU.d = input;
            p.r = input;
            p = p.r;
            p.d = new Node(0);
        }
        p.r = new Node(0);
        for (int i = 0; i < q; i++) {
            swap(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
        }
        p = head;
        Node print;
        for (int i = 0; i < n; i++) {
            p = p.d;
            StringBuilder sb = new StringBuilder();
            print = p.r;
            sb.append(print.val);
            for (int j = 0; j < m - 1; j++) {
                print = print.r;
                sb.append(" ");
                sb.append(print.val);
            }
            out.println(sb.toString());
        }

        out.close();
    }

    void swap(int x1, int y1, int x2, int y2, int l1, int l2) {
        Node lu1 = searchPre(x1, y1);
        Node lu2 = searchPre(x2, y2);
        Node p1 = lu1;
        Node p2 = lu2;
        Node temp;
        for (int i = 0; i < l1; i++) {
            p1 = p1.d;
            p2 = p2.d;
            temp = p1.r;
            p1.r = p2.r;
            p2.r = temp;
        }
        for (int i = 0; i < l2; i++) {
            p1 = p1.r;
            p2 = p2.r;
            temp = p1.d;
            p1.d = p2.d;
            p2.d = temp;
        }
        p1 = lu1;
        p2 = lu2;
        for (int i = 0; i < l2; i++) {
            p1 = p1.r;
            p2 = p2.r;
            temp = p1.d;
            p1.d = p2.d;
            p2.d = temp;
        }
        for (int i = 0; i < l1; i++) {
            p1 = p1.d;
            p2 = p2.d;
            temp = p1.r;
            p1.r = p2.r;
            p2.r = temp;
        }
    }

    void fakeHead() {
        Node l = head;
        Node u = head;
        for (int i = 0; i < n; i++) {
            l.d = new Node(0);
            l = l.d;
        }
        for (int i = 0; i < m; i++) {
            u.r = new Node(0);
            u = u.r;
        }
    }

    Node searchPre(int x, int y) {
        Node tar = head;
        for (int i = 0; i < x - 1; i++) {
            tar = tar.d;
        }
        for (int i = 0; i < y - 1; i++) {
            tar = tar.r;
        }
        return tar;
    }

    Node searchTail(Node tar, int l1, int l2) {
        Node tail = tar;
        for (int i = 0; i < l1 - 1; i++) {
            tail = tar.d;
        }
        for (int i = 0; i < l2 - 1; i++) {
            tail = tar.r;
        }
        return tail;
    }
}

class Node {
    int val;
    Node r;
    Node d;

    Node(int val) {
        this.val = val;
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

/**************************************************************
 Problem: 1496
 User: *********
 Language: Java
 Result: Accepted
 Time:2592 ms
 Memory:55748 kb
 ****************************************************************/
