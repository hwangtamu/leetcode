package mergeLists;

public class mergeTwoLists {
	/**
	 * Definition for singly-linked list. public class ListNode { int val;
	 * ListNode next; ListNode(int x) { val = x; next = null; } }
	 */

	public class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
			next = null;
		}
	};

	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		// Note: The Solution object is instantiated only once and is reused by
		// each test case.
		ListNode tmp1 = l1;
		ListNode tmp2 = l2;
		ListNode result, tail;
		if (l1 == null) return l2;
		if (l2 == null) return l1;
		if(tmp1.val < tmp2.val) {
			result = tmp1;
			tmp1 = tmp1.next;
		} else {
			result = tmp2;
			tmp2 = tmp2.next;
		}
		tail = result;
		while (tmp1 != null && tmp2 != null) {
			if(tmp1.val < tmp2.val) {
				tail.next = tmp1;
				tmp1 = tmp1.next;
			} else {
				tail.next = tmp2;
				tmp2 = tmp2.next;
			}
			tail = tail.next;
		}
		for (; tmp1 != null; tmp1 = tmp1.next, tail =tail.next) {
			tail.next = tmp1;
		}
		for (; tmp2 != null; tmp2 = tmp2.next, tail =tail.next) {
			tail.next = tmp2;
		}
		return result;
	}
}
