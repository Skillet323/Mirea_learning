import java.util.*;
public class Main {
    /*
    public static void main(String[] args) {
        double[] list1 = {1.5,6,7,9,0};
        double[] list2 = {3,6,8};
        double [] res = alternate(list1,list2);
        for (int i =0; i<res.length;i++){
            System.out.print(res[i]+" ");
        }

    }
    static public double[] alternate(double[] list1, double[] list2){
        int l1 = Math.min(list1.length,list2.length);
        int l2 = Math.max(list1.length,list2.length);
        double[] result = new double[l1+l2];
        int j =0;
        for(int i=0; i<l1; i++){
            result[j] = list1[i];
            result[j+1] = list2[i];
            j+=2;
        }
        double[] list = l1==list1.length ? list2 : list1;
        for(int i=l1; i<l2; i++){
            result[j] = list[i];
            j++;
        }
        return result;
    }
    */

    /*
    public static void main(String[] args) {
        Map<Integer, String> map = new HashMap<>();
        map.put(1, "9");
        map.put(2, "8");
        map.put(3, "7");
        map.put(4, "6");
        map.put(5, "6");
        System.out.println(map.keySet());
        System.out.println(reverse(map));
    }
    public static Map<String,Integer> reverse(Map<Integer, String> map) {
        Map<String,Integer> reversed = new HashMap<>();
        String[] Values  = map.values().toArray(new String[0]);
        Integer[] Keys = map.keySet().toArray(new Integer[0]);
        for (int i = Values.length-1; i >=0 ; i--) {
            reversed.put(Values[i],Keys[i]);
        }
        return reversed;
    }
    */

    /*
    public static void main(String[] args) {
        Map<String, String> map1 = new HashMap<>();
        Map<String, String> map2 = new HashMap<>();
        map1.put("a","b");
        map1.put("a","b");
        map1.put("c","b");
        map2.put("a","b");
        map2.put("a","b");
        map2.put("c","d");
        System.out.println(isUnique(map1));
        System.out.println(isUnique(map2));
        Map<String, String> map3 = new HashMap<>();
        System.out.println(isUnique(map3));
    }
    public static boolean isUnique(Map<String, String> map){
        String[] keys = map.keySet().toArray(new String[map.size()]);
        for(String key1 : keys){
            for(String key2 : keys){
                if(!key1.equals(key2) && map.get(key1).equals(map.get(key2))){
                    return false;
                }
            }
        }
        return true;
    }
    */

    /*
    public static void main(String[] args) {
        Set<Integer> set = new HashSet<>();
        System.out.println(hasOdd(set));
    }
    public static boolean hasOdd(Set<Integer> set) {
        for (Integer i : set) {
            if (i % 2 != 0) {
                return true;
            }
        }
        return false;
    }
     */

    /*
    public static void main(String[] args) throws Exception {
        Map<String, Integer> map = new HashMap<>();
        map.put("a", 1);
        map.put("b", 1);
        map.put("c", 2);
        map.put("d", 2);
        map.put("e", 2);
        System.out.println(rarest(map));
    }
    public static Integer rarest(Map<String,Integer> map) throws Exception{
        if(map.isEmpty()){
            throw new Exception("Dictionary is empty");
        }
        Map<Integer, Integer> counts = new HashMap<>();
        for (Integer item : map.values()) {
            if(!counts.containsKey(item)){
                counts.put(item, 1);
                continue;
            }
            counts.replace(item, counts.get(item) + 1);
        }
        int index = Integer.MAX_VALUE;
        for (Integer item : counts.values()) {
            index = Math.min(index,item);
        }
        int result = 0;
        for (Integer key : counts.keySet()) {
            if(counts.get(key)==index){
                result = key;
            }
        }
        return result;
    }
     */

    /*
    public static void main(String[] args) {
        String[] arr = {"Farm", "Zoo", "Car", "Apple", "Bee", "Golf", "Bee", "Dog", "Golf", "Zoo", "Zoo", "Bee", "Bee", "Apple"};
        String[] sorted = guavaSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(sorted[i]);
        }
    }
    public static String[] guavaSort(String[] array) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < array.length; i++) {
            if (map.containsKey(array[i])) {
                map.replace(array[i], map.get(array[i]) + 1);
                continue;
            }
            map.put(array[i], 1);
        }
        String[] sortedArray = new String[array.length];
        int i = 0;
        for (String s : map.keySet()) {
            int j = map.get(s) + i;
            for (;i<j;i++){
                sortedArray[i] = s;
            }
        }
        sortedArray = Arrays.stream(sortedArray).sorted().toArray(String[]::new);
        return sortedArray;
    }
     */

    public static void main(String[] args) {
        LinkedIntList list1 = new LinkedIntList();
        LinkedIntList list2 = new LinkedIntList();
        list1.add(1);
        list1.add(3);
        list1.add(5);
        list1.add(7);
        list2.add(1);
        list2.add(2);
        list2.add(3);
        list2.add(4);
        list2.add(5);
        System.out.print("list1 ");
        list1.print();
        System.out.print("list2 ");
        list2.print();
        System.out.println();
        list2.removeAll(list1);//Расскоментировать для 1 случая
        System.out.print("list1 ");
        list1.print();
        System.out.print("list2 ");
        list2.print();

    }


}
