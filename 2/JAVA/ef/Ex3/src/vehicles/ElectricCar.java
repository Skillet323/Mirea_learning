package vehicles;

public class ElectricCar extends Car{
    private int batteryCapacity;

    public ElectricCar(String ownerName, String insuranceNumber) {
        super(ownerName, insuranceNumber, "Electric");
        batteryCapacity = 100;

    }

    public int getBatteryCapacity() {
        return batteryCapacity;
    }

    public void setBatteryCapacity(int batteryCapacity) {
        this.batteryCapacity = batteryCapacity;
    }
}
