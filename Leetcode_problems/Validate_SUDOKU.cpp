#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach--> We will traverse every row , every column and 3X3 sqaure grid to check if there is no repeatition of a number in row,column and square grid.
class Solution
{
public:
    bool traverse(vector<vector<char>> &grid, int sr, int er, int sc, int ec)
    {
        set<char> st;
        for (int i = sr; i < er; i++)
        {
            for (int j = sc; j < ec; j++)
            {
                if (grid[i][j] == '.')
                    continue;
                if (st.find(grid[i][j]) != st.end())
                    return false;
                st.insert(grid[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // check every row
        for (int row = 0; row < 9; row++)
        {
            set<char> st;
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                    continue;
                if (st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }
        // check every column
        for (int col = 0; col < 9; col++)
        {
            set<char> st;
            for (int row = 0; row < 9; row++)
            {
                if (board[row][col] == '.')
                    continue;
                if (st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }
        // check every 3X3 square grid
        for (int sr = 0; sr < 9; sr += 3)
        {
            for (int sc = 0; sc < 9; sc += 3)
            {
                // we have sr,er,sc,ec
                if (!traverse(board, sr, sr + 3, sc, sc + 3))
                    return false;
            }
        }
        return true;
    }
};

// Smart Trick--> We store a string in set for row,column,and square grid
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> st;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1, board[i][j]) + "_COLUMN_" + to_string(j);
                string grid = string(1, board[i][j]) + "_GRID_" +
                              to_string(i / 3) + to_string(j / 3);
                if (st.find(row) != st.end() || st.find(col) != st.end() ||
                    st.find(grid) != st.end())
                    return false;
                st.insert(row);
                st.insert(col);
                st.insert(grid);
            }
        }
        return true;
    }
};