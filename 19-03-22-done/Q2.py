# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        s_new = "%20".join(list(s.split(" ")))
        return s_new