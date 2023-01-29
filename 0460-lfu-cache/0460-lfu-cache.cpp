class LFUCache {
  unordered_map<int, tuple<int, std::list<int>::iterator, int>> mp;
  unordered_map<int, std::list<int>> cnt;
  int capacity = 0, lowest_cnt = 1;

public:
  LFUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (capacity == 0) {
      return -1;
    }

    if (auto it = mp.find(key); it == mp.end()) {
      return -1;
    } else {
      auto &[value, node, count] = it->second;
      auto &list = cnt[count];
      list.erase(node);
      if (list.size() == 0 && count == lowest_cnt) {
        ++lowest_cnt;
      }

      auto &new_list = cnt[++count];
      new_list.push_back(key);
      node = --new_list.end();

      return value;
    }
  }

  void put(int key, int value) {
    if (capacity == 0) {
      return;
    }

    if (auto it = mp.find(key); it != mp.end()) {
      auto &[cur_value, node, count] = it->second;
      auto &list = cnt[count];
      list.erase(node);
      if (list.size() == 0 && count == lowest_cnt) {
        ++lowest_cnt;
      }
      auto &new_list = cnt[++count];
      new_list.push_back(key);
      cur_value = value;
      node = --new_list.end();
    } else if (mp.size() < capacity) {
      auto &list = cnt[1];
      list.push_back(key);
      mp.insert({key, tuple{value, --list.end(), 1}});
      lowest_cnt = 1;
    } else {
      auto &lowest_list = cnt[lowest_cnt];
      auto lru_key_it = lowest_list.begin();
      mp.erase(*lru_key_it);
      lowest_list.erase(lru_key_it);

      auto &list = cnt[1];
      list.push_back(key);
      mp.insert({key, tuple{value, --list.end(), 1}});
      lowest_cnt = 1;
    }
  }
};