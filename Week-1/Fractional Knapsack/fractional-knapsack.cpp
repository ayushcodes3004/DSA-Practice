class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            double r=(double)val[i]/(double)wt[i];
            v.push_back({r,i});
        }
        
        sort(v.begin(),v.end());
        double ans=0;
        for(int i=n-1;i>=0;i--){
            int ind=v[i].second;
            if(wt[ind]<=capacity){
                ans+=val[ind];
                capacity-=wt[ind];
            }else{
                ans+=((double)capacity / wt[ind])*val[ind];
                capacity=0;
                break;
            }
        }
        return ans;
    }
};
