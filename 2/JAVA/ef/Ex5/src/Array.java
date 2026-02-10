public class Array {
    private int n;
    private boolean[] array;
    public Array(int size) {
        this.n = size;
        this.array = new boolean[size];
    }
    public void push(int element) {
        if(0 <= element && element < n) {
            if(array[element]) {System.out.println("Число " + element + " уже есть в множестве");
            } else {array[element] = true;}
        }
        else {System.out.println("Число " + element + " выходит за границы диапазона");}
    }
    public void remove(int element) {
        if(element >= n) {return;}
        if(array[element]) {array[element] = false;}
    }
    public void find(int element) {
        if(element >= n) {System.out.println("Данного числа нет в множестве");
            return;
        }
        if(array[element]) {System.out.println("Данное число присутствует в множестве");}
        else {System.out.println("Данного числа нет в множестве");}
    }
    public void print_array() {
        System.out.print("Все элементы множества:");
        for(int i = 0; i < n; i++) {
            if(array[i]) {System.out.print(" " + i);}
        }
        System.out.println(".");
    }
}