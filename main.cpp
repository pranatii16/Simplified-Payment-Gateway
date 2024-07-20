#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int sendOTP() {
    srand(time(0));
    return rand() % 9000 + 1000; // Generate a 4-digit OTP
}


bool detectFraud(double amount) {
    // Simple rule: Transactions over 5000 are flagged as potential fraud
    if (amount > 5000) {
        return true;
    }
    return false;
}

int main() {
    string username = "user";
    string password = "pass";
    string enteredUsername, enteredPassword;
    int enteredOTP, generatedOTP;

    
    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    if (enteredUsername == username && enteredPassword == password) {
        cout << "Login successful!" << endl;

        
        generatedOTP = sendOTP();
        cout << "An OTP has been sent to your registered mobile number." << endl;
        cout << "Enter OTP: ";
        cin >> enteredOTP;

        if (enteredOTP == generatedOTP) {
            cout << "2FA successful!" << endl;

            
            double amount;
            cout << "Enter transaction amount: ";
            cin >> amount;

            if (detectFraud(amount)) {
                cout << "Transaction flagged as potential fraud. Please contact customer support." << endl;
            } else {
                cout << "Transaction successful!" << endl;
            }
        } else {
            cout << "Invalid OTP. 2FA failed." << endl;
        }
    } else {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}
