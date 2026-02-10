public class ArrayList<T> {
    private Object[] items;
    private int size = 0;
    private static final int DEFAULT_CAP = 10;

    public ArrayList() {
        items = new Object[DEFAULT_CAP];
    }
    
    public void add(T element) {
        addCap(size + 1);
        items[size++] = element;
    }

    private void addCap(int minCap)  {
        if (minCap > items.length) {
            int newCap = items.length * 2;
            if (newCap < minCap) {
                newCap = minCap;
            }
            items = java.util.Arrays.copyOf(items, newCap);
        }
    }
    public T remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        T oldValue = (T) items[index];
        int numMoved = size - index - 1;
        if (numMoved > 0) {
            System.arraycopy(items, index + 1, items, index, numMoved);
        }
        items[--size] = null;
        return oldValue;
    }

    public T get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        return (T) items[index];
    }

    public T set(int index, T element) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        T oldValue = (T) items[index];
        items[index] = element;
        return oldValue;
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        if (size == 0) {
            str.append("ArrayList is empty");
        }
        for (int i =0; i<size; i++) {
            str.append(items[i]).append(" ");
        }
        return str.toString();
    }

    public int size() {
        return size;
    }
    public boolean isEmpty() {
        return size == 0;
    }
    public void clear() {
        for (int i = 0; i < size; i++) {
            items[i] = null;
        }
        size = 0;
    }

}
