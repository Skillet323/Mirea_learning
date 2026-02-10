public class LinkedIntList {
    private ListNode front;
    public LinkedIntList() {
        this.front = new ListNode();
        front.next = new ListNode();
    }

    public void add(int n) {
        ListNode buff = front.next;
        while (buff.data != Integer.MAX_VALUE) {
            buff = buff.next;
        }
        buff.data = n;
        buff.next = new ListNode();
    }

    public void print(){
        ListNode buff = front.next;
        while(buff.data != Integer.MAX_VALUE) {
            System.out.print(buff.data + " ");
            buff = buff.next;
        }
        System.out.println();
    }
    public void removeAll(LinkedIntList list2){
        ListNode buff = list2.front.next;
        ListNode prev = front;
        ListNode curr = front.next;
        while(curr.data != Integer.MAX_VALUE) {
            if (buff.data < curr.data) {
                while (buff.data < curr.data && buff.data != Integer.MAX_VALUE)
                {
                    buff = buff.next;
                }
            }
            if(buff.data == curr.data) {
                prev.next = prev.next.next;
            }
            if (buff.data > curr.data) {
                prev = prev.next;
            }
            curr = curr.next;
        }

    }
}
