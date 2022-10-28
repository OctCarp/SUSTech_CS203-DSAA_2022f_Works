package E_1497;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class L3E {
    public static void main(String[] args) {
        new Soln();
    }
}

class Soln {
    final static int MAX_N = 80000; //max size of sequence
    final static int MAX_VAL = 80000; //max size of range
    final static int MAX_BLK = 283; //max number of blocks
    final static int RAN_WIDE = 283; //single range size
    final static int RAN_NUM = 283; //number of ranges
    final static int BLK_SIZE = 283; //single block size
    static int cntB = 0; //number of blocks

    Block[] bs = new Block[MAX_BLK + 5]; //linked list of blocks
    int[] v2r = new int[MAX_VAL + 5]; //give a value to return its range index

    int n;
    int m;

    Soln() {
        QReader in = new QReader();
        QWriter out = new QWriter();
        n = in.nextInt();
        m = in.nextInt();
        initV2R(); //initialize the value to range array
        cntB = v2r[n];

        for (int i = 0; i < bs.length; i++) {
            bs[i] = new Block(); //initialize the node in linked list
        }
        for (int i = 1; i <= n; i++) {
            bs[v2r[i]].vs[++bs[v2r[i]].cnt] = in.nextInt(); //read every number and initial block
        }
        init(); //calculate the prefix of the initial input

        for (int i = 0; i < m; i++) {
            int print = choose(in.nextLine());
            if (print >= 0) {
                out.println(print);
            }
        }

        out.close();
    }

    void initV2R() {
        for (int i = 0; i <= MAX_N; i++) {
            v2r[i] = i / RAN_WIDE + 1;
        }
    }

    void init() {
        for (int i = 1; i <= v2r[n]; i++) {
            Block b = bs[i];

            if (i > 1) {
                b.prev = i - 1; //bind previous node index
            }
            if (i < v2r[n]) {
                b.next = i + 1; //bind next node index
            }

            int val;
            for (int j = 1; j <= b.cnt; j++) {
                val = b.vs[j]; //read value
                b.inr[v2r[val]]++; // count of the range +1
                b.sgl[val]++; // count of the value +1
            }
            for (int j = 0; j <= MAX_N; j++) {
                if (v2r[j + 1] != v2r[j]) {
                    bs[i].inr[v2r[j]] += bs[i - 1].inr[v2r[j]]; //prefix sum of inr
                }
                bs[i].sgl[j] += bs[i - 1].sgl[j]; //prefix sum of single num
            }
        }
    }

    int choose(String str) {
        char type = str.charAt(0);
        String[] sep = str.split(" ");
        switch (type) {
            case 'I':
                insert(Integer.valueOf(sep[1]), Integer.valueOf(sep[2]));
                return -1;
            case 'M':
                modify(Integer.valueOf(sep[1]), Integer.valueOf(sep[2]));
                return -1;
            case 'Q':
                return query(Integer.valueOf(sep[1]), Integer.valueOf(sep[2]), Integer.valueOf(sep[3]));
            default:
                return -1;
        }
    }

    int query(int l, int r, int k) {
        int inbL, inbR, p = 1;
        while (bs[p].cnt < l) {
            l -= bs[p].cnt; //minus count of nums for l
            p = bs[p].next;
        }
        inbL = p; //record p for L
        p = 1; //initial p
        while (bs[p].cnt < r) {
            r -= bs[p].cnt; //minus count of nums for l
            p = bs[p].next;
        }
        inbR = p; // record p for R
        if (inbL == inbR) { //in same block
            int arr[] = Arrays.copyOfRange(bs[inbL].vs, l, r + 1);
            return Util.qSelect(arr, 0, arr.length - 1, k); //quick select in this block
        } else {
            Block bk = new Block();
            int val;
            for (int i = l; i <= bs[inbL].cnt; i++) { //count single element in left block
                val = bs[inbL].vs[i];
                bk.inr[v2r[val]]++;
                bk.sgl[val]++;
            }
            for (int i = 1; i <= r; i++) { //count single element in right block
                val = bs[inbR].vs[i];
                bk.inr[v2r[val]]++;
                bk.sgl[val]++;
            }

            int pRin = 1; //pointer of ranges
            while (bk.inr[pRin] + (bs[bs[inbR].prev].inr[pRin] - bs[inbL].inr[pRin]) < k) {
                k -= bk.inr[pRin] + (bs[bs[inbR].prev].inr[pRin] - bs[inbL].inr[pRin]); //k minus one range
                pRin++; //pointer moves to next range
            }
            int pSgl = (pRin - 1) * RAN_WIDE;
            while (bk.sgl[pSgl] + (bs[bs[inbR].prev].sgl[pSgl] - bs[inbL].sgl[pSgl]) < k) {
                k -= bk.sgl[pSgl] + (bs[bs[inbR].prev].sgl[pSgl] - bs[inbL].sgl[pSgl]); //k minus one single num
                pSgl++; //pointer moves to next range
            }
            return pSgl;
        }
    }

