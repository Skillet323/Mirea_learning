package ex2_first_variant;

import static java.lang.Math.sqrt;

abstract public class QuadraticEquation {
    protected double A;
    protected double B;
    protected double C;

    abstract void solve();

    public QuadraticEquation(double A, double B, double C){
        this.A = A;
        this.B = B;
        this.C = C;
    }
}

class Solver extends QuadraticEquation{

    public Solver(double A, double B, double C) {
        super(A, B, C);
    }
    @Override
    void solve() {
        if(A == 0){
            double x = -C / B;
            System.out.println("Корень уравнения: " + x);
            return;
        }
        double Discriminant = B*B - 4*A*C;

        if (Discriminant < 0){
            System.out.println("Решений нет");
        }
        if (Discriminant == 0){
            double x = -B / 2*A;
            System.out.println("Корень уравнения: " + x);
            return;
        }
        if(Discriminant > 0){
            double x1 = (-B - sqrt(Discriminant)) / 2*A;
            double x2 = (-B + sqrt(Discriminant)) / 2*A;
            System.out.println("Первый корень уравнения: " + x1);
            System.out.println("Второй корень уравнения: " + x2);
        }
    }
}