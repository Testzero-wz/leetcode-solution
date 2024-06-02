#
# @lc app=leetcode id=165 lang=python3
#
# [165] Compare Version Numbers
#


# @lc code=start
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        nums1 = version1.split(".")
        nums2 = version2.split(".")
        for i in range(max(len(nums1), len(nums2))):
            n1 = "0" if i >= len(nums1) else nums1[i]
            n2 = "0" if i >= len(nums2) else nums2[i]
            res = Solution.comp_num(n1, n2)
            if res != 0:
                return res
        return 0

    @staticmethod
    def comp_num(s1: str, s2: str):
        max_l = max(len(s1), len(s2))
        format_string = "{:0>%d}" % max_l
        s1 = format_string.format(s1)
        s2 = format_string.format(s2)
        for i in range(max_l):
            if s1[i] > s2[i]:
                return 1
            elif s1[i] < s2[i]:
                return -1
        return 0


# @lc code=end
