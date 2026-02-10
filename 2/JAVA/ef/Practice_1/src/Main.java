import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        final double ROEUBLES_PER_YUAN = 11.91;
        int yuan = input.nextInt();
        int digit = yuan % 10;
        double roubles = Math.ceil(ROEUBLES_PER_YUAN*yuan);
        System.out.println((int) roubles);
        input.close();
    }
}

