#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Valiutu kursai
    double GBP_Bendras = 0.8729;
    double GBP_Pirkti = 0.8600;
    double GBP_Parduoti = 0.9220;

    double USD_Bendras = 1.1793;
    double USD_Pirkti = 1.1460;
    double USD_Parduoti = 1.2340;

    double INR_Bendras = 104.6918;
    double INR_Pirkti = 101.3862;
    double INR_Parduoti = 107.8546;

    int veiksmas;
    int valiuta;
    double suma;

    while (true) {
        cout << "*****************************************\n";
        cout << "       VALIUTOS KEITYKLA (EUR)        \n";
        cout << "*****************************************\n";
        cout << "1 - Palyginti kursa\n";
        cout << "2 - Pirkti valiuta (uz EUR)\n";
        cout << "3 - Parduoti valiuta (gausite EUR)\n";
        cout << "0 - Baigti darba\n";
        cout << "Jusu pasirinkimas: ";
        cin >> veiksmas;

        if (veiksmas == 0) {
            cout << "Programa baigta.\n";
            break;
        }

        if (veiksmas < 0 || veiksmas > 3) {
            cout << "Klaida: tokio veiksmo nera!\n";
            continue;
        }

        cout << "\nPasirinkite valiuta:\n";
        cout << "1 - EUR (Euras)\n";
        cout << "2 - GBP (Didziosios Britanijos svaras)\n";
        cout << "3 - USD (JAV doleris)\n";
        cout << "4 - INR (Indijos rupija)\n";
        cout << "Jusu pasirinkimas: ";
        cin >> valiuta;

        if (valiuta < 1 || valiuta > 4) {
            cout << "Klaida: tokios valiutos nera\n";
            continue;
        }

        cout << "Iveskite valiutos kieki: ";
        cin >> suma;

        cout << "\n--- REZULTATAS ---\n";
        // Palyginimas
        if (veiksmas == 1) { 
            if (valiuta == 1) cout << suma << " EUR atitinka " << suma * 1.0 << " EUR\n";
            else if (valiuta == 2) cout << suma << " EUR atitinka " << suma * GBP_Bendras << " GBP\n";
            else if (valiuta == 3) cout << suma << " EUR atitinka " << suma * USD_Bendras << " USD\n";
            else if (valiuta == 4) cout << suma << " EUR atitinka " << suma * INR_Bendras << " INR\n";
        }
        // Pirkimas
        else if (veiksmas == 2) { 
            if (valiuta == 1) cout << "Uz " << suma << " EUR gausite " << suma * 1.0 << " EUR\n";
            else if (valiuta == 2) cout << "Uz " << suma << " EUR gausite " << suma * GBP_Pirkti << " GBP\n";
            else if (valiuta == 3) cout << "Uz " << suma << " EUR gausite " << suma * USD_Pirkti << " USD\n";
            else if (valiuta == 4) cout << "Uz " << suma << " EUR gausite " << suma * INR_Pirkti << " INR\n";
        }
        // Pardavimas
        else if (veiksmas == 3) { 
            if (valiuta == 1) cout << "Pardave " << suma << " EUR gausite " << suma * 1.0 << " EUR\n";
            else if (valiuta == 2) cout << "Pardave " << suma << " GBP gausite " << suma * GBP_Parduoti << " EUR\n";
            else if (valiuta == 3) cout << "Pardave " << suma << " USD gausite " << suma * USD_Parduoti << " EUR\n";
            else if (valiuta == 4) cout << "Pardave " << suma << " INR gausite " << suma * INR_Parduoti << " EUR\n";
        }

    }
    return 0;
}
