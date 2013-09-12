public class Solution {
    public void swap(int[] num, int index1, int index2) {
        int tmp = num[index1];
        num[index1] = num[index2];
        num[index2] = tmp;
    }
	
	public void reverse(int[] num, int n) {
        for (int i = 1; n + i + i < num.length; i++) swap(num, n+i, num.length-i);
    }
	
	public void adjust(int[] num, int n) {
		int i = 1;
		for (; (n + i < num.length) && num[n] < num[n + i]; i++);
		swap(num, n, n + i - 1);
	}
	
	public void nextPermutation(int[] num) {
		// Start typing your Java solution below
		// DO NOT write main() function
		for (int i = num.length - 1; i > 0; i--) {
			if (num[i - 1] < num[i]) {
				adjust(num, i - 1);
				reverse(num, i - 1);
				return;
			}
		}
		reverse(num, -1);
	}
}




