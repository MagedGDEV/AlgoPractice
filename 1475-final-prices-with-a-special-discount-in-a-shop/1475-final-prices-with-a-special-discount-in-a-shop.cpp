class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> out(prices.begin(), prices.end());
        
        for (size_t i = 0; i < prices.size(); i++)
        {
            for (size_t j = i+1; j < prices.size(); j++)
            {
                if (prices[i] >= prices[j])
                {
                    out[i] -= prices[j];
                    break;
                }
            }
        }
        return out;
    }
};