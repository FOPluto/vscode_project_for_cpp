#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

class Fu {
  protected:
    int n = 10;
};

class Zi : public Fu {
  public:
    void show()
    {
        cout << n << endl;
    }
};