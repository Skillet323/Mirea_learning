package vehicles.app;


import vehicles.Car;
import vehicles.ElectricCar;

public class Main {
    public static void main(String[] args) {
        var car = new Car("Владимир", "2317462475", "Petrol");
        var electricCar = new ElectricCar("Игорь", "7621856897");

        System.out.println(car.getOwnerName());
        car.setOwnerName("Игорь");
        System.out.println(car.getOwnerName());

        System.out.println(car.getEngineType());

        System.out.println(electricCar.getEngineType());
        System.out.println(electricCar.getBatteryCapacity());
        electricCar.setBatteryCapacity(56);
        System.out.println(electricCar.getBatteryCapacity());
    }
}

