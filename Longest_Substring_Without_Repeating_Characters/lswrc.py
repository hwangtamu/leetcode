class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        a = 0
        b = 1
        length = 0
        while b <= len(s):
            if len(set(s[a:b])) == b - a:
                length = max(length,(b-a))
                b = b + 1
            else:
                a = a + 1
                b = b + 1
        return length
