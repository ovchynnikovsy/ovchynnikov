#include <iostream>
#include <cmath>
using namespace std;

// --- Task 1: Calculate the perimeter of a rectangle ---
double RectP(double x1, double y1, double x2, double y2) {
    // Check the range of input data
    if (x1 < -100 || x1 > 100 || y1 < -100 || y1 > 100 || 
        x2 < -100 || x2 > 100 || y2 < -100 || y2 > 100) {
        cout << "Error: Coordinates must be within the range [-100, 100]!\n";
        return -1; // Return an error value
    }
    // Calculate width, height, and perimeter
    double width = abs(x2 - x1);
    double height = abs(y2 - y1);
    return 2 * (width + height);
}

// --- Task 2: Check if the triangle is equilateral ---
bool isEquilateral(int a, int b, int c) {
    // Check the range of input data
    if (a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100) {
        cout << "Error: Side lengths must be within the range [-100, 100]!\n";
        return false; // Treat the triangle as invalid
    }
    // Check if all sides are equal
    return a == b && b == c;
}

// --- Task 3: Calculate the number of full tons ---
int fullTons(int M) {
    // Check the range of input data
    if (M < 0 || M > 100000) { // Assuming mass cannot be negative
        cout << "Error: Mass must be within the range [0, 100000]!\n";
        return -1; // Return an error value
    }
    // Calculate the number of tons
    return M / 1000;
}

int main() {
    int choice;

    do {
        // Main menu
        cout << "\nSelect a task to execute:\n";
        cout << "1. Task 1: Calculate the perimeter of rectangles\n";
        cout << "2. Task 2: Check if a triangle is equilateral\n";
        cout << "3. Task 3: Calculate the number of full tons\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Task 1: Rectangle perimeter
                cout << "Enter the coordinates of 3 rectangles (x1, y1, x2, y2):\n";
                for (int i = 0; i < 3; i++) {
                    double x1, y1, x2, y2;
                    cout << "Rectangle " << i + 1 << ": ";
                    cin >> x1 >> y1 >> x2 >> y2;
                    double perimeter = RectP(x1, y1, x2, y2);
                    if (perimeter != -1) {
                        cout << "Perimeter: " << perimeter << endl;
                    }
                }
                break;
            }
            case 2: {
                // Task 2: Equilateral triangle check
                int a, b, c;
                cout << "Enter the sides of the triangle (a, b, c): ";
                cin >> a >> b >> c;
                if (isEquilateral(a, b, c)) {
                    cout << "The triangle is equilateral\n";
                } else {
                    cout << "The triangle is not equilateral or has invalid data\n";
                }
                break;
            }
            case 3: {
                // Task 3: Number of full tons
                int M;
                cout << "Enter mass in kilograms: ";
                cin >> M;
                int tons = fullTons(M);
                if (tons != -1) {
                    cout << "Number of full tons: " << tons << endl;
                }
                break;
            }
            case 0:
                // Exit the program
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
