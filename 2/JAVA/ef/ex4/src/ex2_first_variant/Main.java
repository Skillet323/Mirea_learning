package ex2_first_variant;
public class Main {
    public static void main(String[] args) {
        var solver1 = new Solver(1,3,5);
        System.out.println("Первое уравнение: " + solver1.A +"*x^2 + " + solver1.B + "*x + " + solver1.C + " = 0");
        solver1.solve();
        System.out.println();

        var solver2 = new Solver(0,2,6);
        System.out.println("Второе уравнение: " + solver2.A +"*x^2 + " + solver2.B + "*x + " + solver2.C + " = 0");
        solver2.solve();
        System.out.println();

        var solver3 = new Solver(1,5,3);
        System.out.println("Третье уравнение: " + solver3.A +"*x^2 + " + solver3.B + "*x + " + solver3.C + " = 0");
        solver3.solve();
        System.out.println();

        var solver4 = new Solver(1,-3,-6.75);
        System.out.println("Четвёртое уравнение: " + solver4.A +"*x^2 + " + solver4.B + "*x + " + solver4.C + " = 0");
        solver4.solve();
        System.out.println();

        var solver5 = new Solver(1,5,6);
        System.out.println("Пятое уравнение: " + solver5.A +"*x^2 + " + solver5.B + "*x + " + solver5.C + " = 0");
        solver5.solve();
        System.out.println();
    }
}