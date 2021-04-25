#ifndef C783_MINDIFFINBST_H
#define C783_MINDIFFINBST_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class c783_minDiffInBST
{
    public:
        c783_minDiffInBST();
        virtual ~c783_minDiffInBST();

    protected:

    private:
};

#endif // C783_MINDIFFINBST_H
