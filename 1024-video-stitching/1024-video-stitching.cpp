class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        
        sort(clips.begin(),clips.end());
        
        int num = 1;
        int end = 0;
        for(int i=0; i<n;){
            int newend = end;
            while(i<n && clips[i][0]<=end) 
            {
                newend=max(newend,clips[i++][1]);
            }
            if(newend>=time)
            {
                return num;
            }
            if(newend==end)
            {
                return -1;
            }
            end = newend;
            num++;
        }
        return -1;
    }
};