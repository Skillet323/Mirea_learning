import java.util.ArrayList;

class A {
    String name;

    public A(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

class B extends A {
    int value;

    public B(String name, int value) {
        super(name);
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

class C extends A {
    double amount;

    public C(String name, double amount) {
        super(name);
        this.amount = amount;
    }

    public double getAmount() {
        return amount;
    }
}

class D extends C {
    String description;

    public D(String name, double amount, String description) {
        super(name, amount);
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}

class CollectionManager {
    private ArrayList<A> items;

    public CollectionManager() {
        items = new ArrayList<>();
    }

    public void addItem(A item) {
        items.add(item);
    }

    public void displayAll() {
        for (A item : items) {
            System.out.println(item.getName());
        }
    }

    public void displayExceptA() {
        for (A item : items) {
            if (!(item instanceof A && !(item instanceof B) && !(item instanceof C)
                    && !(item instanceof D))) {
                System.out.println(item.getName());
            }
        }
    }

    public void displayExceptD() {
        for (A item : items) {
            if (!(item instanceof D)) {
                System.out.println(item.getName());
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        CollectionManager manager = new CollectionManager();
        A a1 = new A("A1");
        A a2 = new A("A2");
        B b1 = new B("B1", 10);
        B b2 = new B("B2", 20);
        C c1 = new C("C1", 30.5);
        C c2 = new C("C2", 40.5);
        D d1 = new D("D1", 50.5, "Description D1");

        manager.addItem(a1);
        manager.addItem(a2);
        manager.addItem(b1);
        manager.addItem(b2);
        manager.addItem(c1);
        manager.addItem(c2);
        manager.addItem(d1);

        System.out.println("Все элементы:");
        manager.displayAll();

        System.out.println("\nЭлементы, кроме A:");
        manager.displayExceptA();

        System.out.println("\nЭлементы, кроме D:");
        manager.displayExceptD();
    }
}
