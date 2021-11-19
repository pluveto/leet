#include <debug.h>
// 去除连续字符
string remove_dup(string s) {
  if (s.size() <= 1) {
    return s;
  }
  int n = s.size();
  string ret;
  ret.push_back(s[0]);
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      continue;
    }
    ret.push_back(s[i]);
  }
  return ret;
}
bool is_sub_sq(string parent, string child) {
  if (parent.size() < child.size()) {
    return false;
  }
  auto l = remove_dup(parent);
  auto r = remove_dup(child);
  // 只要 r 中的字符在 l 中出现过，就返回 true
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < l.size(); j++) {
      if (r[i] == l[j]) {
        return true;
      }
    }
  }

  auto ret = (l == r);
  cout << parent << "," << child << " " << l << "," << r << " " << ret << endl;
  return ret;
}


bool isSubsequence(string t, string s) {
  int n = s.length(), m = t.length();
  if (m < n) {
    return false;
  }
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }
  return i == n;
}

class Solution {
public:
  int findLUSlength(vector<string> &strs) {
    auto n = strs.size();
    // 排序
    sort(strs.begin(), strs.end());    
    set<string> ss;
    set<string> dup; // 记录具体是谁重复
    for (auto &&s : strs) {
      auto itr = ss.find(s);
      if (itr != ss.end()) {
        dup.insert(s);
        continue;
      }      
      ss.insert(s);
    }
    // 去重
    for (auto ssitr = ss.begin(); ssitr != ss.end();) {
      bool eraseFlag = false;
      for (auto &&d : dup) {
        if (isSubsequence(d, *ssitr)) {
          ssitr = ss.erase(ssitr);
          eraseFlag = true;
          break;
        }
      }
      if (!eraseFlag)
        ssitr++;
    }
    // 返回最长
    int maxlen = -1;
    for (auto &&s : ss) {
      int sn = s.size();
      maxlen = max(sn, maxlen);
    }

    return maxlen;
  }
};


int main(int argc, char const *argv[]) {
  Solution s;
  // ["abaa","aba","aba"] => 4
  // ["abaa","abaa","aba"] => 3
  //   vector<string> vs = {"bb", "aba", "bb", "bb", "abba",
  //   "abbb","cccccc","cccccc"};
  //   vector<string> vs = {"aaa", "aaa", "aa"};
  vector<string> vs = {"aabbcc", "aabbcc", "cb", "abc"};
  //   vector<string> vs = {"abaa", "aba", "aba"};
  //   vector<string> vs = {"aaa", "aaa", "a"};
  //   vector<string> vs = {"aabbcc", "aabbcc","c"};
  std::cout << s.findLUSlength(vs) << endl;
  return 0;
}