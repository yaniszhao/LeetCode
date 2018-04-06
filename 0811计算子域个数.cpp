class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        map<string,int> map;
        int times,pos;
        string s;
        stringstream ss;
        for (auto it:cpdomains) {
            ss.clear();
            ss<<it;
            ss>>times>>s;
            map[s]+=times;
            while ((pos=s.find('.'))!=-1) {
                s=s.substr(pos+1);
                map[s]+=times;
            }
        }
        for (auto it:map) {
            s=to_string(it.second).append(" ").append(it.first);
            ans.push_back(s);
        }
        return ans;
    }
};