#include <iostream>
#include <vector>
using namespace std;

vector<double> Hebb(vector<vector<double>>& input, vector<double>& output)
{
    vector<double> weight(input.size(), 0.0);

    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[i].size(); ++j) {

            weight[i] += ((1.0 / input[i][j]) * output[j]) / input[i].size();
        }
    }
    return weight;
}

vector<double> Testing(vector<vector<double>>& input, vector<double>& output, vector<double>& weight)
{
    vector<double> Z(output.size(), 0.0);

    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < input.size(); j++) {
            Z[i] += weight[j] * input[j][i];
        }
        if (Z[i] > 0.0) {
            Z[i] = 1;
        }
        else {
            Z[i] = -1;
        }
    }
    return Z;
}

int main()
{
    vector<vector<double>> input = { {1, 1, 1, 1}, {1, 0.5, -0.5, -1}, {1, -0.3, 0.7, -1} };
    vector<vector<double>> output = { { 1, 1, 1, 1 }, { 1, 1, 1, -1 }, { 1, 1, -1, 1 }, {1, 1, -1, -1 },
        {1, -1, 1, 1 }, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, -1, -1, -1}, {-1, 1, 1, 1}, {-1, 1, 1, -1},
        {-1, 1, -1, 1}, {-1, 1, -1, -1}, {-1, -1, 1, 1}, {-1, -1, 1, -1}, {-1, -1, -1, 1}, {-1, -1, -1, -1} };

    for (int i = 0; i < output.size(); i++) {
        vector<double> weights = Hebb(input, output[i]);
        vector<double> results = Testing(input, output[i], weights);

        cout << "Weighting vector " << i + 1 << ": ";

        for (int j = 0; j < input.size(); j++) {
            cout << weights[j] << ", ";
        }
        
        cout << endl << "Output " << i + 1 << ": ";

        for (int j = 0; j < output[i].size(); j++) {
            cout << results[j] << ", ";
        }
        cout << endl;
    }
    return 0;
}





