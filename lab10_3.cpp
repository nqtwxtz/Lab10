#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ifstream source("score.txt");
    string line;
    double sum = 0;
    double sum_pow2 = 0;
    int count = 0;

    while (getline(source, line)) {
        if(line.empty()) continue;
        double value = atof(line.c_str());
        sum += value;
        sum_pow2 += value * value;
        count++;
    }

    if (count > 0) {
        double mean = sum / count;
        double sd = sqrt((sum_pow2 / count) - (mean * mean));

        cout << "Number of data = " << count << endl;
        
        cout << "Mean = " << setprecision(3) << mean << endl;
        cout << "Standard deviation = " << setprecision(3) << sd << endl;
    }

    source.close();
    return 0;
}