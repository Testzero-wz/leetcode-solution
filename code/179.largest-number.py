#
# @lc app=leetcode id=179 lang=python3
#
# [179] Largest Number
#


# @lc code=start
class Solution:
    class MyNum(str):
        def __lt__(self, value: str) -> bool:
            return self + value < value + self

    def largestNumber(self, nums: List[int]) -> str:

        l = sorted(
            map(lambda x: str(x), nums),
            key=lambda x: Solution.MyNum(x),
            reverse=True,
        )
        if l[0] == "0":
            return "0"

        return "".join(l)


# @lc code=end
