/*
 * @lc app=leetcode id=2784 lang=golang
 *
 * [2784] Check if Array is Good
 */

// @lc code=start
func isGood(nums []int) bool {
	p := 1
	length := len(nums)
	val := 0
	n := length - 1
	tmp := 0
	for p < length {
		val = nums[p]
		for val != p {
			if !(val >= 0 && val < length) {
				return false
			}
			tmp = nums[val]
			if tmp == val {
				if tmp == n {
					if nums[n] != n {
						tmp = nums[n]
						nums[n] = n
					} else if nums[0] != n {
						tmp = nums[0]
						nums[0] = n
					} else {
						return false
					}
				} else {
					return false
				}
			} else {
				nums[val] = val
			}
			val = tmp
		}
		p++
	}
	return nums[0] == n
}

// @lc code=end

