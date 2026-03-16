#include "pasirinkimai.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>

#include "rusiavimas.h"
#include "studentas.h"

using namespace std;
using namespace std::chrono;

void Skaiciavimai(std::vector<studentas>& studentai, int b)
{
    double suma; //rezultatui skaiciuoti
    if(b==0){
    for(int i=0; i<studentai.size(); i++)
    {
        suma=0;
        for(int j=0; j<studentai[i].pazymiai.size(); j++)
        {
            if (j != studentai[i].pazymiai.size() - 1) suma+=studentai[i].pazymiai[j]; //sumuojame, tik jei j nera egzamino pazymio numeris
        }
        studentai[i].rez=suma/(studentai[i].pazymiai.size()-1)*0.4+studentai[i].pazymiai.back()*0.6;
    }
    }
    else {
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
}
}
void Spausdinimas(std::vector<studentas>& studentai, int& b)
{
    b=kinta();
            if (b == 0)
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
}
void VardasPavarde(std::vector<studentas>& studentai, studentas& s)
{
    while (true) {
    try {
        cout << "Iveskite studento varda (0 - baigti): ";
        cin >> s.vardas;

        if (s.vardas == "0")
            return;

        for (char c : s.vardas) { //Tikriname ar visi simboliai yra raides
            if (!isalpha(c)) {
                throw std::invalid_argument("Varda gali sudaryti tik raides.");
            }
        }
        break;
    }
    catch (const std::exception& e) {
        cout << "Klaida: " << e.what() <<" Bandykite dar karta:\n"<< endl;
    }
}
while (true) {
    try {   
        cout << "Iveskite pavarde: ";
        cin >> s.pavarde;

        for (char c : s.pavarde) { //Tikriname ar visi simboliai yra raides
            if (!isalpha(c)) {
                throw std::invalid_argument("Pavarde gali sudaryti tik raides.");
            }
        }
        break;
    }
    catch (const std::exception& e) {
        cout << "Klaida: " << e.what() << " Bandykite dar karta:\n"<<endl;
    }
}
}
void RandPaz(std::vector<studentas>& studentai, studentas& s, int& kiek)
{

    if(kiek==0){
    cout << "Pazymiai bus generuojami automatiskai, iveskite pazymiu kieki (min 2): ";
    while (true) {
    cin >> kiek;

    if (cin.fail()) {
        cout << "Iveskite skaiciu!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
    }

    if (kiek < 2) {
        cout << "Pazymiu kiekis turi buti ne mazesnis nei 2, bandykite dar karta:\n";
        continue;
    }

    break;
}
    }
        s.pazymiai.clear();
        s.pazymiai.resize(kiek);
        for(int i = 0; i < kiek; i++)
        {
            s.pazymiai[i] = rand() % 10 + 1;
        }
        studentai.push_back(s);
}

int kinta()
{
    int a;
    while (true) {   
            cout << "Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):" << std::endl;
            cin>>a; 
            if (cin.fail()) 
            { 
                cout << "Iveskite skaiciu: \n"; 
                cin.clear(); 
                cin.ignore(10000, '\n'); //pasirenkamas didelis sk, kad ivedimo reiksme tikrai butu isvalyta
                continue; 

            }
            if (a!=0&&a!=1) { 
                cout << "Skaicius turi buti 1 arba 0: \n"; 
                continue; }

                break;
            }
    return a;
}

int kintrus(int& rus)
{
    int x;
    while (true) { 
            cout<<"Pasirinkite, pagal ka norite, jog butu suriuosatas studentu sarasas: 0 - vardas, 1 - pavarde, 2 - galutinis rez. (vid. arba med.)"<<std::endl;
            cin>>x; 
            if (cin.fail()) 
            { 
                cout << "Iveskite skaiciu: \n"; 
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                continue; 
            }
            if (x!=0&&x!=1&&x!=2) { 
                cout << "Skaicius turi buti 2, 1 arba 0: \n"; 
                continue;
            }

            break;
        }
        return rus=x;
}

