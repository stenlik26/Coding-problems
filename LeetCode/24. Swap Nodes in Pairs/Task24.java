import java.util.List;

class Task24 {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode headCopy = head;
        head = head.next;
        headCopy.next = swapPairs(head.next);
        head.next = headCopy;

        return head;
    }

    public static void main(String[] args) {
        Task24 x = new Task24();
        System.out.println(x.swapPairs(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))))));
    }
}