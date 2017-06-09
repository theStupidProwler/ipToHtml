#ifndef TEMPLATES_HPP//_INCLUDED
#define TEMPLATES_HPP//_INCLUDED
#include <string>
#include <iostream>

void ecrireDebutIndex();
/*
ecrireDebutIndex et ecrireFinIndex servent a interpreter les templates et à les marquer dans un fichier
*/

void ecrireFinIndex();

void ecrireDebutPage(std::string nomFichier);
/*
ecrireDebutPage et ecrireFinPage servent a interpreter les templates et à les marquer dans un fichier
*/
void ecrireFinPage(std::string nomFichier);

/* Ecrire les boutons de naviguations*/
void boutonsNaviguation(int numeroPage);

void titleNumber(int numeroPage);

void h1Number(int numeroPage);

#endif