int kintr(int& r)
{
    int x;
  while (true) { 
    cout<<"Ar norite, jog jusu pasirinkimas butu surusiuotas didejanciai (0) ar mazejanciai (1)?"<<std::endl;
    cin>>x; 
    if (cin.fail()) 
    { 
        cout << "Iveskite skaiciu: \n"; 
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        continue; 
    }
        if (x!=0&&x!=1) { 
        cout << "Skaicius turi buti 1 arba 0: \n"; 
        continue; }
                        
        break;
    }
    return r=x;
}

void PirmasP(std::vector<studentas>& studentai, int& b) //jei pasirinkimas 1
{
while (true) {
studentas s;
bool buvonulis = false;
VardasPavarde(studentai, s);
if (s.vardas == "0") break;
int p;
cout << "Iveskite pazymius (0 - baigti), paskutinis egzaminas (min 2): ";
while (true)
{
    cin >> p;

    if (cin.fail()) {
        cout << "Iveskite skaiciu: \n";
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
    }

    if (p == 0) {
        buvonulis=true;
        if (s.pazymiai.size() < 2) {
            cout << "Reikia ivesti bent 2 pazymius (paskutinis - egzaminas), veskite dar karta: \n";
            continue;
        }
        break;
    }

    if (p < 1 || p > 10) {
        cout << "Pazymys turi buti tarp 1 ir 10, veskite dar karta: \n";
        cin.ignore(10000, '\n'); //kad jei visi skaiciai daugiau uz 10, klaida rasyti viena
        continue;
    }
    s.pazymiai.push_back(p);
    if (!buvonulis) 
    {
        cout << "Ivedimas turi buti uzbaigtas 0.\n";
        buvonulis=true; //kad nekartotu pranesimo
    }
}
       studentai.push_back(s);
    }
    Skaiciavimai(studentai, b);
    Spausdinimas(studentai, b);
    studentai.clear();
}

void AntrasP(std::vector<studentas>& studentai, int& b) //jei pasirinkimas 2
{
    int kiek=0;
    while (true) {
        studentas s;
        VardasPavarde(studentai, s);
        if (s.vardas == "0") break;
        RandPaz(studentai, s, kiek);
    }
    Skaiciavimai(studentai, b);
    Spausdinimas(studentai, b);
    studentai.clear();
}

void TreciasP(std::vector<studentas>& studentai, const std::vector<std::string>& pavardes,  const std::vector<std::string>& vardai, int& b) //jei pasirinkitas 3
{
    studentas s;
        int skiek; //studentu kiekis
        int kiek=0; //pazymiams
        int vardN = vardai.size();
        int pavN = pavardes.size();
        cout << "Sudentu vardai ir pavardes bus generuojami automatiskai, iveskite studentu kieki: ";
        while (true) {
       cin >> skiek;

    if (cin.fail()) {
        cout << "Iveskite skaiciu!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
    }

    break;
}
        for(int i=0; i<skiek; i++)
        {
            s.vardas = vardai[rand() % vardN];
                if (s.vardas.back() == 's') {
                    do { s.pavarde = pavardes[rand() % pavN]; } while (s.pavarde.back() != 's');
                } else {
                    do { s.pavarde = pavardes[rand() % pavN]; } while (s.pavarde.back() == 's');
                }
            RandPaz(studentai, s, kiek);
        }
        Skaiciavimai(studentai, b);
        Spausdinimas(studentai, b);
        studentai.clear();
}

