class Solution {
public:
	void replaceSpace(char *str,int length) {
        int cnt = length+1;
        for(int i = 0; i < length; i++){
            if (str[i]==' ')
                cnt += 1;
        }
        char *ret = (char *)malloc(sizeof(char)*cnt);
        int j=0;
        for(int i = 0; i < length; i++){
            if (str[i]==' '){
                ret[j++]='%';
                ret[j++]='2';
                ret[j++]='0';
            } else {
                ret[j++]=str[i];
            }
        }
        ret[j]='\0';
        for(int i = 0; i < cnt; i++){
            str[i] = ret[i];
        }
	}
};
