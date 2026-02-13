#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

//darbas atliktas su dinamine atmintimi
using std::cin;
using std::string;
using std::cout;

struct studentas
{
   string *var, *pav;
   int *paz[100];
   int *pazkiek;
   double* rez; //su vidurkiu
   double* rez2; //su mediana
}s[100];

struct studentas {
    string* var;
    string* pav;

    int* paz; //pazymiai  
    int  pazkiek; //pazymiu kiekis
    int  pazcap; //kiek telpa - capacity 
    double* rez; //rezultatas vedant n.d vidurki
    double* rez2; //rezultatas skaiciuojant bendra bala su mediana
};

void didStud(studentas*& s, int& scap) { //didinti studentus
    int newCap;
   if (scap == 0) {
       newCap = 2; //pradinis dydis
    } else {
    newCap = scap * 2; //kai truksta vietos dvigubiname
    }

    studentas* ns = new studentas[newCap];

    for (int i = 0; i<scap; i++) ns[i] = s[i]; //kopijuoja rodykles

    delete[] s;
    s = ns;
    scap = newCap;
}

void pridBal(studentas& st, int grade) { //prideda Bala
    if (st.pazcap == 0) {
        st.pazcap = 4;
        st.paz = new int[st.pazcap];
        st.pazkiek = 0;
    }
    if (st.pazkiek == st.pazcap) {
        int newCap = st.pazcap * 2;
        int* np = new int[newCap];
        for (int i = 0; i<st.pazkiek; i++) np[i] = st.paz[i];
        delete[] st.paz;
        st.paz = np;
        st.pazcap = newCap;
    }
    st.paz[st.pazkiek++] = grade;
}

