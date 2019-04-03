vector<int> findSubString(string s, vector<string>& words){
  unordered_map<string, int> numbers;
  for(auto word : words)
    numbers[word]++;
  int slen = s.length(), num = words.size(), len = words[0].length();
  vector<int> ids;
  for(int i = 0; i < slen  - num * len + 1; i++){
    //从i处开始遍历，存下在i处开始的字符里单词的个数
    unordered_map<string, int> iNumbers;
    int tmp = 0;
    for(; tmp < num; tmp++){
      string word = s.substr(i + tmp * len, len);//以i为起点，长度为len的第tmp个单词
      if(iNumber.find(word) != iNumber.end()) {
        iNumber[word]++;
        if(iNumber[word] > numbers[word])
          break;//发现了超过需求数量的单词
      }
      else
        break;//没有找到需要的单词
    }
    if(tmp == num) ids.emplace_back(i);
  }
  return ids;
}