void KetvirtasP(std::vector<studentas>& studentai, const std::string& CVfd, const std::string& CVfr, double& suma2, double& suma3, double& suma4, double& suma5, double& suma6, int& spausd, bool& skaitytaIsFailo, int &b) //jei pasirinkitas 4
{
    skaitytaIsFailo=true;
    try {
        std::ifstream fd(CVfd);
        if (!fd.is_open()) {
            throw std::runtime_error("Nepavyko atidaryti failo. ");
        }

        studentai.clear();
        std::string eilute;

        auto start2 = high_resolution_clock::now();
        std::getline(fd, eilute);

        while (std::getline(fd, eilute)) {
            std::stringstream st(eilute);
            studentas s;
            int p;
            st >> s.vardas >> s.pavarde;
            s.pazymiai.clear();
            while (st >> p) s.pazymiai.push_back(p);
            studentai.push_back(s);
        }

        auto end2 = high_resolution_clock::now();
        suma2 = duration<double>(end2 - start2).count();
    }
    catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << "\n";
        return; 
    }
    Skaiciavimai(studentai, b);
    int r; //kintamasis rusiavimui (mazejanciai arba didejanciai)
    int rus; //rusiavimo tipui pasirinkti (vardas, pavarde ir t.t)
            while (true) { 
            cout<<"Pasirinkite, kur norite, kad butu spausdinami duomenys (0 - faile, 1 - ekrane): "<<std::endl;
            cin>>spausd; 
            if (cin.fail()) 
            { 
                cout << "Iveskite skaiciu: \n"; 
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                continue; 
            }
            if (spausd!=0&&spausd!=1) { 
                cout << "Skaicius turi buti 1 arba 0: \n"; 
                continue; }

            break;
        }

    b = kinta();
    rus = kintrus(rus);
    r = kintr(r);

    if (spausd == 1)
    {
        auto start3 = high_resolution_clock::now();
        RusiuotiStudentus(studentai, b, r, rus);
        auto end3 = high_resolution_clock::now();
        suma3 = duration<double>(end3 - start3).count();

        auto start5 = high_resolution_clock::now();
        //spausdinimas i ekrana
        if (b == 0)
        {
            cout << std::left << std::setw(15) << "Pavarde"<< std::left << std::setw(15) << "Vardas"<< std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < studentai.size(); i++) {
                cout << std::left << std::setw(15) << studentai[i].pavarde<< std::left << std::setw(15) << studentai[i].vardas<< std::fixed << std::setprecision(2) << studentai[i].rez << "\n";
            }
            cout << "-----------------------------------------------\n";
        }
        else
        {
            cout << std::left << std::setw(15) << "Pavarde"<< std::left << std::setw(15) << "Vardas"<< std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < studentai.size(); i++) {
                cout << std::left << std::setw(15) << studentai[i].pavarde<< std::left << std::setw(15) << studentai[i].vardas<< std::fixed << std::setprecision(2) << studentai[i].rez2 << "\n";
            }
            cout << "-----------------------------------------------\n";
        }
        auto end5 = high_resolution_clock::now();
        suma5 = duration<double>(end5 - start5).count();
    }
    else
    {
        auto start4 = high_resolution_clock::now();
        RusiuotiStudentus(studentai, b, r, rus);
        auto end4 = high_resolution_clock::now();
        suma4 = duration<double>(end4 - start4).count();

        auto start6 = high_resolution_clock::now();
        SpausdintiIFaila(CVfr, studentai, b);
        auto end6 = high_resolution_clock::now();
        suma6 = duration<double>(end6 - start6).count();
    }

    studentai.clear();
}

void GeneruotiStudentuFaila(const std::string& failoPav, int studentuKiekis, int ndKiekis)
{
    std::ofstream fr(failoPav);
    if (!fr.is_open()) {
        throw std::runtime_error("Nepavyko sukurti failo");
    }

    //spausdiname antraste
    fr << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";

    for (int i = 1; i <= ndKiekis; i++) {
        fr << std::left << std::setw(8) <<("ND" + std::to_string(i));
    }
    fr << std::left << std::setw(8) << "Egz." << "\n";

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> pazymys(1, 10);

    for (int i = 1; i <= studentuKiekis; i++) {
        fr << std::left << std::setw(20) <<("VardasNR" + std::to_string(i))<< std::left << std::setw(20) <<("PavardeNR" + std::to_string(i));
        for (int j = 0; j < ndKiekis; j++) {
            fr << std::left << std::setw(8) << pazymys(gen);
        }
        fr << std::left << std::setw(8) << pazymys(gen) << "\n";
    }

    fr.close();
}

