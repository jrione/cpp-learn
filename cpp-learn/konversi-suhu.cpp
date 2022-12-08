#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cstring>

using namespace std;

//global vars
bool setFail;
string unit[] = { "C","R","F","K" };

string implode(vector<string> strings, string delim) {
    stringstream ss;
    copy(strings.begin(), strings.end(),
        ostream_iterator<string>(ss, delim.c_str()));
    return ss.str();
}


void convert(int nominal,string fromScale, string toScale) {
    string FromTo = implode({ fromScale, toScale}, "_");
    string ToFrom = implode({ toScale, fromScale }, "_");
    map<string, map<string, int> > rumus;


    for (int j = 0; j < sizeof(unit)/sizeof(unit[0]); j++) { //baris CRFK
        rumus[unit[j]];
        for (int k = 0; k < sizeof(unit) / sizeof(unit[0]); k++) { //kolom cc,cr,cf,ck,dsb
            if (fromScale == toScale) {
                rumus[fromScale][FromTo] = nominal;
            }
            else {
                rumus[unit[j]][implode({ unit[j], unit[k]}, "_")];
            }
        }
        for (auto a : rumus[unit[j]]) {
            if (a.first == FromTo || a.first == ToFrom) {
                cout << a.first <<": "<<a.second<< endl;
            }
        }
    }

    

   /* for (int m = 0; m < sizeof(unit) / sizeof(unit[0]); m++) {
        for (auto l : rumus[unit[m]]) cout << '{' << l.first << ", " << l.second << "}\n";
    }
    */
    //string sumScale =  implode(FromTo, "_");
    //return rumus[sumScale];

    /*{"C_R_", nominal * 4 / 5},
    { "R_R_", nominal },
    { "F_R_", (nominal - 32) * 4 / 9 },
    { "K_R_", (nominal - 273) * 4 / 5 }*/
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

    }
    convert(nominalSuhu, allScale[0], allScale[1]);


       /* if (exist[0] == true && exist[1] == true) {
            float sum;
            sum = convert(nominalSuhu, allScale[0], allScale[1]);
            cout << "============================================" << endl;
            cout << "Konversi suhu " << allScale[0] << " ke " << allScale[1] << " = " << sum << endl;
            setFail = false;
        }
        else {
            cout << "Masukkan input sesuai INGFO!";
            setFail = true;
        }*/
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