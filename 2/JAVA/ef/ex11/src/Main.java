import java.util.LinkedList;
import java.util.Queue;
class StackOnQueue {
    private Queue<Integer> primaryQueue;
    private Queue<Integer> secondaryQueue;
    public StackOnQueue() {
        primaryQueue = new LinkedList<Integer>();
        secondaryQueue = new LinkedList<Integer>();
    }
    public void push(int value) {
        if (primaryQueue.isEmpty()) {
            primaryQueue.add(value);
        } else {
            int size = primaryQueue.size();
            for (int i = 0; i < size; i++) {
                secondaryQueue.add(primaryQueue.poll());
            }
            primaryQueue.add(value);
            for (int i = 0; i < size; i++) {
                primaryQueue.add(secondaryQueue.poll());
            }
        }
    }
    public int pop() {
        return primaryQueue.poll();
    }
    public int top() {
        return primaryQueue.peek();
    }
    public boolean isEmpty() {
        return primaryQueue.isEmpty();
    }
    public void print() {
        if (primaryQueue.isEmpty()) {
            System.out.println("Элементов в стеке нет");
            return;
        }
        String stackElements = primaryQueue.toString();
        System.out.println("Элементы стека: " + stackElements.substring(1, stackElements.length() - 1));
    }
}

class TestMyStack {
    public static void test() {
        StackOnQueue stack = new StackOnQueue();
        stack.push(14);
        stack.push(87);
        System.out.println("1 элемент стека: " + stack.top());
        System.out.println("1 элемент стека (с удалением): " + stack.pop());
        System.out.println("Пустой ли стек?: " + stack.isEmpty());
        stack.print();
    }
}

public class Main {
    public static void main(String[] args) {
        TestMyStack.test();
    }
}
