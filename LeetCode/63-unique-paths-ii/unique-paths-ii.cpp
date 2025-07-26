class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(); //rows
        int n=obstacleGrid[0].size(); //columns
        if (obstacleGrid[0][0] == 1) return 0; //start is blocked
        obstacleGrid[0][0] = 1; //1 way to reach start
        //only 1 way to reach 1st row/column but if obstacle encountered then 0
        //first column j=0
        for(int i=1;i<m;i++){
            //if current and prev not an obstacle 
            if(obstacleGrid[i][0]==0 && obstacleGrid[i-1][0]==1)obstacleGrid[i][0]=1;
            else obstacleGrid[i][0]=0;
        }
        //first row i=0
        for(int j=1;j<n;j++){
            //if current and prev not an obstacle 
            if(obstacleGrid[0][j]==0 && obstacleGrid[0][j-1]==1)obstacleGrid[0][j]=1;
            else obstacleGrid[0][j]=0;
        }
        //rest cells
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0; //current is obstacle
                else obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];

            }
        }
        return obstacleGrid[m-1][n-1];
    }
};