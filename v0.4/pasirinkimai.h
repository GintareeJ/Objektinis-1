#ifndef PASIRINKIMAI_H
#define PASIRINKIMAI_H

#include <vector>
#include "studentas.h"
#include "rusiavimas.h"

void Skaiciavimai(std::vector<studentas>& studentai, int b);
void Spausdinimas(std::vector<studentas>& studentai, int& b);
void VardasPavarde(std::vector<studentas>& studentai, studentas& s);
int kinta();
int kintrus(int& rus);
int kintr(int& r);
void RandPaz(std::vector<studentas>& studentai, studentas& s, int& kiek);
void PirmasP(std::vector<studentas>& studentai, int& b);
void AntrasP(std::vector<studentas>& studentai, int& b);
void TreciasP(std::vector<studentas>& studentai, const std::vector<std::string>& pavardes,  const std::vector<std::string>& vardai, int& b);
void KetvirtasP(std::vector<studentas>& studentai, const std::string& CVfd, const std::string& CVfr, double& suma2, double& suma3, double& suma4, double& suma5, double& suma6, int& spausd, bool& skaitytaIsFailo, int& b);
void GeneruotiStudentuFaila(const std::string& failoPav, int studentuKiekis, int ndKiekis);
void Tyrimas1(const std::string& failoPav, int studentuKiekis, int ndKiekis);
void NuskaitytiIsFailo(std::vector<studentas>& studentai, const std::string& failoPav, int studentuKiekis);
void PadalintiStudentus(const std::vector<studentas>& studentai, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakiai, int b);
void RusiuotiStudentus(std::vector<studentas>& studentai, int b, int r, int rus);
template <typename Konteineris>
void SpausdintiIFaila(const std::string& failoPav, const Konteineris& studentai, int b);
void DarbasSuFailu(const std::string& pradinisFailas, const std::string& vargFailas, const std::string& kietFailas, std::vector<studentas>& studentai, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakai, int ndKiekis, int studentuKiekis, int r, int rus, int b);
void PenktasP(std::vector<studentas>& studentai, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakai);
#endif
