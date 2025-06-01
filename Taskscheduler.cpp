#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int leastIntervals(vector<string>& teams, int n) {
        // Count frequency of each team
        unordered_map<string, int> freq;
        for (const string& team : teams) {
            freq[team]++;
        }
        
        // Create a max heap of teams based on frequency
        using TeamCount = pair<int, string>;
        priority_queue<TeamCount> pq;
        for (const auto& p : freq) {
            pq.emplace(p.second, p.first);
        }
        
        int intervals = 0;
        // Map to track the last interval each team was scheduled
        unordered_map<string, int> lastScheduled;
        
        while (!pq.empty()) {
            vector<TeamCount> temp;
            bool scheduled = false;
            
            // Try to schedule a team at the current interval
            while (!pq.empty()) {
                auto [count, team] = pq.top();
                pq.pop();
                
                // Check if we can schedule this team
                if (lastScheduled.find(team) == lastScheduled.end() || intervals >= lastScheduled[team] + n + 1) {
                    // Schedule the team
                    lastScheduled[team] = intervals;
                    intervals++;
                    scheduled = true;
                    if (count > 1) {
                        // Decrease count and add back to queue
                        temp.emplace_back(count - 1, team);
                    }
                    break;
                } else {
                    // Can't schedule this team yet, save for later
                    temp.emplace_back(count, team);
                }
            }
            
            // Restore teams that couldn't be scheduled
            for (const auto& tc : temp) {
                pq.push(tc);
            }
            
            // If no team was scheduled, increment intervals (idle)
            if (!scheduled) {
                intervals++;
            }
        }
        
        return intervals;
    }
};

int main() {
    Solution solution;
    
    // Read input
    string line;
    getline(cin, line); // Read the team array line
    
    // Parse the team array
    vector<string> teams;
    stringstream ss(line.substr(1, line.size() - 2)); // Remove brackets
    string team;
    while (getline(ss, team, ',')) {
        // Remove quotes and whitespace
        team.erase(remove(team.begin(), team.end(), '"'), team.end());
        team.erase(remove(team.begin(), team.end(), ' '), team.end());
        if (!team.empty()) {
            teams.push_back(team);
        }
    }
    
    // Read n
    int n;
    cin >> n;
    
    // Compute and output result
    cout << solution.leastIntervals(teams, n) << endl;
    
    return 0;
}