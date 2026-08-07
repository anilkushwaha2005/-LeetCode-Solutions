class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int lP = 0;
        int rP = n-1;
        while( lP < rP){
            int wid = rP-lP;
            int ht = min(height[lP],height[rP]);
            int currWater = wid*ht;
            maxWater = max(maxWater,currWater);

            height[lP] < height[rP] ? lP++ : rP--;

        }
       

        return maxWater;
        
    }
};