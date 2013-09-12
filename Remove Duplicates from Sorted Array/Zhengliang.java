public class Solution {
    public int removeDuplicates(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int max = Integer.MIN_VALUE;
        int count = 0;
        for (int i : A) {
            if (max != i) {
                max = i;
                A[count++] = max;
            }
        }
        return count;
    }
}