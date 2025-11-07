bool comp(pair<int,int>& a,pair<int,int>& b){
    return a.second<b.second;
}
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 1;  // Next train to arrive
        int j = 0;  // Next train to depart
        int plat_needed = 1;
        int result = 1;      

        while (i < n && j < n) {
            //train arrive before previous depart
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            }
            //train departs
            else {
                plat_needed--;
                j++;
            }
            result = max(result, plat_needed);
        }

        return result;
    }
};
