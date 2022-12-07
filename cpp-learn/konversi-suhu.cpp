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

string implode(vector<string> strings, string delim)
{
    stringstream ss;
    copy(strings.begin(), strings.end(),
        ostream_iterator<string>(ss, delim.c_str()));
    return ss.str();
}

float convert(int nominal,string fromScale, string toScale) {
    vector<string> FromTo = { fromScale, toScale};
    map<string,float> rumus {
        {"C_R_", nominal*4/5},
        {"R_R_", nominal},
        {"F_R_", (nominal-32)*4/9},
        {"K_R_", (nominal-273)*(4/5)}
    };

    string sumScale =  implode(FromTo, "_");
    return rumus[sumScale];

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
        for (int i = 0; i < sizeof(allScale)/sizeof(allScale[0]); i++) {
            for (char chara: allScale[i]) allScale[i] = toupper(chara);
            exist[i] = find(begin(unit), end(unit), allScale[i]) != end(unit);
        }

        if (exist[0] == true && exist[1] == true) {
            float sum;
            sum = convert(nominalSuhu, allScale[0], allScale[1]);
            cout << "============================================" << endl;
            cout << "Konversi suhu " << allScale[0] << " ke " << allScale[1] << " = " << sum << endl;
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
        cout << "============================================" << endl;
        if (again == 'y' || again == 'Y') {
            goto mainMenu;
        }
        else {
            goto exit;
        }
    exit:
        cout << "Terima kasih :)" << endl;
        return 0;
}
