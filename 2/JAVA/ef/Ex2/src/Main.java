public class Main {
    public static void main(String[] args) {
        Car car = new Car("Toyota Corolla Cross ", "D789VR", "Синий", 2022);
        car.To_String();
        System.out.println("Возраст автомобиля: "+ car.carAge());
        car.setColor("Черный");
        System.out.println("Цвет автомобиля после покраски: "+ car.getColor());
    }
}
class Car {
    private String model, license, color;
    private int year;
    final int thisYear = 2024;
    public void To_String(){
        System.out.println("Модель автомобиля: "+ getModel());
        System.out.println("Номер автомобиля: "+ getlicens());
        System.out.println("Цвет автомобиля: "+ getColor());
        System.out.println("Год выпуска автомобиля: "+ getYear());
    }
    Car(String model, String license, String color, int year){
        this.model = model;
        this.license = license;
        this.color = color;
        this.year = year;
    }
    Car(){}
    Car(String model, String license){
        this.model = model;
        this.license = license;
    }
    public String getModel() {
        return model;
    }
    public void setModel(String model) {
        this.model = model;
    }
    public String getlicens() {
        return license;
    }
    public void setlicensen(String license) {
        this.license = license;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
    public int getYear() {
        return year;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public int carAge(){
        return thisYear - year;
    }
}
