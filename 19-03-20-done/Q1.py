# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        B = []
        n = len(A)
        for i in range(n):
            s = 1
            for j in range(n):
                if (j != i):
                    s = s * A[j]
            B.append(s)
        return B