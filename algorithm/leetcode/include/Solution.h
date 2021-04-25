#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <vector>

class Solution
{
    public:
        Solution();
        virtual ~Solution();

        std::vector<std::string> c22_generateParenthsis(int n);
        bool c33_search(std::vector<int>& nums, int target);
        int c80_removeDuplicates(std::vector<int>& nums);
        std::string c179_largestNumber(std::vector<int>& nums);

    protected:

    private:
};

#endif // SOLUTION_H
