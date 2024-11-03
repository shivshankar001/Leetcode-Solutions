class Solution {
public:
    bool check(int sr, int er, int sc, int ec, vector<vector<char>>& board)
    {
        map<char, int> mp;
        for(int i=sr; i<=er; i++)
        {
            for(int j=sc; j<=ec; j++)
            {
                if(board[i][j] != '.')
                {
                    if(mp[board[i][j]]>0)
                    {
                        return false;
                    }
                    mp[board[i][j]]++;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] != '.')
                {
                    for(int k=i+1; k<n; k++)
                    {
                        if(board[i][j]==board[k][j])
                        {
                            return false;
                        }
                    }
                    for(int k=j+1; k<m; k++)
                    {
                        if(board[i][j]==board[i][k])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i+=3)
        {
            for(int j=0; j<n; j+=3)
            {
                if(!check(i, i+2, j, j+2, board))
                {
                    return false;
                }
            }
        }
        return true;
    }
};