// trie based solution

class TrieNode {
public:
  unordered_map<char, TrieNode *> nxt;
};

class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    int result = 0;
    TrieNode *root = new TrieNode();
    TrieNode *cur = root;
    vector<pair<TrieNode *, int>> leaves;

    for (string word : unordered_set<string>(words.begin(), words.end())) {
      cur = root;
      for (int i = word.length() - 1; i >= 0; --i) {
        if (cur->nxt.count(word[i]) == 0)
          cur->nxt[word[i]] = new TrieNode();
        cur = cur->nxt[word[i]];
      }
      leaves.emplace_back(cur, word.length());
    }

    for (auto &leaf : leaves)
      result += leaf.first->nxt.size() == 0 ? leaf.second + 1 : 0;

    return result;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

// efficient sorting based solution

class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    int result = 0;
    for (string &word : words)
      reverse(word.begin(), word.end());
    sort(words.begin(), words.end());
    for (int i = 0; i < words.size() - 1; ++i)
      result += words[i] == words[i + 1].substr(0, words[i].length())
                    ? 0
                    : words[i].length() + 1;

    return result + words[words.size() - 1].length() + 1;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

// set based solution

class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    int result = 0;
    unordered_set<string> s(words.begin(), words.end());

    for (string word : s) {
      for (int i = 1; i < word.length(); ++i) {
        s.erase(word.substr(i));
      }
    }

    for (string word : s) {
      result += word.length() + 1;
    }

    return result;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
