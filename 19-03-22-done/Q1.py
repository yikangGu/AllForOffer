# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.char_list = [-1 for i in range(256)]
        self.index = 0  # 记录当前字符的个数
 
    def FirstAppearingOnce(self):
        # write code here
        min_value = 500
        min_idx = -1
        for i in range(256):
            if self.char_list[i] > -1:
                if self.char_list[i] < min_value:
                    min_value = self.char_list[i]
                    min_idx = i
        if min_idx > -1:
            return chr(min_idx)
        else:
            return '#'
 
    def Insert(self, char):
        # 如果是第一出现，则将对应元素的值改为下边
        if self.char_list[ord(char)] == -1:
            self.char_list[ord(char)] = self.index
        # 如果已经出现过两次了，则不修改
        elif self.char_list[ord(char)] == -2:
            pass
        # 如果出现过一次，则进行修改，修改为-2
        else:
            self.char_list[ord(char)] = -2
        self.index += 1