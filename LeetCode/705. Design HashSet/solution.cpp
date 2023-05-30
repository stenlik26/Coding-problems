#include <iostream>
using namespace std;

class MyHashSet {
private:
    bool* set;
public:
    ~MyHashSet()
    {
        delete[] set;
    }

    MyHashSet() {
        this->set = new bool[1000001] {0};
    }

    void add(int key) {
        set[key] = true;
    }

    void remove(int key) {
        set[key] = false;
    }

    bool contains(int key) {
        return set[key];
    }
};


int main()
{
    MyHashSet set;

    set.add(1);
    set.add(2);
    set.add(3);
    set.add(1000000);

    cout << set.contains(1) << endl;
    cout << set.contains(2) << endl;
    cout << set.contains(3) << endl;
    cout << set.contains(1000006) << endl;
}
