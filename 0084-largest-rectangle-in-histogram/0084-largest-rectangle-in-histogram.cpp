class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> s;
        for (size_t i = 0; i <= heights.size(); i++)
        {
            int currH = i == heights.size() ? 0 : heights[i];

            while (!s.empty() && currH < heights[s.top()])
            {
                int h = heights[s.top()]; s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h*w);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};