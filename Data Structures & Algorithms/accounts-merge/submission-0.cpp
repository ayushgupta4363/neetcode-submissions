class Solution {
public:
   void dfs(const string& email, 
             unordered_map<string, vector<string>>& adj, 
             unordered_set<string>& visited, 
             vector<string>& merged_account) {
        
        visited.insert(email);
        merged_account.push_back(email);
        
        // Traverse all neighboring emails
        for (const string& neighbor : adj[email]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adj, visited, merged_account);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,string>email_to_name;

        for(auto account:accounts){
            string name =account[0];
            string first_email=account[1];

            for(int i=1;i<account.size();i++){
                string curremail =account[i];
                adj[first_email].push_back(curremail);
                adj[curremail].push_back(first_email);
                  
                  email_to_name[curremail]=name;
            }
        }

        unordered_set<string> visited;
        vector<vector<string>> result;
        
        for (const auto& pair : email_to_name) {
            string email = pair.first;
            string name = pair.second;
            
            // If the email hasn't been visited, it belongs to a new merged component
            if (visited.find(email) == visited.end()) {
                vector<string> merged_account;
                
                // Collect all connected emails via DFS
                dfs(email, adj, visited, merged_account);
                
                // Step 3: Sort emails alphabetically as required
                sort(merged_account.begin(), merged_account.end());
                
                // Add the owner's name to the beginning of the list
                merged_account.insert(merged_account.begin(), name);
                
                result.push_back(merged_account);
            }
        }
        
        return result;

    }
};