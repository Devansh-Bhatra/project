#include <bits/stdc++.h>
using namespace std;

// Function to convert string number from base `b` to decimal
long long baseToDecimal(const string &num, int base) {
    long long result = 0;
    for(char c : num) {
        int digit;
        if(c >= '0' && c <= '9') digit = c - '0';
        else if(c >= 'a' && c <= 'z') digit = 10 + (c - 'a');
        else if(c >= 'A' && c <= 'Z') digit = 10 + (c - 'A');
        else continue; // ignore invalid chars

        result = result * base + digit;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read entire JSON input from stdin
    string json, line;
    while (getline(cin, line)) {
        json += line;
    }

    // Extract n and k
    int n = 0, k = 0;
    {
        size_t pos = json.find("\"n\"");
        if (pos != string::npos) {
            sscanf(json.c_str() + pos, "\"n\": %d", &n);
        }
        pos = json.find("\"k\"");
        if (pos != string::npos) {
            sscanf(json.c_str() + pos, "\"k\": %d", &k);
        }
    }

    cout << "n = " << n << ", k = " << k << "\n";

    // Regex to capture each "index": { "base": "...", "value": "..." }
    regex re("\"[0-9]+\"\\s*:\\s*\\{\\s*\"base\"\\s*:\\s*\"([0-9]+)\"\\s*,\\s*\"value\"\\s*:\\s*\"([0-9a-zA-Z]+)\"\\s*\\}");
    smatch match;

    auto begin = sregex_iterator(json.begin(), json.end(), re);
    auto end = sregex_iterator();

    cout << "Converted roots in decimal:\n";
    for (auto it = begin; it != end; ++it) {
        int base = stoi((*it)[1]);
        string value = (*it)[2];
        long long decimalValue = baseToDecimal(value, base);
        cout << "Base: " << base << " Value: " << value << " -> Decimal: " << decimalValue << "\n";
    }

    return 0;
}

