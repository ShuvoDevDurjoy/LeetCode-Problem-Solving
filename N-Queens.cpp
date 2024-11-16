class Solution {
public:
int maxRow;
int maxColumn;
void mark(vector<string> &sample, vector<string> &track, int row, int column)
{
    for (int i = row + 1; i < maxRow; ++i)
    {
        if (sample[i][column] != 'n')
        {
            sample[i][column] = 'n';
            track.push_back((to_string(i) + to_string(column)));
        }
    }
    int x = row + 1;
    for (int i = column + 1; i < maxRow && x<maxRow; ++i)
    {
        if (sample[x][i] != 'n')
        {
            sample[x][i] = 'n';
            track.push_back(to_string(x) + to_string(i));
            x++;
        }
        else
        {
            x++;
        }
    }
    x = row + 1;
    for (int i = column - 1; i >= 0 && x<maxRow; --i)
    {
        if (sample[x][i] != 'n')
        {
            sample[x][i] = 'n';
            track.push_back(to_string(x) + to_string(i));
            x++;
        }
        else
        {
            x++;
        }
    }

}

void unmark(vector<string> &sample, vector<string> &track, int row, int column)
{

    while (!track.empty())
    {
        string s = track.back();
        sample[s[0]-'0'][s[1]-'0'] = '.';
        track.pop_back();
    }

}

void insert(vector<vector<string>> &ans, vector<string> &sample)
{
    vector<string> s;
    string temp = "";
    for (int i = 0; i < maxRow; ++i)
    {
        temp = "";
        for (int j = 0; j < maxRow; ++j)
        {
            if (sample[i][j] == 'Q')
            {
                temp += sample[i][j];
            }
            else
            {
                temp += '.';
            }
        }
        s.push_back(temp);
    }
    ans.push_back(s);
}
void solve(vector<vector<string>> &track, vector<vector<string>> &ans, vector<string> &sample, int row)
{
    for (int i = 0; i < maxRow; ++i)
    {
        if (sample[row][i] != 'n')
        {
            if (row + 1 == maxRow)
            {
                sample[row][i] = 'Q';
                insert(ans, sample);
                sample[row][i] = '.';
                break;
            }
            sample[row][i] = 'Q';
            mark(sample, track[row], row, i);
            solve(track, ans, sample, row + 1);
            sample[row][i] = '.';
            unmark(sample, track[row], row, i);
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    maxRow = n;
    maxColumn = n;
    vector<string> sample;
    for (int i = 0; i < n; ++i)
    {
        string temp = "";
        for (int j = 0; j < n; ++j)
        {
            temp += '.';
        }
        sample.push_back(temp);
    }
    vector<vector<string>> track(n);
    vector<vector<string>> ans;
    solve(track, ans, sample, 0);
    return ans;
}
};
