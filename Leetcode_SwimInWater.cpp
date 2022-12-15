class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        visited[0][0] = true;
        pq.push({grid[0][0],0,0});

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty())
        {
            int currT = pq.top()[0];
            int currR = pq.top()[1];
            int currC = pq.top()[2];
            pq.pop();

            if(currR == n-1 && currC == n-1)
            {
                return currT;
            }

            for(auto &dir: dirs)
            {
                int newR = currR + dir[0];
                int newC = currC + dir[1];
                if(newR < 0 || newR == n || newC < 0 || newC == n || visited[newR][newC])
                continue;

                visited[newR][newC] = true;
                visited[newR][newC] = true;
                pq.push({max(currT,grid[newR][newC]), newR, newC});
            }
        }
        return -1;
    }
};
