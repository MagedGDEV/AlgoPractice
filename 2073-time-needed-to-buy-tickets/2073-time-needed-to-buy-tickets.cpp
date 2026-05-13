class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        while (tickets.size() != 0)
        {
            tickets[0]--;
            if (tickets[k] == 0)
                break;

            int temp = tickets[0];
            tickets.erase(tickets.begin());

            if (temp != 0)
                tickets.push_back(temp);
            
            k = (k == 0) ? tickets.size()-1 : k-1;
            time++;
        }
            
        return time + 1;
    }
};