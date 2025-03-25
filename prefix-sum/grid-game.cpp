class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondRowRemainSum = 0;
        long long minimizedRobot2Sum = LLONG_MAX;
        for(int Robot1Col = 0; Robot1Col < grid[0].size(); Robot1Col++){
            firstRowRemainSum -= grid[0][Robot1Col];
            long long bestOfRobot2 = max(firstRowRemainSum, secondRowRemainSum);
            minimizedRobot2Sum = min(bestOfRobot2, minimizedRobot2Sum);
            secondRowRemainSum += grid[1][Robot1Col];
        }
        return minimizedRobot2Sum;
    }
};