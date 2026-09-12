class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closetoopen = {')': '(', '}': '{', ']': '['}

        for c in s:
            if c in closetoopen: # check if c is a key of the dictionary, not values
                if stack and stack[-1] == closetoopen.get(c): # stack not empty = True; stack[-1] = last element
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return not stack