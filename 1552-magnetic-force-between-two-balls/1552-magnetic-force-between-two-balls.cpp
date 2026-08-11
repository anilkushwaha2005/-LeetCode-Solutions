class Solution {
public:

    bool isPossible(vector<int>& arr, int m,int minMagneticForce){
        int morty = 1, lastAllowedPos = arr[0];

        for(int i = 1; i < arr.size() ; i++){
            if(arr[i]-lastAllowedPos >= minMagneticForce){
                morty++;
                lastAllowedPos = arr[i];
            }

            if(morty == m){
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& arr, int m) {
    sort(arr.begin(),arr.end());

    int st = 1, end = arr[arr.size()-1]- arr[0], ans = -1;
    
    while(st <= end){
        int mid = st + (end-st)/2;
        
        if(isPossible(arr,m,mid)){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
     return ans; 
    }
   
};