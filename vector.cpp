#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using std::cin;
using std::string;
using std::cout;


//darbas atliktas su vector konteineriu

struct studentas
{
   string vardas, pavarde;
   std::vector<int> pazymiai;
   double rez; //rezultatui su vidurkiu saugoti
   double rez2; //rezultatui su mediana saugoti
};

bool DidPav(studentas &A, studentas &B)
{
    return A.pavarde<B.pavarde;
}

bool DidVar(studentas &A, studentas &B)
{
    return A.vardas<B.vardas;
}

bool DidVid(studentas &A, studentas &B)
{
    return A.rez<B.rez;
}

bool DidMed(studentas &A, studentas &B)
{
    return A.rez2<B.rez2;
}

int main() {
   std::string CVfd;

cout << "Pasirinkite faila:\n";
cout << "1 - studentai10000.txt\n";
cout << "2 - studentai100000.txt\n";
cout << "3 - studentai1000000.txt\n";

int pasirinkimas;
cin>>pasirinkimas;
if (pasirinkimas==1)
    CVfd = "studentai.txt";
else if (pasirinkimas == 2)
    CVfd = "studentai100000.txt";
else if (pasirinkimas == 3)
    CVfd = "studentai1000000.txt";

    std::string CVfr="rezultatas.txt";
    std::ifstream fd(CVfd);
    std::vector<studentas> studentai;
    srand(time(nullptr)); //kad kiekviena karta butu generuojami skirtingi pazymiai
    string pavardes[] = { "Kazlauskas", "Petrauskas", "Jankauskas", "Vaitkus",
        "Kazlauskaite", "Petrauskaite", "Jankauskaite", "Vaitkute" };
    int pavN = sizeof(pavardes) / sizeof(pavardes[0]);

    string vardai[] = { "Jonas", "Petras", "Mantas", "Lukas", "Tomas",
        "Ieva", "Aiste", "Monika", "Greta", "Laura" };
    int vardN = sizeof(vardai) / sizeof(vardai[0]);

    //meniu
    int m = 0;
    while (m != 4) {
        cout << "Pasirinkite, kokiu budu norite, kad programa vykdytu uzduoti (1 - duomenu irasymas ranka, 2 - generuoti tik pazymius, 3 - generuoti studentu vardus, pavardes ir pazymius, 4 - nuskaityti duomenis is failo,  5 - baigti darba): " << std::endl;
        cin >> m;

    if (m == 1)
    {
    while (true) {
        studentas s;
        cout << "Iveskite studento varda (0 - baigti): ";
        cin >> s.vardas;

        if (s.vardas == "0")
            break;

        cout << "Iveskite pavarde: ";
        cin >> s.pavarde;
        cout << "Iveskite pazymius (0 - baigti), paskutinis egzaminas (min 2): ";
        int p; //pazymiams
        while(true)
        {
          cin>>p;
          if (p == 0) break;
          s.pazymiai.push_back(p);
        }
       studentai.push_back(s);
    }

    double suma; //rezultatui skaiciuoti
    for(int i=0; i<studentai.size(); i++)
    {
        suma=0;
        for(int j=0; j<studentai[i].pazymiai.size(); j++)
        {
            if (j != studentai[i].pazymiai.size() - 1) suma+=studentai[i].pazymiai[j]; //sumuojame, tik jei j nera egzamino pazymio numeris
        }
        studentai[i].rez=suma/(studentai[i].pazymiai.size()-1)*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    //rusiuojame medianai
    for(int i=0; i<studentai.size(); i++) //rikiuojame tik ND, be paskutinio egzamino
    {
        if(studentai[i].pazymiai.size() > 1) {
            std::sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end() - 1);
        }
    }
    //skaiciuojame mediana ir bendra bala
        for(int i=0; i<studentai.size(); i++)
    {
        int k = studentai[i].pazymiai.size();
        int nd = k - 1;

        double med;
        if (nd % 2 == 1) med = studentai[i].pazymiai[nd / 2];
        else med = (studentai[i].pazymiai[nd / 2 - 1] + studentai[i].pazymiai[nd / 2]) / 2.0;
        studentai[i].rez2=med*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    int a;
    cout << "Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):" << std::endl;
            cin >> a;
            if (a == 0)
            {
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<< std::fixed << std::setprecision(2) << studentai[i].rez << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            else {
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<<std::fixed << std::setprecision(2) << studentai[i].rez2 << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            studentai.clear();
        }
        if(m==2)
        {
          while (true) {
        studentas s;
        cout << "Iveskite studento varda (0 - baigti): ";
        cin >> s.vardas;

        if (s.vardas == "0")
            break;

        cout << "Iveskite pavarde: ";
        cin >> s.pavarde;
        cout << "Pazymiai bus generuojami automatiskai, iveskite pazymiu kieki (min 2): ";
        int kiek=0; //pazymiu kiekis
        int p; //pazymiams
        cin>>kiek;
        s.pazymiai.clear();
        s.pazymiai.resize(kiek);
        for(int i = 0; i < kiek; i++)
        {
            s.pazymiai[i] = rand() % 10 + 1;
        }
        studentai.push_back(s);
    }

    double suma; //rezultatui skaiciuoti
    for(int i=0; i<studentai.size(); i++)
    {
        suma=0;
        for(int j=0; j<studentai[i].pazymiai.size(); j++)
        {
            if (j != studentai[i].pazymiai.size() - 1) suma+=studentai[i].pazymiai[j]; //sumuojame, tik jei j nera egzamino pazymio numeris
        }
        studentai[i].rez=suma/(studentai[i].pazymiai.size()-1)*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    //rusiuojame medianai
    for(int i=0; i<studentai.size(); i++) //rikiuojame tik ND, be paskutinio egzamino
    {
        if(studentai[i].pazymiai.size() > 1) {
            std::sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end() - 1);
        }
    }
    //skaiciuojame mediana ir bendra bala
        for(int i=0; i<studentai.size(); i++)
    {
        int k = studentai[i].pazymiai.size();
        int nd = k - 1;

        double med;
        if (nd % 2 == 1) med = studentai[i].pazymiai[nd / 2];
        else med = (studentai[i].pazymiai[nd / 2 - 1] + studentai[i].pazymiai[nd / 2]) / 2.0;
        studentai[i].rez2=med*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    int a;
    cout << "Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):" << std::endl;
            cin >> a;
            if (a == 0)
            {
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<< std::fixed << std::setprecision(2) << studentai[i].rez << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            else {
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<<std::fixed << std::setprecision(2) << studentai[i].rez2 << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            studentai.clear();
        } 
        if(m==3)
        {
        studentas s;
        int skiek; //studentu kiekis
        cout << "Sudentu vardai ir pavardes bus generuojami automatiskai, iveskite studentu kieki: ";
        cin >> skiek;
        cout << "Pazymiai bus generuojami automatiskai, iveskite pazymiu kieki (min 2): ";
        int kiek; //pazymiu kiekis
        cin>>kiek;
        for(int i=0; i<skiek; i++)
        {
             s.vardas = vardai[rand() % vardN];
                if (s.vardas.back() == 's') {
                    do { s.pavarde = pavardes[rand() % pavN]; } while (s.pavarde.back() != 's');
                } else {
                    do { s.pavarde = pavardes[rand() % pavN]; } while (s.pavarde.back() == 's');
                }
        int p; //pazymiams
        s.pazymiai.clear();
        s.pazymiai.resize(kiek);
        for(int i = 0; i < kiek; i++)
        {
            s.pazymiai[i] = rand() % 10 + 1;
        }
        studentai.push_back(s);
        }
    double suma; //rezultatui skaiciuoti
    for(int i=0; i<studentai.size(); i++)
    {
        suma=0;
        for(int j=0; j<studentai[i].pazymiai.size(); j++)
        {
            if (j != studentai[i].pazymiai.size() - 1) suma+=studentai[i].pazymiai[j]; //sumuojame, tik jei j nera egzamino pazymio numeris
        }
        studentai[i].rez=suma/(studentai[i].pazymiai.size()-1)*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    //rusiuojame medianai
    for(int i=0; i<studentai.size(); i++) //rikiuojame tik ND, be paskutinio egzamino
    {
        if(studentai[i].pazymiai.size() > 1) {
            std::sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end() - 1);
        }
    }
    //skaiciuojame mediana ir bendra bala
        for(int i=0; i<studentai.size(); i++)
    {
        int k = studentai[i].pazymiai.size();
        int nd = k - 1;

        double med;
        if (nd % 2 == 1) med = studentai[i].pazymiai[nd / 2];
        else med = (studentai[i].pazymiai[nd / 2 - 1] + studentai[i].pazymiai[nd / 2]) / 2.0;
        studentai[i].rez2=med*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    int a;
    cout << "Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):" << std::endl;
            cin >> a;
            if (a == 0)
            {
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<< std::fixed << std::setprecision(2) << studentai[i].rez << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            else {
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<<std::fixed << std::setprecision(2) << studentai[i].rez2 << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            studentai.clear();
        }
        if (m == 5) cout << "Baigiamas darbas.\n";
        if(m==4)
        {
            studentai.clear();
            std::string eilute;
            std::getline(fd, eilute); //praleidžia pirma eilute
        while (std::getline(fd, eilute))
       {
        std::stringstream st(eilute);
        studentas s;
        int p; //pazymiai + egzaminas (paskutinis)
        st>>s.vardas>>s.pavarde;
        s.pazymiai.clear();

           while(st>>p)
           {
                  s.pazymiai.push_back(p);
           }

          studentai.push_back(s);
         }
         double suma; //rezultatui skaiciuoti
    for(int i=0; i<studentai.size(); i++)
    {
        suma=0;
        for(int j=0; j<studentai[i].pazymiai.size(); j++)
        {
            if (j != studentai[i].pazymiai.size() - 1) suma+=studentai[i].pazymiai[j]; //sumuojame, tik jei j nera egzamino pazymio numeris
        }
        studentai[i].rez=suma/(studentai[i].pazymiai.size()-1)*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    //rusiuojame medianai
    for(int i=0; i<studentai.size(); i++) //rikiuojame tik ND, be paskutinio egzamino
    {
        if(studentai[i].pazymiai.size() > 1) {
            std::sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end() - 1);
        }
    }
    //skaiciuojame mediana ir bendra bala
        for(int i=0; i<studentai.size(); i++)
    {
        int k = studentai[i].pazymiai.size();
        int nd = k - 1;

        double med;
        if (nd % 2 == 1) med = studentai[i].pazymiai[nd / 2];
        else med = (studentai[i].pazymiai[nd / 2 - 1] + studentai[i].pazymiai[nd / 2]) / 2.0;
        studentai[i].rez2=med*0.4+studentai[i].pazymiai.back()*0.6;
    }
    
    int a;
    int spausd;
    int rus; //rusiavimui
            cout<<"Pasirinkite, kur norite, kad butu spausdinami duomenys (0 - faile, 1 - ekrane): "<<std::endl;
            cin>>spausd;
            if(spausd==1){
    cout << "Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):" << std::endl;
            cin >> a;
            if (a == 0)
            {
                cout<<"Pasirinkite, pagal ka norite, jog butu suriuosatas studentu sarasas: 0 - vardas, 1 - pavarde, 2 - galutinis rez. (vid.)\n";
                cin>>rus;
                if(rus==0) sort(studentai.begin(), studentai.end(), DidVar);
                if(rus==1) sort(studentai.begin(), studentai.end(), DidPav);
                if(rus==2) sort(studentai.begin(), studentai.end(), DidVid);
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<< std::fixed << std::setprecision(2) << studentai[i].rez << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            else {
                cout<<"Pasirinkite, pagal ka norite, jog butu suriuosatas studentu sarasas: 0 - vardas, 1 - pavarde, 2 - galutinis rez. (med.)\n";
                cin>>rus;
                if(rus==0) sort(studentai.begin(), studentai.end(), DidVar);
                if(rus==1) sort(studentai.begin(), studentai.end(), DidPav);
                if(rus==2) sort(studentai.begin(), studentai.end(), DidMed);
                cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    cout << std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<<std::fixed << std::setprecision(2) << studentai[i].rez2 << "\n";
                }
                cout << "-----------------------------------------------\n";
            }
            studentai.clear();
        }
            if(spausd==0){
            std::ofstream fr(CVfr); 
            cout << "Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):" << std::endl;
            cin>>a;
            if (a == 0)
            {
                cout<<"Pasirinkite, pagal ka norite, jog butu suriuosatas studentu sarasas: 0 - vardas, 1 - pavarde, 2 - galutinis rez. (vid.)\n";
                cin>>rus;
                if(rus==0) sort(studentai.begin(), studentai.end(), DidVar);
                if(rus==1) sort(studentai.begin(), studentai.end(), DidPav);
                if(rus==2) sort(studentai.begin(), studentai.end(), DidVid);
                fr<< std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
                fr<< "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    fr<< std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<< std::fixed << std::setprecision(2) << studentai[i].rez << "\n";
                }
                fr<< "-----------------------------------------------\n";
            }
            else {
                cout<<"Pasirinkite, pagal ka norite, jog butu suriuosatas studentu sarasas: 0 - vardas, 1 - pavarde, 2 - galutinis rez. (vid.)\n";
                cin>>rus;
                if(rus==0) sort(studentai.begin(), studentai.end(), DidVar);
                if(rus==1) sort(studentai.begin(), studentai.end(), DidPav);
                if(rus==2) sort(studentai.begin(), studentai.end(), DidVid);
                fr<< std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
                fr<< "-----------------------------------------------\n";
                for (int i = 0; i < studentai.size(); i++) {
                    fr<< std::left << std::setw(15) << studentai[i].pavarde << std::left << std::setw(15) << studentai[i].vardas<<std::fixed << std::setprecision(2) << studentai[i].rez2 << "\n";
                }
                fr<< "-----------------------------------------------\n";
            }
            studentai.clear();
            fr.close();
        }
        }
    } 

    return 0;
}


