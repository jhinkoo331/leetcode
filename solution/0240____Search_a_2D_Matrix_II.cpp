#include <vector>
#include <stack>
using std::pair;
using std::vector;

typedef pair<int, int> loc;

class Solution {
public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
                return _3(matrix, target);
        }
private:
        //* this method is wrong..
        bool _1(vector<vector<int>>& matrix, int target){
                if(matrix.empty() || matrix.front().empty())
                        return false;
                //* find the row where target exists
                int r = 0, rr = matrix.size() - 1;
                while(r < rr){
                        int mid = r + (rr - r) / 2;
                        if(target >= matrix[mid].front() && target <= matrix[mid].back()){
                                r = mid;
                                rr = mid;
                                break;
                        }else if(target < matrix[mid].front())
                                rr = mid - 1;
                        else
                                r = mid + 1;
                }
                if(r > rr)
                        return false;
                int c = 0, cc = matrix[r].size() - 1;
                while(c < cc){
                        int mid = c + (cc - c) / 2;
                        if(matrix[r][mid] < target)
                                c = mid + 1;
                        else if(matrix[r][mid] > target)
                                cc = mid - 1;
                        else
                                return true;
                }
                return false;
        }

        bool _2(vector<vector<int>>& mat, int target){
                if(mat.empty() || mat.front().empty())
                        return false;
                if(target == mat[0][0])
                        return true;
                if(target < mat[0][0] || target > mat.back().back())
                        return false;
                
                int r = 0, c = 0;
                int rr = mat.size() - 1, cc = mat.front().size() - 1;
                while(rr - r > 1 || cc - c > 1){
                        int rrr = r + (rr - r) / 2;
                        int ccc = c + (cc - c) / 2;
                        if(target > mat[rrr][ccc]){
                                r = rrr;
                                c = ccc;
                        }else if(target < mat[rrr][ccc]){
                                rr = rrr;
                                cc = ccc;
                        }else
                                return true;
                }
                r = rr;
                c = cc;
                while(r >= 0){
                        if(target == mat[r][c])
                                return true;
                        else if(target > mat[r][c])
                                break;
                        --r;
                }
                while(cc >= 0){
                        if(target == mat[rr][cc])
                                return true;
                        else if(target > mat[rr][cc])
                                break;
                        --cc;
                }
                return false;
        }
        /**
         * @brief TLE err
         * 
         * @param mat 
         * @param target 
         * @return true 
         * @return false 
         */
        bool _3(vector<vector<int>>& mat, int target){
                if(mat.empty() || mat.front().empty())
                        return false;
                std::stack<loc> s;
                s.push({mat.size() - 1, mat.back().size()});
                s.push(s.top());
                s.push({mat.size() - 1, mat.front().size() - 1});
                s.push({0, 0});
                mat.back().push_back(target);           //* sentinel
                while(true){
                        loc loc_1 = s.top();
                        s.pop();
                        loc loc_2 = s.top();
                        s.pop();
                        if(loc_1.first > loc_2.first || loc_1.second > loc_2.second)
                                continue;
                        if(target < mat[loc_1.first][loc_1.second] || target > mat[loc_2.first][loc_2.second])
                                continue;
                        loc loc_3;
                        loc_3.first = loc_1.first + (loc_2.first - loc_1.first) / 2;
                        loc_3.second = loc_1.second + (loc_2.second - loc_1.second) / 2;
                        if(mat[loc_3.first][loc_3.second] == target)
                                break;
                        else if(mat[loc_3.first][loc_3.second] > target){
                                s.push({loc_2.first, loc_3.second - 1});
                                s.push(loc_1);
                                s.push({loc_3.first - 1, loc_2.second});
                                s.push({loc_1.first, loc_3.second});
                        }else{
                                s.push(loc_2);
                                s.push({loc_1.first, loc_3.second + 1});
                                s.push({loc_2.first, loc_3.second});
                                s.push({loc_3.first + 1, loc_1.second});
                        }
                }
                if(s.empty())
                        return false;
                else
                        return true;
        }
};

int main(){
        vector<vector<int>> v = {
                {1,   4,  7, 11, 15},
                {2,   5,  8, 12, 19},
                {3,   6,  9, 16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30}
        };
        vector<vector<int>> vv = {{1, 1}};
        vector<vector<int>> v3 = {
                {1,2,3,4,5},
                {6,7,8,9,10},
                {11,12,13,14,15},
                {16,17,18,19,20},
                {21,22,23,24,25}
        };
        Solution sln;
        sln.searchMatrix(v, 5);
        return 0;
}

