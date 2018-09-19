/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
    	if (head == null) {
    		return null;
    	}
    	ListNode odd = head;
    	ListNode even = head.next;
    	ListNode even_head = head.next;
    	while (even != null && even.next != null) {
    		odd.next = odd.next.next;
    		even.next = even.next.next;
    		odd = odd.next;
    		even = even.next;
    	}
        odd.next = even_head;
        return head;
    }
}