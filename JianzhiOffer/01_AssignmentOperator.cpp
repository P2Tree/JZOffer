// 题目：编写一个类的赋值运算符重载成员函数。

#include <iostream>
#include <string>

class CString {
private:
  unsigned int Len;
  char *Data;
public:
  CString() : Len(0), Data(nullptr) {}
  CString(const CString &str) {
    Len = str.size();
    Data = new char[Len];
    memcpy(Data, str.getData(), sizeof(char) * Len);
  }
  CString(char *str) {
    if (str == nullptr) {
      Len = 0;
      Data = nullptr;
      return;
    }
      
    Len = 0;
    char *sp = str;
    while (*sp != '\0') {
      Len++;
      sp++;
    }
    Data = new char[Len];
    memcpy(Data, str, sizeof(char) * Len);
  }
  
  CString& operator=(const CString &cstr) {
    if (&cstr == this)
      return *this;
    if (cstr.size() == 0) {
      if (Data != nullptr) {
        delete [] Data;
        Data = nullptr;
      }
      Len = 0;
      return *this;
    }
    Len = cstr.size();
    Data = new char[Len];
    memcpy(Data, cstr.getData(), sizeof(char) * Len);
    return *this;
  }
  
  ~CString() {
    if (Data == nullptr)
      return;
    delete []Data;
    Data = nullptr;
    Len = 0;
  }

  unsigned int size() const {
    return Len;
  }
  char * getData() const {
    return Data;
  }
  
  friend std::ostream& operator<<(std::ostream& os, const CString& cstr);
  
};

std::ostream& operator<<(std::ostream& os, const CString& cstr) {
  unsigned int len = 0;
  while (len < cstr.size()) {
    os << cstr.getData()[len++];
  }
  return os;
}

int main(int argc, const char * argv[]) {
  char str[4] = "abc";
  CString a(str);
  std::cout << a << std::endl;
  CString b(a);
  std::cout << b << std::endl;
  CString c;
  c = b = a;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  CString d;
  c = d;
  std::cout << c << std::endl;
  return 0;
}
