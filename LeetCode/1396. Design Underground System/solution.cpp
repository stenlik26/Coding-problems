#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:

    unordered_map<int, pair<string, int>> check_ins;
    unordered_map <string, pair<uint32_t, uint32_t>> times;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        check_ins[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        string station_key = check_ins[id].first + "-" + stationName;

        times[station_key].first += t - check_ins[id].second;
        times[station_key].second++;

        check_ins.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        pair<uint32_t, uint32_t>& pair = times[startStation + "-" + endStation];
        return pair.first / (double)pair.second;
    }
};
int main()
{
    UndergroundSystem* undergroundSystem = new UndergroundSystem();
    undergroundSystem->checkIn(45, "Leyton", 3);
    undergroundSystem->checkIn(32, "Paradise", 8);
    undergroundSystem->checkIn(27, "Leyton", 10);
    undergroundSystem->checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    undergroundSystem->checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    undergroundSystem->checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    cout << undergroundSystem->getAverageTime("Paradise", "Cambridge") << " =? 14.00" << endl; // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << " =? 11.00" << endl;    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem->checkIn(10, "Leyton", 24);
    cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << " =? 11.00" << endl;   // return 11.00000
    undergroundSystem->checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << " =? 12.00" << endl;    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
}
