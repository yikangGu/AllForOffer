class Solution {
public:
    bool isNumber(const char *s) {
        if(s == nullptr) return false;
        while( *s ==' ')  s++;
        bool numberRight = scanInter(&s);
        if(*s =='.')
        {
            s++;
            numberRight =  postiveInter(&s) || numberRight;
        }
        if(*s == 'e' ||*s == 'E')
        {
            s++;
            numberRight =  numberRight && scanInter(&s) ;
        }
        while( *s ==' ')  s++;
        return (*s=='\0') && numberRight ;

    }
   bool postiveInter( const char** string)
    {
        const char* tmp = *string ;
        while((**string != '\0') && ((**string >= '0') && (**string <= '9'))){
            (*string) ++;


        }
        return (*string >tmp);
    }
      bool scanInter(const char** string)
    {

        if ( **string == '-' || **string == '+')
            (*string) ++;

        return postiveInter(string);
    }
};
