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

        // Mokinio pridėjimas
        if (pasirinkimas == 1) {
            if (mokiniuSkaicius < MAX_MOKINIU) {
                cout << "Iveskite varda: ";
                cin >> vardai[mokiniuSkaicius]; // vardas saugomas masyve
                
                int kiek;
                cout << "Kiek pazymiu (max " << MAX_PAZYMIU << ")? ";
                cin >> kiek;
                
                // Apsauga nuo netinkamo įvedimo
                if (kiek > MAX_PAZYMIU) kiek = MAX_PAZYMIU;
                if (kiek < 0) kiek = 0; 

                // Įvedamas kiekvienas pažymys su apsauga 
                for (int i = 0; i < kiek; i++) {
                    int laikinasPazymys;
                    do {
                        cout << "Pazymys nr. " << i + 1 << " (1-10): ";
                        cin >> laikinasPazymys;
                        if (laikinasPazymys < 1 || laikinasPazymys > 10) {
                            cout << "Klaida! Pazymys turi buti nuo 1 iki 10.\n";
                        }
                    } while (laikinasPazymys < 1 || laikinasPazymys > 10);
                    
                    // Tinkamas pažymys išsaugomas masyve
                    pazymiai[mokiniuSkaicius][i] = laikinasPazymys;
                }
                
                // Išsaugoma kiek pažymių gavo mokinys ir padidinamas mokinių skaičius
                pazymiuKiekis[mokiniuSkaicius] = kiek;
                mokiniuSkaicius++;
                cout << "Mokinys pridetas!\n";
            } else {
                cout << "Sarasas pilnas!\n";
            }
        }
        // Mokiniai ir jų pažymių rodymas
        else if (pasirinkimas == 2) { 
            if (mokiniuSkaicius == 0) cout << "Sarasas tuscias.\n";
            for (int i = 0; i < mokiniuSkaicius; i++) {
                cout << i + 1 << ". " << vardai[i] << " | Pazymiai: ";
                // Konkretaus mokinio pažymių atspausdinimas
                for (int j = 0; j < pazymiuKiekis[i]; j++) {
                    cout << pazymiai[i][j] << " ";
                }
                cout << endl;
            }
        }
        // Mokinio peržiūra pagal numerį
        else if (pasirinkimas == 3) { 
            int nr;
            cout << "Iveskite mokinio numeri: ";
            cin >> nr;
            int idx = nr - 1;
            // Patikrinima ar toks mokinys egzistuoja, jei taip atspausdinama jo info
            if (idx >= 0 && idx < mokiniuSkaicius) {
                cout << vardai[idx] << " pazymiai: ";
                if (pazymiuKiekis[idx] == 0) cout << "nėra.";
                for (int j = 0; j < pazymiuKiekis[idx]; j++) {
                    cout << pazymiai[idx][j] << " ";
                }
                cout << endl;
            } else {
                cout << "Klaida: Tokio mokinio nera.\n";
            }
        }
        // Pažymio keitimas
        else if (pasirinkimas == 4) { 
            int mNr, pNr;
            cout << "Kurio mokinio pazymi keisti? ";
            cin >> mNr;
            int mIdx = mNr - 1; 
            
            // Jei mokinys yra sąraše
            if (mIdx >= 0 && mIdx < mokiniuSkaicius) {
                if (pazymiuKiekis[mIdx] == 0) {
                    cout << "Mokinys neturi pazymiu.\n";
                } else {
                    cout << "Kuri pazymi keisti (1-" << pazymiuKiekis[mIdx] << ")? ";
                    cin >> pNr;
                    int pIdx = pNr - 1;
                    
                    // Jei pasirinko teisingą pažymio numerį
                    if (pIdx >= 0 && pIdx < pazymiuKiekis[mIdx]) {
                        int naujasPazymys;
                        do {
                            cout << "Iveskite nauja pazymi (1-10): ";
                            cin >> naujasPazymys;
                            if (naujasPazymys < 1 || naujasPazymys > 10) {
                                cout << "Klaida! Pazymys turi buti nuo 1 iki 10.\n";
                            }
                        } while (naujasPazymys < 1 || naujasPazymys > 10);
                        
                        pazymiai[mIdx][pIdx] = naujasPazymys;
                        cout << "Atnaujinta!\n";
                    } else {
                        cout << "Klaida: Neteisingas pazymio numeris.\n";
                    }
                }
            } else {
                cout << "Klaida: Tokio mokinio nera.\n";
            }
        }
        // Mokinio trinimas
        else if (pasirinkimas == 5) { 
            int nr;
            cout << "Iveskite mokinio numeri istrinimui: ";
            cin >> nr;
            int idx = nr - 1;
            
            // Jei mokinys yra
            if (idx >= 0 && idx < mokiniuSkaicius) {
                for (int i = idx; i < mokiniuSkaicius - 1; i++) {
                    vardai[i] = vardai[i+1]; 
                    pazymiuKiekis[i] = pazymiuKiekis[i+1]; 
                    // Perkeliu ir visus jo pažymius iš 2d masyvo
                    for (int j = 0; j < MAX_PAZYMIU; j++) {
                        pazymiai[i][j] = pazymiai[i+1][j];
                    }
                }
                // Kai mokiniai perstumti - sumažiname mokinių skaičiu
                mokiniuSkaicius--;
                cout << "Mokinys istrintas.\n";
            } else {
                cout << "Klaida: Tokio mokinio nera.\n";
            }
        }
        else if (pasirinkimas != 0) {
            cout << "Neatpazintas veiksmas. Bandykite dar karta.\n";
        }
    } while (pasirinkimas != 0); // Jei 0, ciklas baigiasi ir programa užsidaro

    return 0;
}
