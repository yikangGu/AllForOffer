class Solution {
public:
    bool isNumber(const char *s) {
        enum InputType {
            INVALID, SPACE, SIGN, DOT, E, DIGIT, LEN
        };
        int trans[][LEN] = {
            {-1,  0,  1,  2, -1,  3},//状态0：初始 | 初始+空格                                                                       错误
            {-1, -1, -1,  2, -1,  3},//状态1：符号                                                                                   错误
            {-1, -1, -1, -1, -1,  4},//状态2：点 | 符号+点                                                                           错误
            {-1,  5, -1,  4,  6,  3},//状态3：数字 | 符号+数字                                                                       正确
            {-1,  5, -1, -1,  6,  4},//状态4：点+数字 | 符号+点+数字 | 符号+数字+点 | 数字+点                                        正确
            {-1,  5, -1, -1, -1, -1},//状态5：数字+空格 | 符号+数字+空格                                                             正确
            {-1, -1,  7, -1, -1,  8},//状态6：数字+e | 符号+数字+e | 点+数字+e | 符号+点+数字+e | 数字+点+e                          错误
            {-1, -1, -1, -1, -1,  8},//状态7：数字+e+符号 | 符号+数字+e+符号 | 点+数字+e+符号 | 符号+点+数字+e+符号 | 数字+点+e+符号 错误
            {-1,  5, -1, -1, -1,  8} //状态8：状态6+数字 | 状态7+数字                                                                正确
        };
        int state = 0;
        while (*s) {
            InputType input;
            if (*s == ' ') {
                input = SPACE;
            } else if (*s == '+' || *s == '-') {
                input = SIGN;
            } else if (*s == '.') {
                input = DOT;
            } else if (*s == 'e' || *s == 'E') {
                input = E;
            } else if (*s >= '0' && *s <= '9') {
                input = DIGIT;
            } else {
                input = INVALID;
            }
            state = trans[state][input];
            if (state == -1) {
                return false;
            }
            s++;
        }
        return state == 3 || state == 4 || state == 5 || state == 8;
    }
};
