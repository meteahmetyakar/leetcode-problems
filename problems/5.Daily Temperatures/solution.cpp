class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int temp_size = temperatures.size();

        stack<int> monotonic;
        vector<int> nextWarmerDays(temp_size, 0);

        for (int i = 0; i < temp_size; i++)
        {
            while (!monotonic.empty() && temperatures[monotonic.top()] < temperatures[i])
            {
                nextWarmerDays[monotonic.top()] = i - monotonic.top();
                monotonic.pop();
            }

            monotonic.push(i);
        }

        return nextWarmerDays;
    }
};