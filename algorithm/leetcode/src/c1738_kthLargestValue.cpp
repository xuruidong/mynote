#include "c1738_kthLargestValue.h"

c1738_kthLargestValue::c1738_kthLargestValue()
{
    //ctor
}

c1738_kthLargestValue::~c1738_kthLargestValue()
{
    //dtor
}

int c1738_kthLargestValue::kthLargestValue(vector<vector<int>>& matrix, int k)
{
    std::priority_queue<int> q;
    q.push(matrix[0][0]);
    for(int i=1; i<matrix[0].size(); ++i) {
        matrix[0][i] = matrix[0][i]^matrix[0][i-1];
        q.push(matrix[0][i]);
        cout<< matrix[0][i] <<"  ";
    }

    int tmp = 0;
    for(int i=1; i<matrix.size(); ++i) {
        tmp = matrix[i][0];
        matrix[i][0] ^= matrix[i-1][0];
        q.push(matrix[i][0]);
        cout<< matrix[i][0] <<"  ";
        for(int j=1; j<matrix[i].size(); ++j) {
            tmp ^= matrix[i][j];
            matrix[i][j] = tmp^matrix[i-1][j];
            q.push(matrix[i][j]);
            cout<< matrix[i][j] <<"  ";
        }
    }
    cout<<endl;

    for(int i=1; i<k; ++i) {
        q.pop();
    }

    return q.top();
}

int kthLargestValue2(vector<vector<int>>& matrix, int k)
{
    std::priority_queue<int> q;
    q.push(matrix[0][0]);
    for(int i=1; i<matrix[0].size(); ++i) {
        matrix[0][i] = matrix[0][i]^matrix[0][i-1];
        q.push(matrix[0][i]);
        cout<< matrix[0][i] <<"  ";
    }

    int tmp = 0;
    for(int i=1; i<matrix.size(); ++i) {
        tmp = matrix[i][0];
        matrix[i][0] ^= matrix[i-1][0];
        q.push(matrix[i][0]);
        cout<< matrix[i][0] <<"  ";
        for(int j=1; j<matrix[i].size(); ++j) {
            tmp ^= matrix[i][j];
            matrix[i][j] = tmp^matrix[i-1][j];
            q.push(matrix[i][j]);
            cout<< matrix[i][j] <<"  ";
        }
    }
    cout<<endl;

    for(int i=1; i<k; ++i) {
        q.pop();
    }

    return q.top();
}

void c1738_kthLargestValue::test()
{
    vector<vector<int>> matrix = {{10,9,5},{2,0,4},{1,0,9},{3,4,8}};
    cout<<kthLargestValue(matrix, 3)<<endl;
}