    void insert(int p, int v) {
        int pRin = 1;
        while (bs[pRin].cnt < p) {
            if (bs[pRin].next != 0) { //if it is not the last block
                p -= bs[pRin].cnt;
                pRin = bs[pRin].next;
            } else break;
        }
        final int inb = pRin; //record the index of this block

        for (int i = bs[inb].cnt; i >= p; i--) {
            bs[inb].vs[i + 1] = bs[inb].vs[i]; //move the behind elements
        }
        bs[inb].vs[p] = v; //insert the value
        bs[inb].cnt++; //count of numbers +1

        while (pRin != 0) { //update the prefix sum of behind blocks
            bs[pRin].inr[v2r[v]]++; //prefix of range +1
            bs[pRin].sgl[v]++; //prefix of single num +1
            pRin = bs[pRin].next;
        }
        if (bs[inb].cnt >= BLK_SIZE * 2) newBlock(inb);
    }

    void newBlock(int inb) {
        int oldI = inb;
        int newI = ++cntB; //new index for new block
        bs[newI].vs = bs[oldI].vs.clone();
        bs[newI].inr = bs[oldI].inr.clone();
        bs[newI].sgl = bs[oldI].sgl.clone(); //clone the arrays

        bs[bs[oldI].next].prev = newI;
        bs[newI].next = bs[oldI].next;
        bs[newI].prev = inb;
        bs[oldI].next = newI; //rebind the linked list

        bs[newI].cnt = bs[oldI].cnt / 2;
        int oldVal;
        for (int i = bs[oldI].cnt - bs[newI].cnt + 1; i <= bs[oldI].cnt; i++) {
            bs[newI].vs[i - (bs[oldI].cnt - bs[newI].cnt)] = bs[newI].vs[i];
            bs[newI].vs[i] = 0; //initialize the value in new block

            oldVal = bs[oldI].vs[i];
            bs[oldI].inr[v2r[oldVal]]--;
            bs[oldI].sgl[oldVal]--; //update the prefix in old block
            bs[oldI].vs[i] = 0; //initialize the value in old block
        }
        bs[oldI].cnt = bs[oldI].cnt - bs[newI].cnt;
    }

    void modify(int p, int v) {
        int pRin = 1;
        while (bs[pRin].cnt < p) { //search the target block
            p -= bs[pRin].cnt;
            pRin = bs[pRin].next;
        }

        int old = bs[pRin].vs[p];
        bs[pRin].vs[p] = v;

        while (pRin != 0) { //update the prefix sum of behind blocks
            bs[pRin].inr[v2r[old]]--;
            bs[pRin].inr[v2r[v]]++; //change the prefix of ranges
            bs[pRin].sgl[old]--;
            bs[pRin].sgl[v]++; //change the prefix of single value numbers
            pRin = bs[pRin].next;
        }
    }
}

class Block {
    int cnt = 0; //size of numbers
    int[] vs = new int[Soln.BLK_SIZE * 2 + 5]; //value of numbers
    int[] inr = new int[Soln.RAN_NUM + 5]; //count of value in range
    int[] sgl = new int[Soln.MAX_VAL + 5]; //count of single value

    int prev; //index of previous block in bs
    int next; //index of next block in bs
}

class Util {
    static int qSelect(int[] arr, int low, int high, int k) { //quick select: O(n)
        int partition = partition(arr, low, high);
        if (partition == k - 1) {
            return arr[partition];
        } else if (partition < k - 1) {
            return qSelect(arr, partition + 1, high, k);
        } else {
            return qSelect(arr, low, partition - 1, k);
        }
    }

    private static int partition(int[] arr, int l, int r) {
        int p = arr[r];
        int left = l;
        for (int i = l; i <= r; i++) {
            if (arr[i] < p) {
                int temp = arr[i];
                arr[i] = arr[left];
                arr[left] = temp;
                left++;
            }
        }
        int temp = arr[r];
        arr[r] = arr[left];
        arr[left] = temp;

        return left;
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

    public String nextLine() {
        tokenizer = new StringTokenizer("");
        return innerNextLine();
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