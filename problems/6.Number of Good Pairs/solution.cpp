class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> hashtable;
        int goodPairs = 0;
        
        for(int i=0; i<nums.size(); i++)
            hashtable[nums[i]] += 1;
        
        for(auto element : hashtable)
            goodPairs += (element.second - 1)/2 * element.second;
        
        
        return goodPairs;
        
    }
};