class Solution {
public:
    typedef pair<int, pair<int, int>> pp;

    vector<vector<int>> topKFrequent(vector<int>& nums1, vector<int>& nums2,
                                     int k) {

        priority_queue<pp> pq;
        vector<vector<int>> ans;

        for (int i = 0; i < nums1.size(); i++) {

           

            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                
                if (pq.size() < k) {
                    pq.push({sum, {nums1[i], nums2[j]}});
                    continue;
                }
                 if(pq.size() != 0 && nums1[i] + nums2[0] > pq.top().first) break;
                int temp = pq.top().first;
                if (sum < temp) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else break;
            }
        }

        while (!pq.empty()) {
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            ans.push_back({a,b});
            pq.pop();
        }

        return ans;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        return topKFrequent(nums1, nums2, k);
    }
};