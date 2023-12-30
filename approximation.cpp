#include <fstream>
#include <iostream>

using namespace std;

// Function to approximate pi using a series
double calculatePi()
{
    int num = 1;
    double pi = 0.0;
    int othernum = 3;

    cout << "Initial value of pi: " << pi << endl;

    // Tweak the loop values to get a better approximation
    for (int i = 0; i < 1000000 + 1; i++)
    {
        if (othernum == num)
        {
            double term = -(4.0 / num) + 4;
            term -= 4;
            pi = pi + term;
            othernum += 4;
            cout << "Term: " << (4.0 / num) << endl;
        }
        else
        {
            pi = (4.0 / num) + pi;
            cout << "Term: " << (4.0 / num) << endl;
        }

        num += 2;

        // Display current iteration details
        cout << "-------------------" << endl;
        cout << "Current pi: " << pi << endl;
        cout << "Current num: " << num << endl;
        cout << "Current othernum: " << othernum << endl;
        cout << "-------------------" << endl;
    }

    return pi;
}

// Function to write the result to a file
void writeToFile(double value)
{
    ofstream myFile("PiApproximation.txt");
    myFile << fixed << value; // Use fixed to prevent scientific notation
    myFile.close();
}

int main()
{
    cout << "Approximation of Pi: \n";
    cout << "Actual PI: 3.14159265359\n\n";
    cout << "Note: It is recommended to run this code in an environment like "
            "replit. Look at PiApproximation.txt to see the output. Tweak the "
            "values in the for loop for a closer approximation. :)\n\n";

    // Calculate pi approximation and write to file
    double piApproximation = calculatePi();
    writeToFile(piApproximation);

    return 0;
}
