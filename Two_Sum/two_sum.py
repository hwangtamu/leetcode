class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        num_s = sorted(num)
        a = 0
        b = len(num) - 1
        while num_s[a] + num_s[b] != target:
            if num_s[a] + num_s[b] < target:
                a = a + 1
            if num_s[a] + num_s[b] > target:
                b = b - 1
        index1 = num.index(num_s[a]) + 1
        index2 = num.index(num_s[b]) + 1
        if index1 == index2:
            index2 = num[index1:].index(num_s[b]) + index1 + 1
        return tuple(sorted([index1,index2]))
        
