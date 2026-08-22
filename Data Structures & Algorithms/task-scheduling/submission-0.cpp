class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>frq(26,0);
        for(auto c:tasks){
             frq[c-'A']++;
        }

        int max_frq=0;
        for(int count:frq){
    max_frq=max(max_frq,count);
        }

        int max_cnt=0;
        for(int cnt:frq){
            if(cnt==max_frq){
                max_cnt++;
            }
        }
        int time=(max_frq-1)*(n+1)+max_cnt;
        return max((int)tasks.size(),time);
          
    }
};
