#include <iostream>
#include <cmath>       // for sin, cos, tan, log, pow, sqrt
#include <iomanip>     // for formatting output
using namespace std;

void showMenu() {
    cout << "\n=========================================\n";
    cout << "      🔹 SCIENTIFIC CALCULATOR 🔹       \n";
    cout << "=========================================\n";
    cout << " 1. Addition (+)\n";
    cout << " 2. Subtraction (-)\n";
    cout << " 3. Multiplication (*)\n";
    cout << " 4. Division (/)\n";
    cout << " 5. Power (x^y)\n";
    cout << " 6. Square Root (√x)\n";
    cout << " 7. Logarithm (log base e)\n";
    cout << " 8. Sine (sin x)\n";
    cout << " 9. Cosine (cos x)\n";
    cout << "10. Tangent (tan x)\n";
    cout << " 0. Exit\n";
    cout << "-----------------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double num1, num2, result;

    cout << fixed << setprecision(4); // show up to 4 decimal places

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 + num2;
                cout << "Result = " << result << endl;
                break;

            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 - num2;
                cout << "Result = " << result << endl;
                break;

            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 * num2;
                cout << "Result = " << result << endl;
                break;

            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 == 0)
                    cout << "❌ Error: Division by zero!" << endl;
                else
                    cout << "Result = " << num1 / num2 << endl;
                break;

            case 5:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                result = pow(num1, num2);
                cout << "Result = " << result << endl;
                break;

            case 6:
                cout << "Enter number: ";
                cin >> num1;
                if (num1 < 0)
                    cout << "❌ Error: Negative number!" << endl;
                else
                    cout << "Result = " << sqrt(num1) << endl;
                break;

            case 7:
                cout << "Enter number: ";
                cin >> num1;
                if (num1 <= 0)
                    cout << "❌ Error: log undefined for non-positive values!" << endl;
                else
                    cout << "Result = " << log(num1) << endl;
                break;

            case 8:
                cout << "Enter angle (in radians): ";
                cin >> num1;
                cout << "sin(" << num1 << ") = " << sin(num1) << endl;
                break;

            case 9:
                cout << "Enter angle (in radians): ";
                cin >> num1;
                cout << "cos(" << num1 << ") = " << cos(num1) << endl;
                break;

            case 10:
                cout << "Enter angle (in radians): ";
                cin >> num1;
                cout << "tan(" << num1 << ") = " << tan(num1) << endl;
                break;

            case 0:
                cout << "\n👋 Thank you for using the Scientific Calculator!\n";
                break;

            default:
                cout << "❌ Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
