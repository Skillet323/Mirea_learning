abstract class Beverage {
    public final void prepare() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    protected abstract void brew();
    protected abstract void addCondiments();


    private void boilWater() {
        System.out.println("Кипятим воду");
    }

    private void pourInCup() {
        System.out.println("Наливаем напиток в чашку");
    }
}

class Tea extends Beverage {
    @Override
    protected void brew() {
        System.out.println("Завариваем чайные листья");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Добавляем лимон");
    }
}

class Coffee extends Beverage {
    @Override
    protected void brew() {
        System.out.println("Завариваем кофейные зерна");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Добавляем сахар и молоко");
    }
}

public class Main {
    public static void main(String[] args) {
        Beverage tea = new Tea();
        System.out.println("Приготовление чая:");
        tea.prepare();

        System.out.println();

        Beverage coffee = new Coffee();
        System.out.println("Приготовление кофе:");
        coffee.prepare();
    }
}
