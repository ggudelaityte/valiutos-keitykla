#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

const int MENU_SIZE = 8; // Meniu elementų skaičius

// Funkcijų prototipai
void getData(menuItemType menuList[]);
void showMenu(menuItemType menuList[]);
void printCheck(menuItemType menuList[], int orderQuantities[]);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    menuItemType menuList[MENU_SIZE];
    int orderQuantities[MENU_SIZE] = {0}; // Masyvas, kuriame saugoma kiek porcijų kiekvieno patiekalo užsakyta

    // duomenų nuskaitymas iš failo
    getData(menuList);

    // Parodo meniu
    showMenu(menuList);

    int choice;
    int quantity;

    // Vartotojo pasirinkimų ciklas
    cout << "\nIveskite patiekalo numeri (1-" << MENU_SIZE << ") arba 0, jei norite baigti: ";
    while (cin >> choice && choice != 0) {
        if (choice > 0 && choice <= MENU_SIZE) {
            cout << "Kiek porciju norite? ";
            cin >> quantity;
            if (quantity > 0) {
                // Pridedame užsakytą kiekį prie patiekalo
                orderQuantities[choice - 1] += quantity;
                cout << "Prideta" << endl;
            } else {
                cout << "Neteisingas kiekis." << endl;
            }
        } else {
            cout << "Neteisingas pasirinkimas. Bandykite is naujo." << endl;
        }
        cout << "Iveskite patiekalo numeri (1-" << MENU_SIZE << ") arba 0, jei norite baigti: ";
    }

    // Atspausdiname sąskaitą į ekraną ir į failą
    printCheck(menuList, orderQuantities);

    return 0;
}

// nuskaito duomenis iš tekstinio failo
void getData(menuItemType menuList[]) {
    ifstream inFile("menu.txt"); // Atidarome failą

    if (!inFile) {
        cout << "Klaida- nepavyko atidaryti menu.txt failo" << endl;
        return;
    }

    for (int i = 0; i < MENU_SIZE; i++) {
        getline(inFile, menuList[i].menuItem); // Nuskaito pavadinimą
        inFile >> menuList[i].menuPrice;       // Nuskaito kainą
        inFile.ignore(); // praleidžia Enter simbolį po kainos, kad kitas getline veiktų teisingai
    }

    inFile.close(); // Uždarome failą
}

// Funkcija, kuri parodo meniu ir instrukcijas
void showMenu(menuItemType menuList[]) {
    cout << "~~~~RESTORANAS~~~~\n";
    cout << " PUSRYCIU MENIU \n";
    for (int i = 0; i < MENU_SIZE; i++) {
        // Formatuojame išvestį, kad atrodytų tvarkingai
        cout << left << setw(2) << i + 1 << ". "
             << setw(40) << menuList[i].menuItem
             << fixed << setprecision(2) << menuList[i].menuPrice << " Eur" << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Iveskite patiekalo numeri, kuri norite uzsisakyti, tuomet iveskite porciju kieki.\n";
    cout << "Noredami baigti uzsakyma, iveskite 0.\n";
}

// Funkcija, kuri suskaičiuoja sumas ir sukuria čeki
void printCheck(menuItemType menuList[], int orderQuantities[]) {
    double totalWithoutTax = 0;
    double taxRate = 0.21; // 21 proc. PVM
    double taxAmount = 0;
    double finalTotal = 0;
    bool hasItems = false; // patikrinina ar varotojas kažką užsisakė

    ofstream outFile("receipt.txt"); // Atidarom failą rašymui

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Jusu saskaita :\n\n";
    outFile << "Jusu saskaita :\n\n";

    // Einame per visą užsakymų masyvą
    for (int i = 0; i < MENU_SIZE; i++) {
        if (orderQuantities[i] > 0) {
            hasItems = true;
            double itemTotal = menuList[i].menuPrice * orderQuantities[i]; // Kaina * Kiekis
            totalWithoutTax += itemTotal; // pridedma į bendrą sumą

            // Išvedame į ekraną
            cout << left << setw(2) << orderQuantities[i] << " "
                 << setw(40) << menuList[i].menuItem
                 << fixed << setprecision(2) << itemTotal << " Eur" << endl;

            // Išvedame į failą
            outFile << left << setw(2) << orderQuantities[i] << " "
                    << setw(40) << menuList[i].menuItem
                    << fixed << setprecision(2) << itemTotal << " Eur" << endl;
        }
    }

    if (!hasItems) {
        cout << "Jus nieko neuzsisakete." << endl;
        outFile << "Jus nieko neuzsisakete." << endl;
        outFile.close();
        return;
    }

    // Mokesčių suskaičiavimas
    taxAmount = totalWithoutTax * taxRate;
    finalTotal = totalWithoutTax + taxAmount;

    // Spausdiname mokesčius ir galutinę sumą į ekraną
    cout << "\n" << left << setw(43) << "Mokesciai (21%)" << fixed << setprecision(2) << taxAmount << " Eur" << endl;
    cout << left << setw(43) << "Galutine suma" << fixed << setprecision(2) << finalTotal << " Eur" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // Spausdiname mokesčius ir galutinę sumą į failą
    outFile << "\n" << left << setw(43) << "Mokesciai (21%)" << fixed << setprecision(2) << taxAmount << " Eur" << endl;
    outFile << left << setw(43) << "Galutine suma" << fixed << setprecision(2) << finalTotal << " Eur" << endl;

    outFile.close();
    cout << "Saskaita sekmingai issaugota faile receipt.txt\n";
}
