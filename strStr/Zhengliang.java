public class Solution {
    public String strStr(String haystack, String needle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int nLen = needle.length();
        int hLen = haystack.length();
        for (int i = 0; i <= hLen - nLen; i++) 
          if (haystack.substring(i, i + nLen).equals(needle))
            return haystack.substring(i);
        return null;
    }
}