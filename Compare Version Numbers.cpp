class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;

        string current = ""; 

        for (int i = 0; i < version1.length(); ++i) {
            if (version1[i] == '.') {
                if (!current.empty()) {
                    v1.push_back(stoi(current)); 
                    current = "";
                }
            } else {
                // if (current.empty() || current[0] != '0') {
                //     current += version1[i];
                // }
                current+=version1[i] ; 
            }
        }
        if (!current.empty()) {
            v1.push_back(stoi(current));
        }

        current = "";
        for (int i = 0; i < version2.length(); ++i) {
            if (version2[i] == '.') {
                if (!current.empty()) {
                    v2.push_back(stoi(current));
                    current = "";
                }
            } else {
                // if (current.empty() || current[0] != '0') {
                    current += version2[i];
                // }
            }
        }
        if (!current.empty()) {
            v2.push_back(stoi(current));
        }

        for (int i = 0; i < min(v1.size(), v2.size()); ++i) {
            if (v1[i] > v2[i]) {
                return 1;
            } else if (v1[i] < v2[i]) {
                return -1;
            }
        }

        for (int i = min(v1.size(), v2.size()); i < v1.size(); ++i) {
            if (v1[i] > 0) {
                return 1;
            }
        }
        for (int i = min(v1.size(), v2.size()); i < v2.size(); ++i) {
            if (v2[i] > 0) {
                return -1;
            }
        }

        return 0;
    }
};
