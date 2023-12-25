#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

bool compare_double(const double &x1, const double y1)
{
    return abs(x1 - y1) < 0.01;
}

void parse_input(const char *filename, vector<vector<long>> &mat)
{

    std::ifstream input_file;
    input_file.open(filename);

    if (!input_file.is_open())
        return;

    string input_line;

    while (input_file.good())
    {
        vector<long> coords;
        for (size_t i = 0; i < 7; i++)
        {
            input_file >> input_line;

            if (input_line == "@")
                continue;

            int coef = 1;
            if (input_line[0] == '-')
            {
                input_line.erase(0, 1);
                coef = -1;
            }

            if (input_line[input_line.size() - 1] == ',')
                input_line.pop_back();

            coords.push_back(stol(input_line) * coef);
        }
        mat.push_back(coords);
    }
}

void get_slope_eq(vector<vector<long>> &mat, vector<vector<double>> &slope_eq)
{
    for (size_t i = 0; i < mat.size(); i++)
    {
        vector<double> current;
        long &x1 = mat[i][0];
        long &y1 = mat[i][1];
        long &vx = mat[i][3];
        long &vy = mat[i][4];

        long x2 = x1 + vx;
        long y2 = y1 + vy;

        double m = (double)(y2 - y1) / (x2 - x1);

        double b = y1 - m * x1;
        current.push_back(m);
        current.push_back(b);
        slope_eq.push_back(current);
    }
}

bool future_dir(const double &intersect_x,
                const double &point_x,
                const double &vx)
{
    double temp = intersect_x - point_x;
    return (temp > 0 && vx > 0) || (temp < 0 && vx < 0);
}

bool intersect_in(
    const vector<double> &slope1, 
    const vector<double> &slope2,
    const vector<long> &coords1,
    const vector<long> &coords2,
    const long long const1, 
    const long long const2)
{
    const double &m1 = slope1[0];
    const double &b1 = slope1[1];

    const double &m2 = slope2[0];
    const double &b2 = slope2[1];

    double m_res = m2 - m1;
    double b_res = b1 - b2;

    if (m_res == 0)
    {
        cout << "No intersection: " << endl;
        return (b_res == 0);
    }

    double x_res = b_res / m_res;

    double y_res = m1 * x_res + b1;

    cout << "x = " << x_res << " y = " << y_res;

    if(!future_dir(x_res, coords1[0], coords1[3]) || !future_dir(x_res, coords2[0], coords2[3]))
    {
        cout << " Past intersection!!"<<endl;
        return false;
    }

    cout << endl;

    return (x_res >= const1) && (x_res <= const2) && (y_res >= const1) && (y_res <= const2);
    
}

int main()
{
    vector<vector<long>> coords;
    vector<vector<double>> slope_eq;

    parse_input("input.txt", coords);
    get_slope_eq(coords, slope_eq);

    const double atleast = 200000000000000;
    const double atmost = 400000000000000;

    int valid = 0;
    for (size_t i = 0; i < slope_eq.size(); i++)
    {
        for (size_t j = i + 1; j < slope_eq.size(); j++)
        {
            // cout << intersect_in(slope_eq[i], slope_eq[j], 7, 27) << endl;
            //if(intersect_in(slope_eq[i], slope_eq[j], coords[i], coords[j], 7, 27))
            if(intersect_in(slope_eq[i], slope_eq[j], coords[i], coords[j], atleast, atmost))
                valid++;
        }
    }
    cout << valid<<endl;

    return 0;
}