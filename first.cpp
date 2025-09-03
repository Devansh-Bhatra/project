#include <bits/stdc++.h>
using namespace std;

// Function to convert string number from base `b` to decimal
long long baseToDecimal(const string &num, int base) {
    long long result = 0;
    for(char c : num) {
        int digit;
        if(c >= '0' && c <= '9') digit = c - '0';
        else if(c >= 'a' && c <= 'f') digit = 10 + (c - 'a');
        else if(c >= 'A' && c <= 'F') digit = 10 + (c - 'A');
        else continue; // ignore invalid chars

        result = result * base + digit;
    }
    return result;
}

int main() {
    // Simulate reading JSON manually
    int n = 4; // number of roots
    int k = 3; // min roots required

    vector<pair<int, string>> roots = {
        {10, "4"},
        {2, "111"},
        {10, "12"},
        {4, "213"}
    };

    cout << "Converted roots in decimal:\n";
    for(auto &p : roots) {
        int base = p.first;
        string value = p.second;
        long long decimalValue = baseToDecimal(value, base);
        cout << "Base: " << base << " Value: " << value << " -> Decimal: " << decimalValue << "\n";
    }

    return 0;
}