int main()
{
    
    srand(time(nullptr)); //kad kiekviena karta butu generuojami skirtingi pazymiai
    studentas* s = nullptr;
    int scount = 0; //kiek studentų ivesta
    int scap = 0;  //kiek telpa
    int a;
    int i=0; //studento numeriui saugoti
    int j=0; //pazymiu kiekiui saugoti
    string v, p;
    int pz;

    while(i<100)
    //meniu
    int m; //kintamasis skaiciui irasyti
    while(m!=4){
    cout<<"Pasirinkite, kokiu budu norite, kad programa vykdytu uzduoti (1 - duomenu irasymas ranka, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardes ir pazymius, 4 - baigti darbą): "<<std::endl;
    cin>>m;
    if(m==1)
    {
        cout<<"Iveskite studento varda ir pavarde, jei norite baigti ivedima, iveskite 0: "<<std::endl;
        cin>>v;
        if(v=="0") break;
        cin>>p;
        s[i].var=new string[100];
        s[i].pav=new string[100];
        *s[i].var = v;
        *s[i].pav = p;
        cout<<"Iveskite studento pazymius, is kuriu paskutinis yra jo egzamino pazymys, jei norite baigti ivedima, iveskite 0: "<<std::endl;
        while(j<100)
        {
            cin>>pz;
            if(pz==0) break;
            s[i].paz[j] = new int;
            *s[i].paz[j] = pz;
            j++;
        }
        s[i].pazkiek = new int;
        *s[i].pazkiek = j;
        j=0;
        i++;
    while (true) {
    cout << "Iveskite studento varda ir pavarde, jei norite baigti ivedima, iveskite 0:\n";
    cin >> v;
    if (v == "0") break;
    cin >> p;

    if (scount == scap) didStud(s, scap);

    // inicializacija
    s[scount].var = new string(v);
    s[scount].pav = new string(p);
    s[scount].paz = nullptr;
    s[scount].pazkiek = 0;
    s[scount].pazcap = 0;
    s[scount].rez = nullptr;
    s[scount].rez2 = nullptr;

    cout << "Iveskite pazymius (paskutinis - egzaminas), baigti 0:\n";
    while (true) {
        cin >> pz;
        if (pz == 0) break;
        pridBal(s[scount], pz);
    }
    int n;
    n=i;

    scount++;
}

int n = scount;

for (int i = 0; i < n; i++)
{
    s[i].rez = new double;
    int k = *s[i].pazkiek;     //visi pažymiai (ND + egz)
    int k = s[i].pazkiek;     //visi pažymiai (ND + egz)

    double suma = 0;
    for (int j = 0; j < k - 1; j++) //tik ND
        suma += *s[i].paz[j];
        suma += s[i].paz[j];

    double vid = suma / (k - 1);
    int egz = *s[i].paz[k - 1];
    int egz = s[i].paz[k - 1];

    *s[i].rez = 0.4 * vid + 0.6 * egz;
}


for(int i=0; i<n; i++) //rusiavimas medianai
{

    for(int j=0; j<*s[i].pazkiek-1; j++)
    for(int j=0; j<s[i].pazkiek-1; j++)
    {
       for(int jj=0; jj<*s[i].pazkiek-1; jj++){ 
           if(*s[i].paz[j]<*s[i].paz[jj]) std::swap(*s[i].paz[j], *s[i].paz[jj]);
       for(int jj=0; jj<s[i].pazkiek-1; jj++){ 
           if(s[i].paz[j]<s[i].paz[jj]) std::swap(s[i].paz[j], s[i].paz[jj]);
        }
    }
}

for (int i = 0; i < n; i++)
{
    s[i].rez2 = new double;

    int k = *s[i].pazkiek; //visi pažymiai
    int k = s[i].pazkiek; //visi pažymiai
    int nd = k - 1; //ND kiekis

    double med;
    if (nd % 2 == 1) { //nelyginis ND kiekis
        med = *s[i].paz[nd / 2];
        med = s[i].paz[nd / 2];
    } else { //lyginis ND kiekis
        med = (*s[i].paz[nd / 2 - 1] + *s[i].paz[nd / 2]) / 2.0;
        med = (s[i].paz[nd / 2 - 1] + s[i].paz[nd / 2]) / 2.0;
    }

    int egz = *s[i].paz[k - 1];
    int egz = s[i].paz[k - 1];
    *s[i].rez2 = 0.4 * med + 0.6 * egz;
}

   cout<<"Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):"<<std::endl;
   cin>>a;
   if(a==0)
   {
   cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15)<<"Vardas"<< std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
   cout<<"-----------------------------------------------\n";
   for(int i=0; i<n; i++){
   cout<<std::left<<std::setw(15)<<*s[i].pav<<std::left<<std::setw(15)<<*s[i].var<<std::fixed<<std::setprecision(2)<<*s[i].rez<<"\n";
   }
   cout<<"-----------------------------------------------\n";
   }
   else {
   cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15)<<"Vardas"<< std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
   cout<<"-----------------------------------------------\n"; 
   for(int i=0; i<100; i++){
   cout<<std::left<<std::setw(15)<<*s[i].pav<<std::left<<std::setw(15)<<*s[i].var<<std::fixed<<std::setprecision(2)<<*s[i].rez2<<"\n";
   cout<<std::left<<std::setw(15)<<*s[i].pav<<std::left<<std::setw(15)<<*s[i].var<<std::fixed<<std::setprecision(2)<<s[i].rez2<<"\n";
   }
   cout<<"-----------------------------------------------\n";
   }
   for(int i=0; i<n; i++)
      for(int i=0; i<n; i++)
{   
    for(int j=0; j<*s[i].pazkiek; j++) delete s[i].paz[j];
    delete[] s[i].var;
    delete[] s[i].pav;
    delete[] s[i].paz;
    delete s[i].var;
    delete s[i].pav;
    delete s[i].rez;
    delete s[i].rez2;
}

}
    if(m==2)
    {
        while (true) {
    cout << "Iveskite studento varda ir pavarde, jei norite baigti ivedima, iveskite 0:\n";
    cin >> v;
    if (v == "0") break;
    cin >> p;

    if (scount == scap) didStud(s, scap);

    //inicializacija
    s[scount].var = new string(v);
    s[scount].pav = new string(p);
    s[scount].paz = nullptr;
    s[scount].pazkiek = 0;
    s[scount].pazcap = 0;
    s[scount].rez = nullptr;
    s[scount].rez2 = nullptr;

    cout << "Programa sugeneruos pazymius (paskutinis - egzaminas), iveskite kiek pazymiu turi studentai: \n";
    int kiek;
    cin>>kiek;
    for(int i=0; i<kiek; i++)
    {
    pz=rand()%10+1;
    pridBal(s[scount], pz);
    }

    scount++;
}
    }
int n = scount;

for (int i = 0; i < n; i++)
{
    s[i].rez = new double;
    int k = s[i].pazkiek;     //visi pažymiai (ND + egz)

    double suma = 0;
    for (int j = 0; j < k - 1; j++) //tik ND
        suma += s[i].paz[j];

    double vid = suma / (k - 1);
    int egz = s[i].paz[k - 1];

    *s[i].rez = 0.4 * vid + 0.6 * egz;
}


for(int i=0; i<n; i++) //rusiavimas medianai
{

    for(int j=0; j<s[i].pazkiek-1; j++)
    {
       for(int jj=0; jj<s[i].pazkiek-1; jj++){ 
           if(s[i].paz[j]<s[i].paz[jj]) std::swap(s[i].paz[j], s[i].paz[jj]);
        }
    }
}

for (int i = 0; i < n; i++)
{
    s[i].rez2 = new double;

    int k = s[i].pazkiek; //visi pažymiai
    int nd = k - 1; //ND kiekis

    double med;
    if (nd % 2 == 1) { //nelyginis ND kiekis
        med = s[i].paz[nd / 2];
    } else { //lyginis ND kiekis
        med = (s[i].paz[nd / 2 - 1] + s[i].paz[nd / 2]) / 2.0;
    }

    int egz = s[i].paz[k - 1];
    *s[i].rez2 = 0.4 * med + 0.6 * egz;
}

   cout<<"Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):"<<std::endl;
   cin>>a;
   if(a==0)
   {
   cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15)<<"Vardas"<< std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
   cout<<"-----------------------------------------------\n";
   for(int i=0; i<n; i++){
   cout<<std::left<<std::setw(15)<<*s[i].pav<<std::left<<std::setw(15)<<*s[i].var<<std::fixed<<std::setprecision(2)<<*s[i].rez<<"\n";
   }
   cout<<"-----------------------------------------------\n";
   }
   else {
   cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15)<<"Vardas"<< std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
   cout<<"-----------------------------------------------\n"; 
   for(int i=0; i<100; i++){
   cout<<std::left<<std::setw(15)<<*s[i].pav<<std::left<<std::setw(15)<<*s[i].var<<std::fixed<<std::setprecision(2)<<s[i].rez2<<"\n";
   }
   cout<<"-----------------------------------------------\n";
   }
      for(int i=0; i<n; i++)
   {   
    delete[] s[i].paz;
    delete s[i].var;
    delete s[i].pav;
    delete s[i].rez;
    delete s[i].rez2;

    }
    if(m==3)
    {
           while (true) {
    cout << "Iveskite studento varda ir pavarde, jei norite baigti ivedima, iveskite 0:\n";
    cin >> v;
    if (v == "0") break;
    cin >> p;

    if (scount == scap) didStud(s, scap);

    //inicializacija
    s[scount].var = new string(v);
    s[scount].pav = new string(p);
    s[scount].paz = nullptr;
    s[scount].pazkiek = 0;
    s[scount].pazcap = 0;
    s[scount].rez = nullptr;
    s[scount].rez2 = nullptr;

    cout << "Programa sugeneruos pazymius (paskutinis - egzaminas), iveskite kiek pazymiu turi studentai: \n";
    int kiek;
    cin>>kiek;
    for(int i=0; i<kiek; i++)
    {
    pz=rand()%10+1;
    pridBal(s[scount], pz);
    }

    scount++;
}
    }
