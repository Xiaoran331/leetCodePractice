#include<iostream>
#include<vector>
using namespace std;

//ascending order
//using binary search
class Solution {
public:
    /*
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = (int)nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[right];
    }
    */
    int findMin(vector<int>& nums) {
        return helper(nums, 0, int(nums.size() - 1));
    }
    int helper(vector<int>& nums, int start, int end){
        if(start == end) return nums[start];
        if(nums[start] < nums[end]) return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid+1, end));
    }
};

int main()
{
    vector<int> list;
    int temp;

    do{
        cin >> temp;
        if(!temp) break;
        list.insert(list.end(),temp);
    }while(getchar()!='\n');

    for(int i = 0; i < list.size(); i++){
        cout << list.at(i) << " ";
    }
    cout << endl;
    Solution S;
    int ans = S.findMin(list);
    cout << ans << endl;
    return 0;
}