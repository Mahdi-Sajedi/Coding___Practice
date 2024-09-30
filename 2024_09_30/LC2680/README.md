Just a quick review of previously solved problems before my interview.
```cpp
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size(), 0);
        vector<long long> suffix(nums.size(), 0);
        long long ans = 0;
        for (int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] | nums[i-1];
            suffix[nums.size()-i-1] = suffix[nums.size()-i] | nums[nums.size()-i]; 
        }
        long long temp;
        for (int i=0; i<nums.size(); i++){
            temp = prefix[i] | ((long long)nums[i] << k) | suffix[i];
            if (temp>ans)
                ans = temp;
        }
        return ans;
    }
};
```
