#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int sayi = rand() % 101;
    int tahmin;
    const int MAX_HAK = 10;

    for (int hak = 1; hak <= MAX_HAK; hak++) {
        cout << "Enter your guess: ";
        
        // Input validation (If a character/letter is entered instead of a number)
        if (!(cin >> tahmin)) {
            cout << "Invalid input! Please enter a number." << endl;
            return 0;
        }
        
        // Boundary check
        if (tahmin < 0 || tahmin > 100) {
            cout << "Please enter a number between 0 and 100!" << endl;
            return 0;
        }

        // Correct guess check and performance evaluation
        if (tahmin == sayi) {
            if (hak <= 3) {
                cout << "Brilliant player! (Guessed on attempt " << hak << ")" << endl;
            } else if (hak <= 7) {
                cout << "Average smarts! (Guessed on attempt " << hak << ")" << endl;
            } else {
                cout << "Need more practice! (Guessed on attempt " << hak << ")" << endl;
            }
            return 0;
        } 
        
        // Hint messages (No need for hints on the final attempt)
        if (hak < MAX_HAK) {
            if (tahmin < sayi) cout << "Go higher!" << endl;
            else cout << "Go lower!" << endl;
        }
    }

    cout << "Game over! The number was: " << sayi << endl;
    return 0;
}
