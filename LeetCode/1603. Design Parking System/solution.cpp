#include <iostream>
using namespace std;
class ParkingSystem {
public:

    uint32_t big_cap;
    uint32_t mid_cap;
    uint32_t small_cap;

    uint32_t big_count;
    uint32_t mid_count;
    uint32_t small_count;

    ParkingSystem(int big, int medium, int small) {

        big_cap = big;
        mid_cap = medium;
        small_cap = small;

        big_count = 0;
        mid_count = 0;
        small_count = 0;

    }

    bool addCar(int carType) {

        uint32_t* cap;
        uint32_t* count;

        switch (carType)
        {
        case 1: // big
            cap = &big_cap;
            count = &big_count;
            break;
        case 2: // medium
            cap = &mid_cap;
            count = &mid_count;
            break;
        case 3: // small
            cap = &small_cap;
            count = &small_count;
            break;
        default:
            return false;
            break;
        }

        if (*count < *cap)
        {
            (*count)++;
            return true;
        }
        else
            return false;
    }
};


int main()
{
    ParkingSystem* obj = new ParkingSystem(1, 1, 0);
    cout << obj->addCar(1) << endl;
    cout << obj->addCar(2) << endl;
    cout << obj->addCar(3) << endl;
    cout << obj->addCar(1) << endl;
}