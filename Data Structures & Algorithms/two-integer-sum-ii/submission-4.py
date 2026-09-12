class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        map = {}

        for i, n in enumerate(numbers):
            diff = target - n
            if diff in map and map[diff] != i:
                return [map[diff] + 1, i + 1]
            map[n] = i
        return []