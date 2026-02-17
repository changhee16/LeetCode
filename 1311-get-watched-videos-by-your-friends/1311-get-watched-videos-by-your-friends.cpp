class Solution {
public:
    static bool comparator(const pair<string,int>& a,
                const pair<string,int>& b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        int cur_level = 0;
        queue <int> q;
        vector<bool> visited(n, false);
        vector<string> res;
        unordered_map<string, int> freq;

        q.push(id);
        visited[id] = true;
        while (cur_level++ < level) //BFS 수행 
        {
            int q_size = q.size();
            while (q_size--)
            {
                int cur = q.front();
                q.pop();
                for (int next : friends[cur])
                {
                    if (!visited[next])
                    {
                        if (cur_level == level)
                            for (string video : watchedVideos[next])
                                freq[video]++;
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
        vector<pair<string, int>> arr(freq.begin(), freq.end());
        sort(arr.begin(), arr.end(), comparator);
        for (auto p : arr) res.push_back(p.first);
        return res;
    }
};