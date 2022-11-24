#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>


using namespace std;

const int N = 100010;

// 下面两个算法看一下

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> subset;
        backtrack(nums, 0, subset, solution);
        return solution;
    }
private:
    void backtrack(vector<int> &nums, int start, 
        vector<int> &subset, vector<vector<int>> &solution) {

        solution.push_back(subset);
        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(nums, i+1, subset, solution);
            subset.pop_back();
        }
    }
};

void backtrack(const vector<char> &num, vector<bool> use, vector<char> solution)
{
    if (solution.size() == 3) {  //注意本列中abb排列的结果维度为3
        for(const auto e : solution)
            cout << e << " ";
        cout << endl;
        return;
    }else {
        for(int i = 0; i < num.size(); ++i) {
            if (!use[i]) {
                use[i] = true;
                solution.push_back(num[i]);
                backtrack(num, use, solution);
                solution.pop_back();
                use[i] = false;
            }
        }
    }
}

int main(){
    
    return 0;
}
