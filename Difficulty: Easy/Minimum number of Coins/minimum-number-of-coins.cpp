class Solution {
  public:
    int findMin(int n) {
        // code here
        int arr[]={10,5,2,1};
        int i=0;
        int notes=0;
        while(n){
            notes+=n/arr[i];
            n%=arr[i++];
        }
        return notes;
    }
};