public class Solution {
    public int removeElement(int[] A, int elem) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int count = 0;
        for (int i : A) if (elem != i) A[count++] = i;
        return count;
    }
}