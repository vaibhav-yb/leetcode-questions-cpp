// 207. Course Schedule
// Medium.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // the graph stores the prerequisite courses required
        vector< vector<int> > graph(numCourses);
        for(vector<int> p : prerequisites)
            graph[p[1]].push_back(p[0]);
        
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < graph.size(); ++i)
        {
            for(auto itr = graph[i].begin(); itr != graph[i].end(); ++itr)
                inDegree[*itr]++;
        }
        queue<int> q;
        
        for(int i = 0; i < inDegree.size(); ++i)
            if(inDegree[i] == 0)
                q.push(i);
        
        int cnt = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt++;
            for(auto itr = graph[u].begin(); itr != graph[u].end(); ++itr)
                if(--inDegree[*itr] == 0)
                    q.push(*itr);
        }
        
        // if the count of nodes is not equal to the complete number of nodes
        // then that means there was a cycle and the course schedule cannot be completed
        if(cnt != numCourses)
            return false;
        
        return true;
    }
};