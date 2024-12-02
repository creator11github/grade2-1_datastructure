#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "bst.h"

using namespace std;

vector<int> generateRandomNumbers(int size, int minVal, int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);

    vector<int> numbers;
    for (int i = 0; i < size; ++i) {
        numbers.push_back(dis(gen));
    }
    return numbers;
}

int main() {
    int n, minVal, maxVal, numExperiments;

    cout << "Enter the number of elements to insert (n): ";
    cin >> n;
    
    cout << "Enter the minimum value for random numbers: ";
    cin >> minVal;

    cout << "Enter the maximum value for random numbers: ";
    cin >> maxVal;

    cout << "Enter the number of experiments: ";
    cin >> numExperiments;

    double totalHeight = 0; // used to calculate the average height

    for (int i = 0; i < numExperiments; ++i) {
        BinSearchTree<int> bst; // create a new binary search tree
        vector<int> randomNumbers = generateRandomNumbers(n, minVal, maxVal);

        cout << "Experiment " << i + 1 << ": Inserting numbers: ";
        for (int num : randomNumbers) {
            cout << num << " ";
            bst.insert(num); // insert the random number into the tree
        }
        cout << endl;

        int height = bst.height(); // get the height of the tree
        cout << "Tree height after insertion: " << height << endl;

        totalHeight += height; // add the height to the total height
    }

    double averageHeight = totalHeight / numExperiments;
    cout << "Average tree height after " << numExperiments << " experiments: " << averageHeight << endl;

    return 0;
}
