class Solution:
    def getDeepth(self, Root):
        if Root is None:
            return 0
        nright = self.getDeepth(Root.right)
        nleft = self.getDeepth(Root.left)
        return max(nright, nleft)+1
    def IsBalanced_Solution(self, pRoot):
        if pRoot is None:
            return True
        right = self.getDeepth(pRoot.right)
        left = self.getDeepth(pRoot.left)
        if abs(right - left) >1:
            return False
        return self.IsBalanced_Solution(pRoot.right) and self.IsBalanced_Solution(pRoot.left)
