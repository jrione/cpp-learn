#include <iostream>
#include <iomanip>

using namespace std;

//global vars
bool setFail;
string unit[] = { "C","R","F","K" };

float convert(int nominal,string fromScale, string toScale) {
    float hasil = 0.69;
    float pengkali = 1.0;
    if (fromScale == toScale) {
        hasil = nominal;
    }
    else if (fromScale == "C") {
        toScale == "R" ? hasil = pengkali*nominal * 4 / 5 : hasil;
        toScale == "F" ? hasil = (pengkali*nominal * 9/5) + 32: hasil;
        toScale == "K" ? hasil = pengkali*nominal+273 : hasil;
    }
    else if (fromScale == "R") {
        toScale == "C" ? hasil = pengkali*nominal * 5 / 4 : hasil;
        toScale == "F" ? hasil = (pengkali*nominal * 9 / 4) + 32 : hasil;
        toScale == "K" ? hasil = pengkali*nominal * 5 / 4 + 273 : hasil;
    }
    else if (fromScale == "F") {
        toScale == "C" ? hasil = (nominal * 5 / 9) - 32 : hasil;
        toScale == "R" ? hasil = (nominal * 4 / 9) - 32 : hasil;
        toScale == "K" ? hasil = (nominal * 5 / 9) + 459.4 : hasil;
    }
    else if (fromScale == "K") {
        toScale == "C" ? hasil = pengkali*nominal + 273 : hasil;
        toScale == "R" ? hasil = (pengkali*nominal * 4 / 5) - 273 : hasil;
        toScale == "F" ? hasil = (pengkali*nominal * 9 / 5) - 459.4 : hasil;
    }
    else {
        hasil = 0;
    }

    return hasil;
    
}



 void menu() {
    string allScale[2];
    int nominalSuhu;

    cout << "KONVERSI SUHU" << endl;
    cout << "INGFO: ketik C untuk Celcius, R untuk Reamur, F untuk Fahrenheit, K untuk Kelvin" << endl;
    cout << "Isi nominal suhu: "; 
    cin >> nominalSuhu;

    if (cin.fail()){
        cout << "Masukkan input berupa angka!"<<endl;
        setFail = true;
    }
    else {
        cout << "Pilih skala suhu yang dikonversi: "; cin >> allScale[0];
        cout << "Pilih skala suhu target konversi: "; cin >> allScale[1];

        bool exist[2];
        for (int i = 0; i < sizeof(allScale) / sizeof(allScale[0]); i++) {
            for (char chara : allScale[i]) allScale[i] = toupper(chara);
            exist[i] = find(begin(unit), end(unit), allScale[i]) != end(unit);
        }
        if (exist[0] == true && exist[1] == true) {
            float sum = convert(nominalSuhu, allScale[0], allScale[1]);
            cout << "============================================" << endl;
            cout << "Konversi suhu " << allScale[0] << " ke " << allScale[1] << " = "<< sum << endl;
            setFail = false;
        }
        else {
            cout << "Masukkan input sesuai INGFO!";
            setFail = true;
        }

    }
   
}

int main() {
    char again;

    mainMenu:
        menu();
        if (setFail == true) {
            goto exit;
        }
        else {
            goto isAgain;
        }

    isAgain:
        cout << "============================================" << endl;
        cout << "Ulangi? (y/n): "; cin >> again;
        if (again == 'y' || again == 'Y') {
            system("CLS");
            goto mainMenu;
        }
        else {
            goto exit;
        }
    exit:
        cout << "============================================" << endl;
        cout << "Terima kasih :)" << endl;
        return 0;
}