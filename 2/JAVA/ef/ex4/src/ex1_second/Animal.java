package ex1_second;
abstract class Animal{
    protected int _age;
    protected int _size;
    abstract int toHumanAge();
    public void set_age(int _age) {
        this._age = _age;
    }
    public void set_size(int _size) {
        this._size = _size;
    }
    public int get_age() {
        return _age;
    }
    public int get_size() {
        return _size;
    }
    public Animal(int _age, int _size){
        this._age = _age;
        this._size = _size;
    }
}
class Dog extends Animal implements Movable {
    public Dog(int _age, int _size) {
        super(_age, _size);
    }
    @Override
    public void move() {
        System.out.println("Собака бежит");
    }
    @Override
    int toHumanAge() {
        return get_age()*7;
    }
}

class Sheep extends Animal implements Movable{
    public Sheep(int _age, int _size) {
        super(_age, _size);
    }
    @Override
    public void move() {
        System.out.println("Овца идёт");
    }
    @Override
    int toHumanAge() {
        return get_age()*4;
    }
}
