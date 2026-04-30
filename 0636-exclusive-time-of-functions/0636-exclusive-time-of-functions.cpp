class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> out(n, 0);
        stack<pair<int,int>> s; // {id, startTime}
        int prev = 0;

        for (auto& log : logs)
        {
            int id = stoi(log.substr(0, log.find(':')));
            int t  = stoi(log.substr(log.rfind(':') + 1));
            bool isStart = log.find('s') != string::npos;

            if (isStart)
            {
                if (!s.empty())
                    out[s.top().first] += t - prev; // charge up to this moment
                prev = t;
                s.push({id, t});
            }
            else
            {
                out[s.top().first] += t - prev + 1; // charge including this tick
                s.pop();
                prev = t + 1; // next interval starts after this end tick
            }
        }
        return out;
    }
};