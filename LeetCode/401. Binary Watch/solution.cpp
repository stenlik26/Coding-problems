#include <iostream>
#include <vector>
#include <string>
using namespace std;

const uint16_t count_bits(uint16_t num)
{
	uint16_t x = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if ((1 << i) & num)
			x++;
	}
	return x;
}

const uint16_t two_pow(int x)
{
	return 1 << x;
}

const uint16_t get_hours(uint16_t num)
{
	uint16_t hours = 0;
	hours += (bool)(num & (1 << 9)) * 8;
	hours += (bool)(num & (1 << 8)) * 4;
	hours += (bool)(num & (1 << 7)) * 2;
	hours += (bool)(num & (1 << 6)) * 1;

	return hours;
}

const uint16_t get_minutes(uint16_t num)
{
	uint16_t minutes = 0;

	for (size_t i = 0; i <= 5; i++)
	{
		minutes += (bool)(num & (1 << i)) * two_pow(i);
	}

	return minutes;
}


const string format_time(uint16_t hours, uint16_t mins)
{ 
	string result = "";

	result += to_string(hours);

	result += ":";

	if (mins < 10)
		result += "0";

	result += to_string(mins);
	return result;
}

vector<string> readBinaryWatch(int turnedOn) {
	vector<string> res;

	for (uint16_t i = 0; i < 1024; i++)
	{
		if (count_bits(i) == turnedOn)
		{
			uint16_t hours, minutes;

			hours = get_hours(i);
			minutes = get_minutes(i);

			if (hours >= 12 || minutes > 59)
				continue;

			res.push_back(format_time(hours, minutes));
		}
	}
	return res;
}

int main()
{
	vector<string> res = readBinaryWatch(2);

	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}
