class Solution {
public:
    string alienOrder(vector<string> &words) {
        
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        // indegree make all char 0
        for(auto word : words){
            for(auto c : st){
                indegree[c]=0;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string curr = words[i];
            string next = words[i+1];
            
            bool flag = false;
            int len = min(curr.length(), next.length());
            for(int j=0; j<len; j++){
                char ch1 = curr[j];
                char ch2 = next[j];

                if(ch1 != ch2){
                    unordered_set<char> set;

                    if(graph.find(ch1) != graph.end()){
                        set = graph[ch1];

                        if(set.find(ch2) == set.end()){
                            set.insert(ch2);
                            indegree[ch2]++;
                            graph[ch1] = set;
                        }
                    }
                    else{
                        set.insert(ch2);
                        indegree[ch2]++;
                        graph[ch1] = set;
                    }

                    flag = true;
                    break;
                }
                
            }

            if(flag == false and (curr.length() > next.length())) return "";
        }

        priority_queue<char, vector<char>, greater<char>> q;

        for(auto it : indegree){
            if(it.second == 0){
                //cout<<it.first<<endl;
                q.push(it.first);
            }
        }

        int count=0;
        string ans = "";

        while(q.size()>0){
            auto rem = q.top();
            q.pop();

            ans += rem;
            count++;

            if(graph.find(rem) != graph.end()){
                unordered_set<char> nbrs = graph[rem];

                for(auto nbr : nbrs){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }

        if(count == indegree.size()){
            return ans;
        }
        return "";
    }
};
