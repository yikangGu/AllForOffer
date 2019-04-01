class Solution {
public:
    bool isNumber(const char *s) {
 
 
    string str(s);
   int index = str.find_first_not_of(' ');
   if(str[index] == '+' || str[index] == '-')
      index++;
   int points = 0,numbers = 0;
   for(;str[index]>='0' && str[index]<='9' || str[index]=='.';index++)
      s[index] == '.' ? ++points : ++ numbers;
   if(points>1 || numbers<1)
     return false;
  
   if(str[index] == 'e' || str[index] == 'E')
   {
      index++;
      if(str[index] == '+' || str[index] == '-')
        index++;
      int afterE =0;
      for(;str[index]>='0' && str[index]<='9';index++)
        afterE++;
      if(afterE<1)
        return false;
   }
   for(;str[index]==' ';index++){}
   return str[index]=='\0';
    }
};
