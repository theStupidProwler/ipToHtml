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
    std::cout << "Comptage de lignes en cours[";
    std::ifstream access("assets/raw.txt");
    if(!access){std::cout << "FAIL]";}

    for(nombreLignes = 0; std::getline(access, contenu); nombreLignes ++){}
    std::cout << "OK]" << std::endl << "Nombre de lignes:" << nombreLignes << std::endl;
    fichiersAGenerer = nombreLignes / 50;
    std::cout << "Nombre de fichiers a generer:" << fichiersAGenerer << std::endl;

    return nombreLignes;
}
int main()
  {
  //  int decompteLien;
    std::string contenu;
    int i = 0;

    int compteARebour;
    int numeroPage, nombreDePages;
    std::string resultat;
    numeroPage = 0;
    nombreDePages = (nombreDeLignes() / 255);
    std::ofstream ecriture;
    std::ifstream access("examples/raw.txt");
    std::cout << "Tentative d'ouvrir le flux de lecture[";
    if(!access)
      {

        std::cout << "FAIL]" << std::endl;

        return 403;
      }
    std::cout << "OK]" << std::endl;
    std::ofstream annuaire("index.html");
    std::cout << "Tentative d'ouvrir le flux d'ecriture[";
    if(!annuaire)
      {
        std::cout << "FAIL]" << std::endl;

        return 403;
      }
      std::cout << "OK]" << std::endl;
      ecrireDebutIndex();
    while(numeroPage != nombreDePages)
      {
        numeroPage ++;
        resultat = "links" + std::to_string(numeroPage) + ".html";
        ecriture.open(resultat);
        ecriture.seekp(0, std::ios_base::end);
        std::cout << "Attempt to create a file stream[";
        annuaire << "<li><a href=\"links" << numeroPage << ".html\">" << numeroPage << "</a></li>" << std::endl;
        std::cout << "OK]" << std::endl;
        std::cout << "Website Creation[";
        ecrireDebutPage(resultat);
        std::cout << "OK]" << std::endl;
        std::cout << "Links creation[";
        std::cout << "OK]" << std::endl;
        compteARebour = 255;
        access.seekg(((numeroPage * 255) - 1), ios::beg);

     while(!(compteARebour == 0))
       {
          i++;
          compteARebour --;
          access >> contenu;
          ecriture.seekp(std::ios_base::end);
          ecriture << "</br><li><a target='_blank' href='http:/" << "/" << contenu << "'>"
                  << "#" << i <<":" << contenu << "</a></li>" << std::endl;
          std::cout << compteARebour << std::endl;

        }

          std::cout << "sortie du while malefique" << std::endl;
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
