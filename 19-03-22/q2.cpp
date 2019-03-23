class Solution {
public:
    int howManyBlank(char *str, int length){
        int num = 0;
        for(int i=0; i<length; i++){
            if(str[i] == ' ')
                num++;
        }
        return num;
    }
	void replaceSpace(char *str,int length) {
        int numBlank = howManyBlank(str, length);
        int p1 = length;
        int p2 = length + 2*numBlank;
        while(p1>=0 && p1 != p2){
            if(str[p1] != ' '){
                str[p2--] = str[p1--];
            }
            else{
                str[p2--]='0';
                str[p2--]='2';
                str[p2--]='%';
                p1--;
            }
        }
	}
};
