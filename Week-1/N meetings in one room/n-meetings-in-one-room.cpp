bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        
        int total=0;
        int ending=-1;
        for(int i=0;i<n;i++){
            if(v[i].first>ending){
                total++;
                ending=v[i].second;
            }
        }
        return total;
    }
};