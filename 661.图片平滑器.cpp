/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 *
 * https://leetcode-cn.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (50.60%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 10.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入)
 * ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * 输出:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
 * 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
 * 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵中的整数范围为 [0, 255]。
 * 矩阵的长和宽的范围均为 [1, 150]。
 * 
 * 
 */
#include <usingstd>
// @lc code=start
class Solution
{
public:
    int m, n;
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        if (M.size() == 0 || M.front().size() == 0)
        {
            return M;
        }
        m = M.size();
        n = M.front().size();
        vector<vector<int>> ans(M.size(), vector<int>(M.front().size()));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[i][j] = doLoop(M, i, j);
            }
        }
        return ans;
    }

    int doLoop(vector<vector<int>> &M, int x, int y)
    {
        static int rot[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
        int cnt = 1;
        int sum = M[x][y];
        for (int i = 0; i < 8; ++i)
        {
            int t = test(M, x+rot[i][0], y+rot[i][1]);
            if (t != -1)
            {
                cnt++;
                sum += t;
            }
        }
        return sum / cnt;
    }
    int test(vector<vector<int>> &M, int x, int y)
    {
        if (x < 0 || x >= m || y < 0 || y >= n)
        {
            return -1;
        }
        return M[x][y];
    }
};
// @lc code=end
