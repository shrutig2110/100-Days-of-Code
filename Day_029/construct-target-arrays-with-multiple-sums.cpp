/*
PROBLEM: You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < n and set the value of arr at index i to x.
You may repeat this procedure as many times as needed.
Return true if it is possible to construct the target array from arr, otherwise, return false.
*/
class Solution {
public:
    bool isPossible(vector<int>& target) {
    auto s = accumulate(begin(target), end(target), (long long)0);
    priority_queue<int> q(begin(target), end(target));
    while (s > 1 && q.top() > s / 2) {
        auto cur = q.top(); q.pop();
        s -= cur;
        if (s <= 1)
            return s;
        q.push(cur % s);
        s += cur % s;
    }
    return s == target.size();
}
};