#include <bits/stdc++.h>
using namespace std;
 
#define ROW 4
#define COL 4
 
// Direction vectors
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };
 
// Function to check if a cell
// is be visited or not
bool isValid(bool vis[][COL],
             int row, int col)
{
    // If cell lies out of bounds
    if (row < 0 || col < 0
        || row >= ROW || col >= COL)
        return false;
 
    // If cell is already visited
    if (vis[row][col])
        return false;
 
    // Otherwise
    return true;
}
 
// Function to perform the BFS traversal
void BFS(int grid[][COL], bool vis[][COL],
         int row, int col)
{
    // Stores indices of the matrix cells
    queue<pair<int, int> > q;
 
    // Mark the starting cell as visited
    // and push it into the queue
    q.push({ row, col });
    vis[row][col] = true;
 
    // Iterate while the queue
    // is not empty
    while (!q.empty()) {
 
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
 
        cout << grid[x][y] << " ";
 
        q.pop();
 
        // Go to the adjacent cells
        for (int i = 0; i < 4; i++) {
 
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
 
            if (isValid(vis, adjx, adjy)) {
                q.push({ adjx, adjy });
                vis[adjx][adjy] = true;
            }
        }
    }
}
 
// Driver Code
int main()
{
    // Given input matrix
    int grid[ROW][COL] = { { 1, 2, 3, 4 },
                           { 5, 6, 7, 8 },
                           { 9, 10, 11, 12 },
                           { 13, 14, 15, 16 } };
 
    // Declare the visited array
    bool vis[ROW][COL];
    memset(vis, false, sizeof vis);
 
    BFS(grid, vis, 0, 0);
 
    return 0;
}
