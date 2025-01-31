class Solution
{
public:
    int rowSize;
    int columnSize;

    bool isValid(int row, int column)
    {
        return row >= 0 && row < rowSize && column >= 0 && column < columnSize;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        // determine the size of row and column in grid
        // once they are stored in a variable this will
        // decrease the time complexity by allowing these variable
        // in for loop condition statement instread of using grid.size()
        //   each time of iteration
        rowSize = grid.size();
        columnSize = grid[0].size();

        unordered_map<int, int> maps;

        vector<vector<bool>> track(rowSize, vector<bool>(columnSize, false));

        queue<pair<int, int>> q;

        int count = 0 ;

        for (int i = 0; i < rowSize; ++i)
        {
            for (int j = 0; j < columnSize; ++j)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                    ++count;
                }
            }
        }

        if(count == rowSize*columnSize){
            return count;
        }

        int direction[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        int index = 2;
        int size = 1;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            if (track[p.first][p.second])
            {
                continue;
            }

            queue<pair<int, int>> currentQueue;
            currentQueue.push(p);
            size = 0;

            while (!currentQueue.empty())
            {
                p = currentQueue.front();
                currentQueue.pop();
                if(track[p.first][p.second]){
                    continue;
                }
                track[p.first][p.second] = true;
                grid[p.first][p.second] = index;
                ++size;
                for (int i = 0; i < 4; ++i)
                {
                    if (isValid(p.first + direction[i][0], p.second + direction[i][1]) && grid[p.first + direction[i][0]][p.second + direction[i][1]] && !track[p.first + direction[i][0]][p.second + direction[i][1]])
                    {
                        currentQueue.push({p.first + direction[i][0], p.second + direction[i][1]});
                    }
                }
            }
            maps[index] = size == 0 ? 1 : size;
            index++;
        }

        int maximum = 0;
       

        unordered_map<int,pair<int,int>> countHelper;
        for(int i = 0 ; i < index ; ++i){
            countHelper[i] = {-1,-1};
        }

        for (int i = 0; i < rowSize; ++i)
        {
            for (int j = 0; j < columnSize; ++j)
            {
                if (!grid[i][j])
                {
                    count = 1;
                    //checks right
                    if(isValid(i,j+1) && grid[i][j+1]){
                        countHelper[grid[i][j+1]] = pair<int,int>{i,j};
                        count += maps[grid[i][j+1]];
                    }
                    //checks left
                    if(isValid(i,j-1) && grid[i][j-1] && (countHelper[grid[i][j-1]].first!=i || countHelper[grid[i][j-1]].second!=j)){
                        countHelper[grid[i][j-1]] = pair<int,int>{i,j};
                        count += maps[grid[i][j-1]];
                    }
                    //checks bottom
                    if(isValid(i+1,j) && grid[i+1][j] && (countHelper[grid[i+1][j]].first!=i || countHelper[grid[i+1][j]].second!=j)){
                        countHelper[grid[i+1][j]] = pair<int,int>{i,j};
                        count += maps[grid[i+1][j]];
                    }
                    //checks top
                    if(isValid(i-1,j) && grid[i-1][j] && (countHelper[grid[i-1][j]].first!=i || countHelper[grid[i-1][j]].second!=j)){
                        countHelper[grid[i-1][j]] = pair<int,int>{i,j};
                        count += maps[grid[i-1][j]];
                    }

                    maximum = max(maximum,count);

                }
            }
        }

        return maximum;
    }
};
