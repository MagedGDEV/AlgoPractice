class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool isIncreasing = false;
        bool isDecreasing = false;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i+1] > arr[i])
            {
                if (isDecreasing)
                    return false;
                isIncreasing = true;
            }
            else if (arr[i+1] < arr[i])
            {
                if (!isIncreasing)
                    return false;
                isDecreasing = true;
            }
            else 
                return false;
        }
        return isIncreasing && isDecreasing;
    }
};