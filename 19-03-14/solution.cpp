bool isMatch(std::string a, std::string b) {

    if(b.size()==0){
        return a.size() == 0;
    }

    bool first_match = a.size() > 0 && (a[0] == b[0] || b[0] == '.');
    if (b.size() >= 2 && b[1] == '*') {
        return (first_match && isMatch(a.substr(1),b)) || isMatch(a, b.substr(2));
    } else {
        return first_match && isMatch(a.substr(1), b.substr(1));
    }
}


std::string longestPalindrome(std::string in){
   if(in.size()==0){
       return in;
   }
   int left,right;
   std::vector<bool> row(in.size());
   std::vector< std::vector<bool> > mat(in.size(),row);
   for(int i=(int)in.size()-2; i >=0; i--) {
       for(int j=i+1; j < in.size(); j++){
           mat[i][j] = in[i] == in[j] && (j-i < 3 || mat[i+1][j-1]);
           if(mat[i][j] && j-i > right-left){
               left=i;
               right=j;
           }
       }
   }
   return in.substr(left, right-left+1);
}
