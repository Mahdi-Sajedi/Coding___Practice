New achievement!

You just solved the KATHTHI problem!

This was the first SPOJ successful submission. I tried to use vector<int> instead of pair<int, pair<int, int>> but it didn't work somehow in compile time and got TLE. Thanks to 
(0-1 BFS)[https://codeforces.com/blog/entry/22276] post and its [user](https://codeforces.com/profile/himanshujaju). Note that there are [some problems](https://stackoverflow.com/questions/68663695/can-01-bfs-be-used-to-find-shortest-path-in-a-graph-with-only-2-weights) that look like solvable using 
0-1 BFS but that's not the case.

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <climits> // For INT_MAX
using namespace std;

int solve(vector<string>& prison_map, int R, int C) {
    deque<pair<int, pair<int, int>>> dq; // {guards_killed, {row, column}}
    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));

    dq.push_front({0, {0, 0}});
    dist[0][0] = 0;

    // Directions: up, right, down, left
    vector<int> dir = {-1, 0, 1, 0, -1}; 

    while (!dq.empty()) {
        auto t = dq.front();
        int guards_killed = t.first;
        int r = t.second.first;
        int c = t.second.second;
        dq.pop_front();

        // If we've reached the bottom-right corner
        if (r == R - 1 && c == C - 1) {
            return dist[r][c];
        }

        for (int i = 0; i < 4; i++) {
            int new_r = r + dir[i];
            int new_c = c + dir[i + 1];

            // Check if the new position is within bounds
            if (new_r >= 0 && new_r < R && new_c >= 0 && new_c < C) {
                int cost = (prison_map[r][c] != prison_map[new_r][new_c]) ? 1 : 0; // Cost to move

                if (dist[r][c] + cost < dist[new_r][new_c]) {
                    dist[new_r][new_c] = dist[r][c] + cost;
                    // Push to front if no guard is killed, else push to back
                    if (cost == 0) 
                        dq.push_front({dist[new_r][new_c], {new_r, new_c}});
                    else
                        dq.push_back({dist[new_r][new_c], {new_r, new_c}});
                }
            }
        }
    }
    return -1; // Return -1 if there's no valid path (should not happen in given constraints)
}

int main() {
    ios::sync_with_stdio(false); // Fast I/O
    cin.tie(nullptr); // Unsynchronize cin and cout

    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int R, C;
        cin >> R >> C;

        vector<string> prison_map(R);
        for (int i = 0; i < R; ++i) {
            cin >> prison_map[i]; // Read each row of the prison map
        }

        // Call the function to solve the current test case
        cout << solve(prison_map, R, C) << endl;
    }

    return 0;
}

```
