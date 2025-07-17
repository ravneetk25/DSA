#include <bits/stdc++.h>
using namespace std;
// int main()
// {
// vector<int> arr1= {1, 2, 4, 5};
// vector<int> arr2= {3, 4, 7, 8};
// vector<int> merged= arr1;
// merged.insert(merged.end(), arr2.begin(), arr2.end());
// sort(merged.begin(), merged.end());
// merged.erase(unique(merged.begin(), merged.end()), merged.end());
// for(int num: merged){
//     cout<<num;
// }

// return 0;
// }
void next(vector<int>& nums){
int n= nums.size();
int i= n-2;
while(i>=0 && nums[i]>=nums[i+1] ){
    i--;
}
if(i>=0){
    int j=n-1;
    while(nums[j]<=nums[i]){
        j--;
    }
    swap(nums[i], nums[j]);
}
reverse(nums.begin()+i+1, nums.end());

}
bool detectloop(Node* head){
    Node* slow= head;
    Node* fast =head;
    while(fast && fast->next){
        slow= slow->next;
        fast= fast->next->next;
        if(slow== fast) return true;
    }
    return false;
}