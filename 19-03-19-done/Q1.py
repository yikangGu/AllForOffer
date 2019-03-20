# -*- coding:utf-8 -*-
 
class Palindrome:
    def getLongestPalindrome(self, A, n):
        # write code here
        A='#'+'#'.join(A)+'#'
        n=len(A)
        RL=[0]*n
        MaxRight=0
        pos=0
        MaxLen=0
        for i in range(n):
            if i<MaxRight:
                RL[i]=min(RL[2*pos-i], MaxRight-i)
            else:
                RL[i]=1
            while i-RL[i]>=0 and i+RL[i]<n and A[i-RL[i]]==A[i+RL[i]]:
                RL[i]+=1
            if RL[i]+i-1>MaxRight:
                MaxRight=RL[i]+i-1
                pos=i
            MaxLen=max(MaxLen, RL[i])
        return MaxLen-1
