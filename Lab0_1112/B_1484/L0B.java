import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Solution();
    }
}

class Solution {
    Card dealer;
    ArrayList<Card> paul = new ArrayList<>();

    Solution() {
        initial();
        System.out.println(compareAll() ? "All in" : "Fold");
    }

    void initial() {
        Scanner sc = new Scanner(System.in);
        String d = sc.next();
        dealer = new Card(d);
        for (int i = 0; i < 5; i++) {
            String p = sc.next();
            paul.add(new Card(p));
        }
        sc.close();
    }

    boolean compareAll() {
        for (int i = 0; i < 5; i++) {
            if (dealer.compare(paul.get(i))) {
                return true;
            }
        }
        return false;
    }
}

class Card {
    char[] card = new char[2];

    Card(String aCard) {
        card[0] = aCard.charAt(0);
        card[1] = aCard.charAt(1);
    }

    boolean compare(Card p) {
        return this.card[0] == p.card[0] | this.card[1] == p.card[1];
    }
}
