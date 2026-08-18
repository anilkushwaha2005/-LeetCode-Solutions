class Solution {
public:

    bool isValid(int n, vector<int>& quantities, int x) {

        int stores = 0;

        for(int q : quantities) {
            stores += (q + x - 1) / x;
        }

        return stores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = 0;

        for(int q : quantities) {
            high = max(high, q);
        }

        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isValid(n, quantities, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};