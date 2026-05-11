class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt = 0;
        while (students.size() != 0)
        {
            if (students.front() != sandwiches.front())
            {
                int temp = students.front();
                students.erase(students.begin());
                students.push_back(temp);
                cnt ++;
            }
            else 
            {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                cnt = 0;
            }

            if (cnt == students.size())
                break;
        }

        return students.size();
    }
};