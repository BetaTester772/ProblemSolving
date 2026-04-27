import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static long fac(long x) {
        if (x <= 1)
            return 1;
        return fac(x - 1) * x;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System.out.println(fac(n));
    }
}
