#include <iostream>
#include <fstream>
#include <set>

struct Dictionary {
  Dictionary() {
    // load _words, here's one possible implementation:
    std::ifstream input("/usr/share/dict/words");
    for (std::string line; getline(input, line);) {
      _words.insert(line);
    }
  }
  bool contains(std::string const& word) const { return _words.count(word); }

  std::set<std::string> _words;
};