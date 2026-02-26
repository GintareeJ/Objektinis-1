#include "rusiavimas.h"

bool DidPav(studentas &A, studentas &B) { return A.pavarde < B.pavarde; }
bool DidVar(studentas &A, studentas &B) { return A.vardas < B.vardas; }
bool DidVid(studentas &A, studentas &B) { return A.rez < B.rez; }
bool DidMed(studentas &A, studentas &B) { return A.rez2 < B.rez2; }

bool MazPav(studentas &A, studentas &B) { return A.pavarde > B.pavarde; }
bool MazVar(studentas &A, studentas &B) { return A.vardas > B.vardas; }
bool MazVid(studentas &A, studentas &B) { return A.rez > B.rez; }
bool MazMed(studentas &A, studentas &B) { return A.rez2 > B.rez2; }