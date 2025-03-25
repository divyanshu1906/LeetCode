class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);

        vector<pair<int, int>> sortedNums1;
        for (int i = 0; i < n; i++) {
            sortedNums1.push_back({nums1[i], i});
        }
        sort(sortedNums1.begin(), sortedNums1.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0; 
        int j = 0; 
        for (int i = 0; i < n; i++) {
            int value = sortedNums1[i].first;
            int idx = sortedNums1[i].second;

            while (j < n && sortedNums1[j].first < value) {
                int nums2Index = sortedNums1[j].second;
                minHeap.push(nums2[nums2Index]);
                sum += nums2[nums2Index];

                if (minHeap.size() > k) {
                    sum -= minHeap.top();
                    minHeap.pop();
                }
                j++;
            }

            ans[idx] = sum;
        }

        return ans;
    }
};