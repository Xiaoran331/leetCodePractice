#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector <string> res;
        vector <string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string& digits, vector<string>&dict, int level, string out, vector<string>& res){
        if(level == digits.size()) {res.push_back(out); return;}
        string str = dict[digits[level] - '0'];
        for(int i = 0; i < str.size(); ++i){
            letterCombinationsDFS(digits, dict, level + 1, out + str[i], res);
        }
    }
};

int main()
{
    string digits;
    getline(cin, digits);
    Solution S;
    vector <string> ans = S.letterCombinations(digits);
    for(int i = 0; i < ans.size(); ++i){
        cout << ans.at(i) << endl;
    }
    return 0;
}