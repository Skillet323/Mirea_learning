/*import java.util.Scanner;

public class Fibonacci {

    public static void main(String[] args) throws InterruptedException{
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите номер числа Фибоначчи(начиная с 1): ");
        int n = scanner.nextInt();
        
        FibonacciThread minus1 = new FibonacciThread(n - 1);
        FibonacciThread minus2 = new FibonacciThread(n - 2);
        
        minus1.start();
        minus2.start();

        minus1.join();
        minus2.join();
        int fibN = minus1.getFibonacci() + minus2.getFibonacci();
        System.out.println("Результат " + fibN);

    }
    
    private static class FibonacciThread extends Thread {
        private final int n;
        private int fibonacci;
        public FibonacciThread(int n) {
            this.n = n;
        }
        @Override
        public void run() {
            fibonacci = fibonacci(n);
        }
        public int getFibonacci() {
            return fibonacci;
        }
        private int fibonacci(int n) {
            if (n <= 0) {
                return 0;
            }

            int[] fib = new int[n + 1];
            fib[0] = 0;
            fib[1] = 1;

            for (int i = 2; i <= n; i++) {
                fib[i] = fib[i - 1] + fib[i - 2];
            }
            return fib[n];
        }
    }
}
*/