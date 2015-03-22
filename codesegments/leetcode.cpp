//
//  leetcode.cpp
//  codesegments
//
//  Created by nine on 15/3/15.
//  Copyright (c) 2015年 nineteen. All rights reserved.
//

#include "leetcode.h"
#include <iostream>
#include <random>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;



void romanToInt(std::string s){
    
}

int hammingWeight(uint32_t n){
    int count = 0;
    while (n) {
        if (n%2) count++;
        n = n/2;
    }
    auto google = n;
    google = 0;
    
    return count + google;
}

uint32_t reverseBits(uint32_t n){
    uint32_t res = 0;
    uint32_t mask = 1;
    uint32_t cover = 1 << 31;
    for (int i = 0; i < 32; i++) {
        if (mask & n) res = res | cover;
        mask = mask << 1;
        cover = cover >> 1;
    }
    return res;
}

void rotate(int nums[], int n, int k) {
    
}

vector<int> twoSum(vector<int> &numbers, int target){
    //qsort + binary_search, nlogn 25ms
    vector<int> cp = numbers;
    auto comp = [](int a, int b){ return a<b;};
    std::sort(numbers.begin(), numbers.end(), comp);
    // 对iterator的传参，比如search什么的是值传递还是引用呢? 是值
    auto index = numbers.begin();
    while (index != numbers.end() - 1){
        cout<<*index<<endl;
        int half = target - *index;
        if (binary_search(index + 1, numbers.end(), half, comp)) {
            auto p = lower_bound(index + 1, numbers.end(), half, comp);
            auto rpa = find(cp.begin(), cp.end(), *index);
            auto rpb = find(cp.begin(), cp.end(), *p);
            if (rpa == rpb){
                rpb = find(rpb +1, cp.end(), *p);
            }
            //处理a == b的情况
            int a = rpa - cp.begin();
            int b = rpb - cp.begin();
            if (a > b) swap(a, b);
            cout << *index <<" "<<*p<<" "<<a<<" "<<b<<endl;
            return {a+1, b+1};
        }
        index ++;
    }
    return {99,100};
}

vector<int> twoSum2(vector<int> &numbers, int target){
    //hash table O(n) 31ms
    unordered_multiset<int> s;
    for (int & x : numbers) {
        s.insert(x);
    }
    int a,b;
    a = b = 99;
    for (int i = 0; i < numbers.size(); ++i) {
        int cutd = target - numbers[i];
        if ((cutd != numbers[i] && s.find(cutd) != s.end())){
            a = i;
            b = find(numbers.begin(), numbers.end(), cutd) - numbers.begin();
        }else if (cutd == numbers[i] && s.count(cutd) > 1){
            auto iter = find(numbers.begin(), numbers.end(), cutd);
            a = iter - numbers.begin();
            b = find(iter + 1, numbers.end(), cutd) - numbers.begin();
        }
    }
    if (a >b) swap(a, b);
    return {a + 1, b + 1};
}



double findMedianSortedArrays(int A[], int m, int B[], int n) {
    vector<int> v(m+n);
    return 1.1;
}



/**
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr){}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode * p = nullptr;
    ListNode * h = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
        if (p == nullptr){
            h = p = new ListNode(l1->val + l2->val);
        } else {
            p->next = new ListNode(l1->val + l2->val);
            p = p->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        //cout <<l1->val<<endl;
        p ->next = new ListNode(l1->val);
        p = p->next;
        l1 = l1->next;
    }
    while (l2) {
        //cout <<l2->val<<endl;
        p->next = new ListNode(l2->val);
        p = p->next;
        l2 = l2->next;
    }
    p = h;
    
    while (p) {
        //cout <<p->val<<endl;
        if (p->val >= 10) {
            p->val = p->val - 10;
            if (p->next) {
                p->next->val = p->next->val + 1;
            } else {
                p->next = new ListNode(1);
            }
        }
        p = p->next;
    }
    return h;
}

int lengthOfLongestSubstring(string s) {
    deque<char> deq;
    unordered_set<char> myset;
    int maxCount = 0;
    for (int i = 0; i < s.length(); i++) {
        char cc = s[i];
        //cout <<cc<<endl;
        if (myset.find(cc) == myset.end()) {
            myset.insert(cc);
            deq.push_back(cc);
        } else {
            if (deq.size() > maxCount) {
                maxCount = deq.size();
            }
            while (deq.front() != cc) {
                myset.erase(deq.front());
                deq.pop_front();
            }
            deq.push_back(cc);
            deq.pop_front();
        }
    }
    if (deq.size() > maxCount){
        maxCount = deq.size();
    }
    return maxCount;
}

inline string maxSubStr(const string& s, int a, int b){
    while (a >= 0 && b < s.length() && s[a] == s[b]) {
        a--;
        b++;
    }
    
}
//string longestPalindrome(string s) {
//    string res = "";
//    for(int i = 0; i < s.length() - 1; ++i){
//        int a = i;
//        int b = i + 1;
//        while(a >= 0 && b < s.length() && s[a] == s[b]){
//            a --;
//            b ++;
//        }
//        
//    }
//}


void leetcode(){
    cout << lengthOfLongestSubstring("c")<<endl;
}


