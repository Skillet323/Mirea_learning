public class Name<T> {
    private T v;

    public Name(T v) {
        this.v = v;
    }

    public String toString() {
        return v.toString();
    }

    public static void main(String[] args) {
        Name<String> name1 = new Name<>("привет");
        System.out.println(name1);

        Name<Integer> name2 = new Name<>(126);
        System.out.println(name2);

        Name<Double> name3 = new Name<>(4567.789);
        System.out.println(name3);

        Name<Boolean> name4 = new Name<>(true);
        System.out.println(name4);

    }
}
