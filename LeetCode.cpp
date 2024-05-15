#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

//stack and queue
//1) Max Nesting Depth of the Parenthese
class Solution {
public:
    int maxDepth(string s) {
            stack<char> st;
    int maxDepth = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c); 
            if (st.size() > maxDepth) {
                maxDepth = st.size();
            }
        } else if (c == ')') {
            st.pop();
        }
    }

    return maxDepth;        
    }
};
//kompleksiteti kohor është (O(n)), ( n ) është gjatësia e vargut ( s ). Kjo ndodh sepse ne iterojmë përmes vargut një herë, duke kryer operacione me kohë konstante për secilin karakter.
//Kompleksiteti hapësinor është (O(n)) në rastin më të keq, ku ( n ) është gjatësia e vargut ( s ). Kjo ndodh kur të gjithë karakteret janë (, duke kërkuar një madhësi staku të barabartë me gjatësinë e vargut.

//2)Baseball Game
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (const string& op : operations) {
            if (op == "C") {
                if (!record.empty()) {
                    record.pop_back();
                }
            } else if (op == "D") {
                if (!record.empty()) {
                    record.push_back(2 * record.back());
                }
            } else if (op == "+") {
                if (record.size() >= 2) {
                    record.push_back(record[record.size() - 1] + record[record.size() - 2]);
                }
            } else {
                record.push_back(stoi(op));
            }
        }

        int totalSum = 0;
        for (int score : record) {
            totalSum += score;
        }

        return totalSum;
    }
};
//Kompleksiteti kohor i këtij kodi është O(n).
//Kompleksiteti hapësinor i këtij kodi është O(n).

//3)First Unique Character in a string
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;

        for (char c : s) {
            charCount[c]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
//Kompleksiteti kohor (O(n))
//Kompleksiteti hapësinor (O(1)

//4)Remove Outermost parentheses
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    result += c; // Shto '(' në rezultat vetëm nëse është brenda stringut paraprak të jashtëm
                }
                opened++;
            } else if (c == ')') {
                opened--;
                if (opened > 0) {
                    result += c; // Shto ')' në rezultat vetëm nëse është brenda stringut paraprak të jashtëm
                }
            }
        }

        return result;
        
    }
};
//Kompleksiteti kohor (O(n))
//Kompleksiteti hapësinor (O(n))

//5) Remove All Adjecent Duplicates in String
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c); 
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
        
    }
};
//Kompleksiteti kohor (O(n))
//Kompleksiteti hapsinor (O(n))
