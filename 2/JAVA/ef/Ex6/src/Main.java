import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Введите ФИО: ");
        String Fio = sc.nextLine();
        try {
            FIO.verification(Fio);
            System.out.println("Введенные данные корректны");
        } catch (FIO.FioException e) {
            System.out.println(e.getMessage());
        }
    }
}
