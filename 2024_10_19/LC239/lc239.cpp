class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, -1), ans(n-k+1, 0);
        stack<int> st;
        // left
        st.push(0);
        for (int i=0; i<n; i++){
            while (!st.empty() && (nums[st.top()] <= nums[i])) {
                // right[st.top()] = i;
                st.pop();
            }
            left[i] = (st.empty() ? -1: st.top());
            st.push(i);
        }

        while(!st.empty())
            st.pop();
        
        // right
        st.push(n-1);
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && (nums[st.top()] <= nums[i])) {
                st.pop();
            }
            right[i] = (st.empty() ? n: st.top());
            st.push(i);
        }

        // max sliding k-window
        for (int i=0; i<n; i++){
            int l = max(left[i]+1, i-k+1); 
            int r = min(right[i]-1, i+k-1);
            for (int j=l; j<=r-k+1; j++)
                ans[j] = nums[i];
        }
        return ans;

    }
};