void NuskaitytiIsFailo(std::vector<studentas>& studentai, const std::string& failoPav, int studentuKiekis)
{
    std::ifstream fd(failoPav);
    if (!fd.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo");
    }

    studentai.clear();
    studentai.reserve(studentuKiekis);

    std::string antraste;
    std::getline(fd, antraste);
    while (true) {
        studentas s;
        s.pazymiai.resize(6); //plius egzaminas
        if (!(fd >> s.vardas >> s.pavarde)) break;
        for (int i = 0; i < 6; i++) {
            fd >> s.pazymiai[i];
        }
        studentai.push_back(s);
    }
    fd.close();
}

void PadalintiStudentus(const std::vector<studentas>& studentai, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakai, int b)
{
    vargsiukai.clear();
    kietiakai.clear();
    for (int i = 0; i < studentai.size(); i++)
    {
        if (b == 0)
        {
            if (studentai[i].rez < 5.0) vargsiukai.push_back(studentai[i]);
            else kietiakai.push_back(studentai[i]);
        }
        else
        {
            if (studentai[i].rez2 < 5.0) vargsiukai.push_back(studentai[i]);
            else kietiakai.push_back(studentai[i]);
        }
    }
}
void RusiuotiStudentus(std::vector<studentas>& studentai, int b, int r, int rus)
{
    if (b == 0)
    {
        if (rus == 0)
        {
            if (r == 0) sort(studentai.begin(), studentai.end(), DidVar);
            else sort(studentai.begin(), studentai.end(), MazVar);
        }
        else if (rus == 1)
        {
            if (r == 0) sort(studentai.begin(), studentai.end(), DidPav);
            else sort(studentai.begin(), studentai.end(), MazPav);
        }
        else if (rus == 2)
        {
            if (r == 0) sort(studentai.begin(), studentai.end(), DidVid);
            else sort(studentai.begin(), studentai.end(), MazVid);
        }
    }
    else
    {
        if (rus == 0)
        {
            if (r == 0) sort(studentai.begin(), studentai.end(), DidVar);
            else sort(studentai.begin(), studentai.end(), MazVar);
        }
        else if (rus == 1)
        {
            if (r == 0) sort(studentai.begin(), studentai.end(), DidPav);
            else sort(studentai.begin(), studentai.end(), MazPav);
        }
        else if (rus == 2)
        {
            if (r == 0) sort(studentai.begin(), studentai.end(), DidMed);
            else sort(studentai.begin(), studentai.end(), MazMed);
        }
    }
}

template <typename Konteineris>
void SpausdintiIFaila(const std::string& failoPav, const Konteineris& studentai, int b)
{
    std::ofstream fr(failoPav);
    if (b == 0)
    {
        fr << std::left << std::setw(15) << "Pavarde"<< std::left << std::setw(15) << "Vardas"<< std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
        for (const auto& s : studentai)
        {
            fr << std::left << std::setw(15) << s.pavarde<< std::left << std::setw(15) << s.vardas<< std::fixed << std::setprecision(2) << s.rez << "\n";
        }
    }
    else
    {
        fr << std::left << std::setw(15) << "Pavarde"<< std::left << std::setw(15) << "Vardas"<< std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
        for (const auto& s : studentai)
        {
            fr << std::left << std::setw(15) << s.pavarde<< std::left << std::setw(15) << s.vardas<< std::fixed << std::setprecision(2) << s.rez2 << "\n";
        }
    }

    fr.close();
}

