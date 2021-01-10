// bidirectional bfs

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wList(wordList.begin(), wordList.end()), start, end, *p_start, *p_end;
        if (wList.count(endWord) == 0)
            return 0;

        int result = 2;
        start.insert(beginWord);
        end.insert(endWord);
        char tmp_char;

        while (start.size() && end.size())
        {
            if (start.size() <= end.size())
            {
                p_start = &start;
                p_end = &end;
            }
            else
            {
                p_start = &end;
                p_end = &start;
            }

            unordered_set<string> tmp;
            for (string word : *p_start)
            {
                for (int i = 0; i < word.length(); ++i)
                {
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c != word[i])
                        {
                            tmp_char = word[i];
                            word[i] = c;
                            if (p_end->count(word))
                                return result;

                            if (wList.count(word))
                            {
                                tmp.insert(word);
                                wList.erase(word);
                            }

                            word[i] = tmp_char;
                        }
                    }
                }
            }
            p_start->swap(tmp);
            ++result;
        }

        return 0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// standard bfs solution

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wList(wordList.begin(), wordList.end());
        if (wList.count(endWord) == 0)
            return 0;
        if (wList.count(beginWord))
            wList.erase(beginWord);

        int result = 0, q_size = 0;
        queue<string> Q;
        Q.push(beginWord);
        string cur;
        char tmp;

        while (Q.size())
        {
            q_size = Q.size();
            while (q_size--)
            {
                cur = Q.front();
                Q.pop();

                if (cur == endWord)
                    return result + 1;

                for (int i = 0; i < cur.length(); ++i)
                {
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c != cur[i])
                        {
                            tmp = cur[i];
                            cur[i] = c;
                            if (wList.count(cur))
                            {
                                Q.push(cur);
                                wList.erase(cur);
                            }
                            cur[i] = tmp;
                        }
                    }
                }
            }
            ++result;
        }

        return 0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();