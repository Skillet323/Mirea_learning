import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var input = new Scanner(System.in);
        int n;
        System.out.print("Введите максимальное значение для чисел(от 0): ");
        n = input.nextInt();
        var example = new Array(n);

        System.out.print("Введите количество чисел для добавления: ");
        int temporary = input.nextInt();
        int elem;
        for(int i = 0; i < temporary; i++) {
            //System.out.print((i + 1) + ". ");
            elem = i;
            example.push(elem);
        }
        example.print_array();

        System.out.print("Введите число, которое надо найти: ");
        int key = input.nextInt();
        example.find(key);

        System.out.print("Введите число, которое надо удалить: ");
        elem = input.nextInt();
        example.remove(elem);
        example.print_array();

        input.close();
    }
}
