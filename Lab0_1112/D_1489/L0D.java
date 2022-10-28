package D_1489;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class L0D {
    static int number;
    static ArrayList<Tiles> players = new ArrayList<>();

    public static void main(String[] args) {
        read();
        for (int i = 0; i < players.size(); i++) {
            System.out.println(players.get(i));
        }
    }

    static void read() {
        Scanner sc = new Scanner(System.in);
        number = sc.nextInt();
        for (int i = 0; i < number; i++) {
            String player = sc.next();
            players.add(new Tiles(player));
        }
        sc.close();
    }
}

class Tiles {
    boolean win;
    ArrayList<Integer> mah = new ArrayList<>();

    public Tiles(String s) {
        for (int i = 0; i < 27; i += 2) {
            int num = s.charAt(i) - '0';
            char type = s.charAt(i + 1);
            if (type == 'b') {
                mah.add(num);
            } else if ((type == 's')) {
                mah.add(num + 10);
            } else if ((type == 'w')) {
                mah.add(num + 20);
            } else if ((type == 'z')) {
                mah.add(num + 30);
            }
        }
        Collections.sort(mah);
        win = hu(mah);
    }

    static boolean hu(ArrayList<Integer> mah) {
        for (int num = 1; num <= 37; num++) {
            for (int i = 0; i < mah.size() - 1; i++) {
                if (mah.get(i) == num && mah.get(i + 1) == num) {
                    ArrayList<Integer> qRemove = new ArrayList<>(mah);
                    qRemove.remove(i);
                    qRemove.remove(i);
                    if (checkKeZiShunZi(qRemove)) return true;
                }
            }
        }
        return false;
    }

    static boolean checkKeZiShunZi(ArrayList<Integer> qRemoved) {
        while (true) {
            if (qRemoved.size() == 0) {
                return true;
            } else if (qRemoved.size() < 3) {
                return false;
            } else {
                int a = qRemoved.get(0);
                int b = qRemoved.get(1);
                int c = qRemoved.get(2);
                if (a < 30) {
                    if (a == b && a == c) {
                        qRemoved.remove(0);
                        qRemoved.remove(0);
                        qRemoved.remove(0);
                    } else if (qRemoved.contains(a + 1) && qRemoved.contains(a + 2)) {
                        qRemoved.remove((Integer) a);
                        qRemoved.remove((Integer) (a + 1));
                        qRemoved.remove((Integer) (a + 2));
                    } else return false;
                } else {
                    if (a == b && a == c) {
                        qRemoved.remove(0);
                        qRemoved.remove(0);
                        qRemoved.remove(0);
                    } else return false;
                }
            }
        }
    }

    @Override
    public String toString() {
        if (win) {
            return "Blessing of Heaven";
        } else {
            return "Bad luck";
        }
    }
}