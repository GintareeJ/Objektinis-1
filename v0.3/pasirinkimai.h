#ifndef APDOROJIMAS_H
#define APDOROJIMAS_H

#include <vector>
#include "studentas.h"
#include "rusiavimas.h"

void PirmasP(std::vector<studentas>& studentai);
void AntrasP(std::vector<studentas>& studentai);
void TreciasP(std::vector<studentas>& studentai, const std::vector<std::string>& pavardes,  const std::vector<std::string>& vardai);
void KetvirtasP(std::vector<studentas>& studentai, const std::string& CVfd, const std::string& CVfr, double& suma2, double& suma3, double& suma4, double& suma5, double& suma6, int& spausd);

#endif