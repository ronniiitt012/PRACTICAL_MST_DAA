class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        rem = total % p
        if rem == 0:
            return 0
        prefix = 0
        res = len(nums)
        mp = {0: -1}
        for i, num in enumerate(nums):
            prefix = (prefix + num) % p
            target = (prefix - rem + p) % p
            if target in mp:
                res = min(res, i - mp[target])
            mp[prefix] = i
        return res if res < len(nums) else -1
