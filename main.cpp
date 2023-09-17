// Population growth rate
#include <iostream>
using namespace std;

// Function to calculate the population growth rate
double CalculateGrowthRate(double birthRate, double deathRate) {
    return birthRate - deathRate;
}

// Function to estimate the population for the next year
double EstimateNextYearPopulation(double currentPopulation, double growthRate) {
    return currentPopulation * (1 + (growthRate / 100));
}

int main() {
    double startingPopulation, birthRate, deathRate;
    int yearsToProject;

    // Input starting population
    do {
        cout << "Enter the starting population (should be 2 or more): ";
        cin >> startingPopulation;
    } while (startingPopulation < 2);

    // Input birth rate (positive value)
    do {
        cout << "Enter the birth rate (should be a positive value): ";
        cin >> birthRate;
    } while (birthRate < 0);

    // Input for death rate with validation (positive value)
    do {
        cout << "Enter the death rate (should be a positive value): ";
        cin >> deathRate;
    } while (deathRate < 0);

    // Input the number of years to project in the future
    cout << "Enter the number of years to project in the future: ";
    cin >> yearsToProject;

    cout << "Year\tPopulation\tGrowth Rate (%)" << endl;

    for (int year = 1; year <= yearsToProject; ++year) {
        double growthRate = CalculateGrowthRate(birthRate, deathRate);
        double estimatedPopulation = EstimateNextYearPopulation(startingPopulation, growthRate);

        cout << year << "\t" << estimatedPopulation << "\t\t" << growthRate << endl;

        // Update the starting population
        startingPopulation = estimatedPopulation;
    }

    return 0;
}
