class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        int *arr = new int[len];
          
        if (!len)
            return false;
        for (int i = 0; i < len; i++)
            arr[i] = sequence[i];
          
        return VerifySquenceOfSubBST(arr, len);
    }
      
    bool VerifySquenceOfSubBST(int *arr, int len) {
        int root = arr[len - 1];
        int i, j;
          
        for (i = 0; i < len - 1; i++)
            if (arr[i] > root)
                break;
        for (j = i; j < len - 1; j++)
            if (arr[j] < root)
                return false;
          
        bool left = true, right = true;
        if (i > 0)
            left = VerifySquenceOfSubBST(arr, i);
        if (j < len - 1)
            right = VerifySquenceOfSubBST(arr + i, len - i - 1);
          
        return left && right;
    }
};