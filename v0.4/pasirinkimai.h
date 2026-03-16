#ifndef PASIRINKIMAI_H
#define PASIRINKIMAI_H

#include <vector>
#include "studentas.h"
#include "rusiavimas.h"

void Skaiciavimai(std::vector<studentas>& studentai);
void Spausdinimas(std::vector<studentas>& studentai, int& b);
void VardasPavarde(std::vector<studentas>& studentai, studentas& s);
int kinta();
int kintrus(int& rus);
int kintr(int& r);
void RandPaz(std::vector<studentas>& studentai, studentas& s);
void PirmasP(std::vector<studentas>& studentai, int& b);
void AntrasP(std::vector<studentas>& studentai, int& b);
void TreciasP(std::vector<studentas>& studentai, const std::vector<std::string>& pavardes,  const std::vector<std::string>& vardai, int& b);
void KetvirtasP(std::vector<studentas>& studentai, const std::string& CVfd, const std::string& CVfr, double& suma2, double& suma3, double& suma4, double& suma5, double& suma6, int& spausd, bool& skaitytaIsFailo, int& b);

#endif