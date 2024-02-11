#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


void moveZeroes(vector<int>& nums) {
    int wIdx = 0;
    for (int idx = 0; idx < nums.size(); idx++) {
        if (nums[idx] != 0) {
            swap(nums[wIdx], nums[idx]);
            wIdx++;
        }
    }
}



int main(void) {

    vector<int> A;
    int n;


    cin >> n;
    int temp = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    moveZeroes(A);

    for (int i = 0; i < A.size(); i++) {

        cout << A[i] << " ";

    }
    cout << endl;


    return 0;
}