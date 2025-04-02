//1700. Number of sttudent unable to eat lunch
// Class op

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> Q;
        int index = 0, rot = 0;
        for (auto s : students)
            Q.push(s);
        while (!Q.empty() && rot < Q.size())
        {
            if (Q.front() == sandwiches[index])
            {
                Q.pop();
                ++index;
                rot = 0;
            }
            else
            {
                Q.push(Q.front());
                Q.pop();
                rot++;
            }
        }
        return Q.size();
    }
};

int main()
{
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    Solution sol;
    int result = sol.countStudents(students, sandwiches);

    cout << "Number of students unable to eat lunch: " << result << endl;

    return 0;
}