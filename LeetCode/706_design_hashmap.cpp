// chained hashing

class MyHashMap {
  vector<list<pair<int, int>>> mem;
  int m_size = 1000;

public:
  /** Initialize your data structure here. */
  MyHashMap() { mem.resize(m_size); }

  /** value will always be non-negative. */
  void put(int key, int value) {
    auto &l = mem[key % m_size];

    for (auto &pair : l)
      if (pair.first == key)
        pair.second = value;

    l.emplace_back(key, value);
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    auto &l = mem[key % m_size];

    for (auto &pair : l)
      if (pair.first == key)
        return pair.second;

    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    auto &l = mem[key % m_size];

    l.remove_if([key](auto &pair) { return pair.first == key; });
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

// simple solution

class MyHashMap {
  vector<int> mem;

public:
  /** Initialize your data structure here. */
  MyHashMap() { mem = vector<int>(1000001, -1); }

  /** value will always be non-negative. */
  void put(int key, int value) { mem[key] = value; }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) { return mem[key]; }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) { mem[key] = -1; }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
