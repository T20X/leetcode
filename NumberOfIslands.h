#pragma once

#include <queue>
#include <stack>
#include <algorithm>

class NumberOfIslands
{
public:
    class Solution
    {
    public:
        using Position = pair<int, int>;

        int numIslands(vector<vector<char>>& grid)
        {
            if (grid.empty())
                return 0;

            size_t rowsN = grid.size();  
            size_t columnsN = grid[0].size();

            vector<vector<bool>> visited;
            visited.resize(rowsN);            
            for (int i = 0; i < rowsN; i++)
                visited[i].resize(columnsN);

            int solution = 0;
            for (size_t r = 0; r < rowsN; r++)
            {
                for (size_t c = 0; c < columnsN; c++)
                {
                    if (!visited[r][c] && grid[r][c] == '1')
                    {
                        bfs(grid, { r, c });
                        solution++;
                    }                     
                }
            }

            return solution;
        }

        void bfs(vector<vector<char>>& grid, 
                 Position root)
        {
            queue<Position> q;
            q.push(root);
            while (!q.empty())
            {
                Position p = q.front();
                grid[p.first][p.second] = '0';
                q.pop();

                auto addIfNotVisisted = [&grid, &q](const auto& p) -> void {
                    int maxRIndex = grid.size() - 1;
                    int maxCIndex = grid[0].size() - 1;
                    if ( p.first >= 0 && p.second >= 0 &&
                         p.first <= maxRIndex && p.second <= maxCIndex &&
                         grid[p.first][p.second] == '1')                        
                    {
                        grid[p.first][p.second] = '0';
                        q.push(p);
                    }
                };

                addIfNotVisisted(Position{ p.first, p.second - 1 });
                addIfNotVisisted(Position{ p.first, p.second + 1 });
                addIfNotVisisted(Position{ p.first - 1, p.second });
                addIfNotVisisted(Position{ p.first + 1, p.second });
            }
        }

        
    };

    static void test()
    {
        vector<vector<char>> input = {
            { '1', '1', '0', '0', '0' },
            { '1', '1', '0', '0', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '1', '0', '0' },
            { '0', '0', '0', '1', '1' }
        };

        Solution s;
        std::cout << "#1 : NumerOfIslands -> " << s.numIslands(input);
    }
};
