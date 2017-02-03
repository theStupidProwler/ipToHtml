#include <iostream>
#include <fstream>
#include <string>
#include "src/templates.hpp"
using std::ios;

double nombreDeLignes() //fonction qui compte le nombre de ligne (ca semble logique dit comme ca)
  {
    std::string contenu;
    double fichiersAGenerer;
    int nombreLignes;
    std::ifstream access("assets/raw.txt");
    for(nombreLignes = 0; std::getline(access, contenu); nombreLignes ++){}
    std::cout << "Ip Numbers:" << nombreLignes << std::endl;
    fichiersAGenerer = nombreLignes / 255;
    std::cout << "Files to create:" << fichiersAGenerer << std::endl;
    return nombreLignes;
}
int main()
  {

    std::string contenu;
    int i = 0;
    int compteARebour;
    int numeroPage, nombreDePages;
    std::string resultat;
    numeroPage = 0;
    nombreDePages = (nombreDeLignes() / 255);
    std::ofstream ecriture;
    std::ifstream access("assets/raw.txt");
    std::ofstream annuaire("index.html", std::ios::app);
    ecrireDebutIndex();
    std::cout << "Generation:";
    while(numeroPage != nombreDePages)
      {
        numeroPage ++;
        resultat = "links" + std::to_string(numeroPage) + ".html";
        ecriture.open(resultat, std::ios::app);
        ecriture.seekp(0, std::ios_base::end);
        annuaire << "<li><a href=\"links" << numeroPage << ".html\">" << numeroPage << "</a></li>" << std::endl;
        ecrireDebutPage(resultat);
        compteARebour = 0;
        access.seekg(((numeroPage * 255) - 1), ios::beg);
        while(compteARebour != 255)
          {
            i++;
            compteARebour ++;
            std::getline(access, contenu);
            ecriture << "</br><li><a target='_blank' href='http:/" << "/" << contenu << "'>" << "#" << i <<":" << contenu << "</a></li>" << std::endl;
          }
        boutonsNaviguation(numeroPage);
        ecrireFinPage(resultat);
        ecriture.close();
        }
    ecrireFinIndex();
    std::cout << "[OK]" << std::endl;
    return 0;
  }
