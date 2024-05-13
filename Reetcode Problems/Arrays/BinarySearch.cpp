#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int pivot = (left + right) / 2;

        if (nums[pivot] == target) {
            return pivot;
        }
        else if (nums[pivot] < target) {
            left = pivot + 1;
        }
        else {
            right = pivot - 1;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    int value = 0;
    vector<int> A;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> value;
        A.push_back(value);
    }

    sort(A.begin(), A.end());

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a = 0;
        cin >> a;

        int result = binarySearch(A, a);
        if (result != -1) {
            cout << 1 << '\n'; 
        }
        else {
            cout << 0 << '\n'; 
        }
    }

    return 0;
}

//수정했습니다.

