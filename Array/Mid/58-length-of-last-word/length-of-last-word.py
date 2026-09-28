class Solution:
    def lengthOfLastWord(self, s: str) -> int:
            string= s.split()
            n = string[-1]
            return len(n)