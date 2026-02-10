package ex1_first;
public class Main {
    public static void main(String[] args) {
        var dog = new Dog(2, 50);
        dog.move();
        System.out.println("Возраст собаки в человеческих годах: " + dog.toHumanAge());

        var sheep = new Sheep(5, 100);
        sheep.move();
        System.out.println("Возраст овцы в человеческих годах: " + sheep.toHumanAge());
    }
}
