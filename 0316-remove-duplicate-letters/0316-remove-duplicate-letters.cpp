class Solution {
public:
    string removeDuplicateLetters(string s) {
        string out; int cnt[26] = {}; int used[26] = {};

        for (char c: s)
            cnt[c - 'a']++;

        for (char c: s)
        {
            cnt[c - 'a']--;
            if (used[c - 'a']++ > 0) continue;
            while (!out.empty() && out.back() > c && cnt[out.back() - 'a'] > 0)
            {
                used[out.back() - 'a'] = 0;
                out.pop_back(); 
            }
            out.push_back(c);
        }
        return out;
    }
};