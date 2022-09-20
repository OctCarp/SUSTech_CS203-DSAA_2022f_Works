package Q2_1484;

import java.util.ArrayList;
import java.util.Scanner;

public class L0Q2 {
    static Card dealer;
    static ArrayList<Card> paul = new ArrayList<>();

    public static void main(String[] args) {
        boolean allSame;
        initial();
        allSame = compareAll();
        if (allSame) {
            System.out.println("All in");
        } else {
            System.out.println("Fold");
        }
    }

    static void initial() {
        Scanner sc = new Scanner(System.in);
        String d = sc.next();
        dealer = new Card(d);
        for (int i = 0; i < 5; i++) {
            String p = sc.next();
            paul.add(new Card(p));
        }
        sc.close();
    }

    static boolean compareAll() {
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

    public Card(String aCard) {
        card[0] = aCard.charAt(0);
        card[1] = aCard.charAt(1);
    }

    public boolean compare(Card p) {
        return this.card[0] == p.card[0] | this.card[1] == p.card[1];
    }
}
