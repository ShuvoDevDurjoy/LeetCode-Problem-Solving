class Solution {
public:
    int binarySearch(vector<pair<int, int>>& dp, int left, int right,
                     int value) {
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (dp[mid].first >= value) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool findAppropriate(vector<pair<int, int>>& dp, int start, int value1,
                         int value2) {
        for (int i = start; i < dp.size(); ++i) {
            if (dp[i].second != value1 && dp[i].second != value2) {
                return true;
            }
        }

        return false;
    }

    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int maximum = 0;

        vector<pair<int, int>> dp;
        vector<int> gaps;
        if (startTime[0] - 0)
            dp.push_back({startTime[0] - 0, 0});
        gaps.push_back(startTime[0] - 0);
        for (int i = 1; i < startTime.size(); ++i) {
            if (startTime[i] - endTime[i - 1])
                dp.push_back({startTime[i] - endTime[i - 1], startTime[i-1]});
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[endTime.size() - 1]);

        if (eventTime - endTime[endTime.size() - 1])
            dp.push_back(
                {eventTime - endTime[endTime.size() - 1], startTime[startTime.size()-1]});

        sort(dp.begin(), dp.end());
        for (int i = 0; i < startTime.size(); ++i) {
            int gapsize = endTime[i] - startTime[i];
            int index = binarySearch(dp, 0, dp.size() - 1, gapsize);
            bool appropriate = findAppropriate(
                dp, index, i == 0 ? 0 : startTime[i - 1], startTime[i]);
            maximum = max(maximum, appropriate ? gapsize + gaps[i] + gaps[i + 1]
                                               : gaps[i] + gaps[i + 1]);
        }

        return maximum;
    }
};
