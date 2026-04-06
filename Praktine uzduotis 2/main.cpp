#include <iostream>
#include <string>

using namespace std;

// Maksimalus mokynių skaičius ir kiek kievienas gali turėti pažymių
const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

int main() {
    // Masyvai vardams ir pažymiams
    string vardai[MAX_MOKINIU]; 
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazymiuKiekis[MAX_MOKINIU] = {0}; 
    int mokiniuSkaicius = 0; 
    int pasirinkimas;

    do {
        cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. Prideti mokini ir pazymius\n";
        cout << "2. Rodyti visus mokinius\n";
        cout << "3. Rodyti konkretaus mokinio pazymius\n";
        cout << "4. Pakeisti pazymi\n";
        cout << "5. Istrinti mokini\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            if (mokiniuSkaicius < MAX_MOKINIU) {
                cout << "Iveskite varda: ";
                cin >> vardai[mokiniuSkaicius];
                
                int kiek;
                cout << "Kiek pazymiu (max " << MAX_PAZYMIU << ")? ";
                cin >> kiek;
            }
        }
            }
    return 0;
}
