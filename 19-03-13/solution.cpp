    int maxArea(vector<int>& height){
        int ret = 0;
        for (int i=0; i < height.size(); i++)
            for (int j = i+1; j < height.size(); j++)
                ret = max(min(height[i],height[j])*(j-i),ret);

        return ret;
    }

    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) {
            return 0;
        }

        int cur_min = INT_MAX;
        int max_profit = 0;
        for(int i = 0; i < prices.size(); i++){
            cur_min = min(cur_min, prices[i]);
            max_profit = max(max_profit, prices[i] - cur_min);
        }
        return max_profit;
    }
