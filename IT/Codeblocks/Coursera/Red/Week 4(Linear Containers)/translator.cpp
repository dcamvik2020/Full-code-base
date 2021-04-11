#include "test_runner.h"
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <deque>      /// references to his elements don't invalidite

using namespace std;

class Translator {
private:
  deque<string> all_words;
  map<string_view, string_view> forward_dictionary;
  map<string_view, string_view> backward_dictionary;
  
  string_view Remember (string_view word) {
    ///      bad way to check existance
    //auto it = find(all_words.find(word);
    
    /// good way to check existance of the word
    for (const auto* map_ptr : {&forward_dictionary, &backward_dictionary}) {
      auto it = map_ptr -> find(word);
      if (it != map_ptr -> end()) {
        return it -> first; // the word we look for
      }
    }
    return all_words.emplace_back(string(word));
  }
public:
  void print() const {
    cout << "Translator :" << "\n";
    for (const auto & p : forward_dictionary) {
      cout << setw(14) << p.first << " " << p.second << "\n";
    }
  }
public:
  void Add(string_view source, string_view target) {
    string_view s1 = Remember(source);
    string_view s2 = Remember(target);
    forward_dictionary[s1] = s2;
    backward_dictionary[s2] = s1;
  }
  string_view TranslateForward(string_view source) const {
    if (forward_dictionary.count(source) > 0) {
      return forward_dictionary.at(source);
    }
    return "";
  }
  string_view TranslateBackward(string_view target) const {
    if (backward_dictionary.count(target) > 0) {
      return backward_dictionary.at(target);
    }
    return "";
  }
};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));


  //translator.print();

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
