#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Function that returns true if a simple graph exists
bool graphExists(vector<int> &a) {
    while (true) {
        // Sort the list in non-increasing order
        sort(a.begin(), a.end(), greater<int>());

        // Check if all the elements are equal to 0
        if (a[0] == 0) return true;

        // Store the first element in a variable and delete it from the list
        int v = a[0];
        a.erase(a.begin());

        // Check if enough elements are present in the list
        if (v > a.size()) return false;

        // Subtract 1 from the next v elements
        for (int i = 0; i < v; i++) {
            a[i]--;

            // Check if negative element is encountered after subtraction
            if (a[i] < 0) return false;
        }
    }
}

// Function to read the degree sequence from the user
vector<int> readSequence() {
    vector<int> sequence;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        sequence.push_back(number);
    }
    return sequence;
}

// Driver Code
int main() {
    string input;
    cout << "Enter degree sequences (separated by space), or 'q' to quit:" << endl;

    while (true) {
        cout << "> ";
        getline(cin, input);
        
        if (input == "q" || input == "Q") break;
        
        stringstream ss(input);
        vector<int> a;
        int temp;
        while (ss >> temp) {
            a.push_back(temp);
        }

        graphExists(a) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
