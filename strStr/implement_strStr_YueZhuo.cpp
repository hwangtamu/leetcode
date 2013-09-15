class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        for (i = 0; i < (int)strlen(haystack) - (int)strlen(needle) + 1; ++i) {
            j = 0;
            while (needle[j] && haystack[i + j] == needle[j]) ++j;
            if (!needle[j])
                break;
        }
        if (i < (int)strlen(haystack) - (int)strlen(needle) + 1)
            return haystack + i;
        return NULL;
    }
};
