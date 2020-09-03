#include "util\frequently_included.h"

class Solution {
public:
        /**
         * @perf: 66, 68
         */
        int minimumTotal(vector<vector<int>>& triangle) {
                int height = triangle.size();
                for(int i = triangle.size() - 2; i >= 0; --i)
                        for(int j = 0; j <= i; ++j)
                                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
                return triangle[0][0];
        }
};
