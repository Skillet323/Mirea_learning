public class Main {
    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(4);
        list.add(3);
        System.out.println(list.toString());

        list.set(1, 17);
        System.out.println(list.toString());

        list.remove(2);
        System.out.println(list.toString());

        System.out.println(list.isEmpty());

        list.clear();
        System.out.println(list.toString());
        System.out.println(list.isEmpty());
    }
}