class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(),0);

        for (int i = temperatures.size() - 2; i >= 0; i--)
        {
            if (temperatures[i+1] > temperatures[i])
                out[i] = 1;
            else 
            {
                int j = i + out[i+1] + 1;
                while (j < temperatures.size())
                {
                    if (temperatures[j] > temperatures[i])
                    {
                        out[i] = j - i;
                        break;
                    }
                    else if (out[j] == 0)
                        j+=1;
                    else
                        j += out[j];
                }
            }
        }
        return out;
    }
};