void DarbasSuFailu(const std::string& pradinisFailas, const std::string& vargFailas, const std::string& kietFailas, std::vector<studentas>& studentai, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakai, int ndKiekis, int studentuKiekis, int r, int rus, int b)
{
    //2 tyrimo 5 progamos pasirinkimo veikimo laiko pradzia
    cout << "\nFailas: " << pradinisFailas << "\n";
    auto start5 = high_resolution_clock::now();
    //tyrimas 1 pradzia
    cout<<"1 TYRIMAS"<<std::endl;
    auto start = high_resolution_clock::now();
    GeneruotiStudentuFaila(pradinisFailas, studentuKiekis, ndKiekis);
    auto end = high_resolution_clock::now();
    cout<<studentuKiekis<<" irasu failo kurimo laikas: "<< duration<double>(end - start).count() << " s\n";
    //1 tyrimo pabaiga
    //2 tyrimo pradzia
    auto startNuskaitymas = high_resolution_clock::now();
    NuskaitytiIsFailo(studentai, pradinisFailas, studentuKiekis);
    auto endNuskaitymas = high_resolution_clock::now();

    Skaiciavimai(studentai, b);

    auto startRusiavimas = high_resolution_clock::now();
    RusiuotiStudentus(studentai, b, r, rus);
    auto endRusiavimas = high_resolution_clock::now();

    auto startDalijimas = high_resolution_clock::now();
    PadalintiStudentus(studentai, vargsiukai, kietiakai, b);
    auto endDalijimas = high_resolution_clock::now();

    auto startIsvedimas = high_resolution_clock::now();
    SpausdintiIFaila(vargFailas, vargsiukai, b);
    SpausdintiIFaila(kietFailas, kietiakai, b);
    auto endIsvedimas = high_resolution_clock::now();
    //2 tyrimo pabaiga

    auto end5 = high_resolution_clock::now();
    //2 tyrimo 5 progamos pasirinkimo veikimo laiko pabaiga
    cout << "Nuskaitymo is failo laikas: "<< duration<double>(endNuskaitymas - startNuskaitymas).count() << " s\n";
    cout << "Rusiavimo laikas: "<< duration<double>(endRusiavimas - startRusiavimas).count() << " s\n";
    cout << "Padalijimo i dvi grupes laikas: "<< duration<double>(endDalijimas - startDalijimas).count() << " s\n";
    cout << "Isvedimo i du failus laikas: "<< duration<double>(endIsvedimas - startIsvedimas).count() << " s\n";
    cout << "Visas failo apdorojimo laikas: "<< duration<double>(end5 - start5).count() << " s\n";
    cout<<std::endl;
}

void PenktasP(std::vector<studentas>& studentai, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakai)
{
    int b;
    int rus;
    int r;
    rus = kintrus(rus);
    r = kintr(r);
    b=kinta();//spausdinimo pasirinkimas;
    int ndKiekis = 5; //pasirinktas bet koks nd kiekis
    DarbasSuFailu("studentai1000.txt", "vargsiukai1000.txt", "kietiakai1000.txt", studentai, vargsiukai, kietiakai, ndKiekis, 1000, r, rus, b);
    DarbasSuFailu("studentai10000.txt", "vargsiukai10000.txt", "kietiakai10000.txt", studentai, vargsiukai, kietiakai, ndKiekis, 10000, r, rus, b);
    DarbasSuFailu("studentai100000.txt", "vargsiukai100000.txt", "kietiakai100000.txt", studentai, vargsiukai, kietiakai, ndKiekis, 100000, r, rus, b);
    DarbasSuFailu("studentai1000000.txt", "vargsiukai1000000.txt", "kietiakai1000000.txt", studentai, vargsiukai, kietiakai, ndKiekis, 1000000, r, rus, b);
    DarbasSuFailu("studentai10000000.txt", "vargsiukai10000000.txt", "kietiakai10000000.txt", studentai, vargsiukai, kietiakai, ndKiekis, 10000000, r, rus, b);
}
