

#include <bits/stdc++.h>
using namespace std;

// Convert string number from base `b` to decimal
long long baseToDecimal(const string &num, int base) {
    long long result = 0;
    for(char c : num) {
        int digit;
        if(c >= '0' && c <= '9') digit = c - '0';
        else if(c >= 'a' && c <= 'z') digit = 10 + (c - 'a');
        else if(c >= 'A' && c <= 'Z') digit = 10 + (c - 'A');
        else continue; 
        result = result * base + digit;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read entire JSON input
    string json, line;
    while (getline(cin, line)) {
        json += line;
    }

    // Extract n and k
    int n = 0, k = 0;
    {
        size_t pos = json.find("\"n\"");
        if (pos != string::npos) sscanf(json.c_str() + pos, "\"n\": %d", &n);
        pos = json.find("\"k\"");
        if (pos != string::npos) sscanf(json.c_str() + pos, "\"k\": %d", &k);
    }

    int m = k - 1; // degree of polynomial
    cout << "n = " << n << ", k = " << k << ", degree = " << m << "\n";

    // Regex to capture roots
    regex re("\"[0-9]+\"\\s*:\\s*\\{\\s*\"base\"\\s*:\\s*\"([0-9]+)\"\\s*,\\s*\"value\"\\s*:\\s*\"([0-9a-zA-Z]+)\"\\s*\\}");
    smatch match;

    auto begin = sregex_iterator(json.begin(), json.end(), re);
    auto end = sregex_iterator();

    vector<long long> roots;
    for (auto it = begin; it != end; ++it) {
        int base = stoi((*it)[1]);
        string value = (*it)[2];
        long long decimalValue = baseToDecimal(value, base);
        roots.push_back(decimalValue);
    }

    cout << "Roots (decimal): ";
    for (auto r : roots) cout << r << " ";
    cout << "\n";

    // Take first m roots to compute constant term
    long long product = 1;
    for (int i = 0; i < m && i < (int)roots.size(); i++) {
        product *= roots[i];
    }

    long long C = ((m % 2 == 0) ? 1 : -1) * product;
    cout << "Constant C = " << C << "\n";

    return 0;
}