int n = scount;

for (int i = 0; i < n; i++)
{
    s[i].rez = new double;
    int k = s[i].pazkiek;     //visi pažymiai (ND + egz)

    double suma = 0;
    for (int j = 0; j < k - 1; j++) //tik ND
        suma += s[i].paz[j];

    double vid = suma / (k - 1);
    int egz = s[i].paz[k - 1];

    *s[i].rez = 0.4 * vid + 0.6 * egz;
}


for(int i=0; i<n; i++) //rusiavimas medianai
{

    for(int j=0; j<s[i].pazkiek-1; j++)
    {
       for(int jj=0; jj<s[i].pazkiek-1; jj++){ 
           if(s[i].paz[j]<s[i].paz[jj]) std::swap(s[i].paz[j], s[i].paz[jj]);
        }
    }
}

for (int i = 0; i < n; i++)
{
    s[i].rez2 = new double;

    int k = s[i].pazkiek; //visi pažymiai
    int nd = k - 1; //ND kiekis

    double med;
    if (nd % 2 == 1) { //nelyginis ND kiekis
        med = s[i].paz[nd / 2];
    } else { //lyginis ND kiekis
        med = (s[i].paz[nd / 2 - 1] + s[i].paz[nd / 2]) / 2.0;
    }

    int egz = s[i].paz[k - 1];
    *s[i].rez2 = 0.4 * med + 0.6 * egz;
}

   cout<<"Pasirinkite, kaip norite, kad butu skaiciuojamas galutinis balas - Vid (0) arba Med (1):"<<std::endl;
   cin>>a;
   if(a==0)
   {
   cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15)<<"Vardas"<< std::left << std::setw(15) << "Galutinis (Vid.)" << "\n";
   cout<<"-----------------------------------------------\n";
   for(int i=0; i<n; i++){
   cout<<std::left<<std::setw(15)<<*s[i].pav<<std::left<<std::setw(15)<<*s[i].var<<std::fixed<<std::setprecision(2)<<*s[i].rez<<"\n";
   }
   cout<<"-----------------------------------------------\n";
   }
   else {
   cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15)<<"Vardas"<< std::left << std::setw(15) << "Galutinis (Med.)" << "\n";
   cout<<"-----------------------------------------------\n"; 
   for(int i=0; i<100; i++){
   cout<<std::left<<std::setw(15)<<*s[i].pav<<std::left<<std::setw(15)<<*s[i].var<<std::fixed<<std::setprecision(2)<<s[i].rez2<<"\n";
   }
   cout<<"-----------------------------------------------\n";
   }
      for(int i=0; i<n; i++)
   {   
    delete[] s[i].paz;
    delete s[i].var;
    delete s[i].pav;
    delete s[i].rez;
    delete s[i].rez2;

    
}
    }
    if(m==4) cout<<"Baigiamas darbas.";


    return 0;
}
