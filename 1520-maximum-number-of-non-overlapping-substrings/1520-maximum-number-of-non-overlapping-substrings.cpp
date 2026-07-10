class Solution {
public:

    int findEnd(string &s, int start, vector<int> &first, vector<int> &last) {

        int end = last[s[start] - 'a'];

        for (int i = start; i <= end; i++) {

            // Agar koi character pehle hi start ho gaya tha,
            // to is index se valid substring nahi ban sakti.
            if (first[s[i] - 'a'] < start)
                return -1;

            end = max(end, last[s[i] - 'a']);
        }

        return end;
    }

    vector<string> maxNumOfSubstrings(string s) {

        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;

            last[s[i] - 'a'] = i;
        }

        vector<string> ans;

        int prevEnd = -1;

        for (int i = 0; i < s.size(); i++) {

            // Sirf first occurrence se hi substring banana try karenge
            if (i != first[s[i] - 'a'])
                continue;

            int end = findEnd(s, i, first, last);

            if (end == -1)
                continue;

            if (i > prevEnd)
                ans.push_back("");

            prevEnd = end;
            ans.back() = s.substr(i, end - i + 1);
        }

        return ans;
    }
};