#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string& replaceSpace(string s) {
    int len = s.size();
    int space_len = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
      if (*iter == ' ') {
        space_len++;
      }
    }
    string *news = new string;
    news->resize(len + space_len * 2);
    auto endp = news->end() - 1;
    auto ends = s.end() - 1;
    while (ends != s.begin() - 1) {
      if (*ends == ' ') {
        *(endp--) = '0';
        *(endp--) = '2';
        *(endp--) = '%';
        ends--;
        continue;
      }
      *endp = *ends;
      endp--;
      ends--;
    }
    return *news;
  }
};

int main() {
  Solution so;
  string s = "we are happy.";
  string r = so.replaceSpace(s);
  cout << r << endl;
  return 0;
}
