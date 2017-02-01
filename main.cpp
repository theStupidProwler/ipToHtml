#include <iostream>
#include <fstream>
#include <string>
#include "src/templates.hpp"
using std::ios;

double nombreDeLignes() //fonction qui compte le nombre de ligne (ca semble logique dit comme ca)
  {
    std::string contenu;
    double fichiersAGenerer; // valeurs inutile qui meuble un peu le terminal parce que c'est sympa
    int nombreLignes;
    std::ifstream access("assets/raw.txt");
    for(nombreLignes = 0; std::getline(access, contenu); nombreLignes ++){}
    std::cout << "Nombre de lignes:" << nombreLignes << std::endl;
    fichiersAGenerer = nombreLignes / 50;
    std::cout << "Nombre de fichiers a generer:" << fichiersAGenerer << std::endl;
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
            std::cout << contenu << std::endl;
          }
        std::cout << resultat << std::endl;
        ecrireFinPage(resultat);
        std::cout << "ecriture de la fin du fichier" << std::endl;
        ecriture.close();
        std::cout << "fermeture du flux" << std::endl;
        }
    ecrireFinIndex();
    std::cout << "This is the end," << std::endl << "my only friend... the end" << std::endl;

    return 0;
  }
