class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        //step1 graph aur indegree array 
        for(auto& pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        //step2: 0 indegree wale courses 
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>order;

        //step3: bfs chalao
        while(!q.empty()){
            int current = q.front();
            q.pop();

            //course lia ho toh order me dal denege
            order.push_back(current);

            for(int neighbor:adj[current]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }

        //agar sare complete toh order return karo nahi toh empty array
        if(order.size()==numCourses){
            return order;
        }
        else{
            return {};
        }
    }
};