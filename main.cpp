#include <iostream>
#include <fstream>
#include <string>
using std::ios;
void error(int err)
{
switch (err) {
  case 403:
  std::cout << "U must launch dat stupid piece of code in root" << std::endl;
  break;
  case 404:
  std::cout << "WOW DID U JUST TRYNA LAUNCH AN NON EXISTING FILE?\n"
      << "u stupid fagot, relaunch dat code with a valid database in txt"
      << " and the root rights(admin if ur a low-valuable winfag)" << std::endl;
      break;
  case 0:
  break;
}
}
double nombreDeLignes()
  {


    std::string contenu;
    double fichiersAGenerer;
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
      //  int err;
        std::cout << "FAIL]" << std::endl;
        //err = 404;
        //error(err);
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
      annuaire << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />" << std::endl
              << " <html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"assets/annuaire.css\">" << std::endl
              << "<title>Botnet Database</title>" << std::endl
              << "<h1>Botnet Database</h1></head>" << std::endl
              << "<body><p>Hébérgé sur un serveur de 2006 #norajdemonlagaj</p><ul>" << std::endl;

    while(numeroPage != nombreDePages)
      {
        numeroPage ++;
        resultat = "links" + std::to_string(numeroPage) + ".html";
        ecriture.open(resultat.c_str());
        std::cout << "Attempt to create a file stream[";
        if(!ecriture)
          {

            std::cout << "FAIL]" << std::endl;
            return 403;
          }
      annuaire << "<li><a href=\"links" << numeroPage << ".html\">" << numeroPage << "</a></li>";
      std::cout << "OK]" << std::endl;
      std::cout << "Website Creation[";
      ecriture << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />" << std::endl
              << " <html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"annuaire.css\">" << std::endl;
              if(numeroPage == 1)
              {
                ecriture << "<a class=\"selecteurhaut\" href=index.html>accueil</a>" << std::endl;
                ecriture << "<a class=\"selecteurhaut\" href=links" << 2 << ".html>suivant</a><ul>" << std::endl;
              }
              else
              {
                std::cout << "Making navigation button[";
                ecriture << "<footer><a class=\"selecteurhaut\" href=links" << (std::to_string(numeroPage - 1)) << ".html>precedent</a>" << std::endl;
                ecriture << "<a class=\"selecteurhaut\" href=index.html>accueil</a>" << std::endl;
                ecriture << "<a class=\"selecteurhaut\" href=links" << (std::to_string(numeroPage + 1)) << ".html>suivant</a></footer><ul>" << std::endl;

              }
      ecriture << "<title>Botnet database #"<< numeroPage<<"</title>" << std::endl
              << "<h1>Ip list #"<< numeroPage <<" </h1></head>" << std::endl
              << "<nav><div class=\"bottomtop\"> <ul><li><a href=\"#top\">top</a></li><li><a href=\"#bottom\">bottom</a></li></ul></div></nav>" << std::endl
              << "<body><a name=\"top\"></a>" << std::endl;
      std::cout << "OK]" << std::endl;
      std::cout << "Links creation[";
      std::cout << "OK]" << std::endl;
      compteARebour = 255;
      access.seekg(((numeroPage * 255) - 1), ios::beg);
      while(compteARebour > 0)
        {
          compteARebour --;
          access >> contenu;
          ecriture << "</br><li><a target='_blank' href='http:/" << "/" << contenu << "'>"
                  << "#" << i <<":" << contenu
                  << "</a></li>" << std::endl;

          i++;
        }
    ecriture << "</ul>";
    if(numeroPage == 1)
      {
        ecriture << "<a href=links" << 2 << ".html>suivant</a></footer>" << std::endl;
      }
      else
      {

        ecriture << "<footer><a class=\"selecteur\" href=links" << (std::to_string(numeroPage - 1)) << ".html>Previous</a>" << std::endl;
        ecriture << "<a class=\"selecteur\" href=index.html>accueil</a>" << std::endl;
        ecriture << "<a class=\"selecteur\" href=links" << (std::to_string(numeroPage + 1)) << ".html>Following</a></footer>" << std::endl;
      }

        ecriture << "<p>Self-generated, with IpToHtml, by alexandre ouillon</p>" << std::endl //very optional, delete it and set ur name ;)
                << "</br></br><a name=\"bottom\"></a></body></html>" << std::endl;

      ecriture.close();

      }
    std::cout << "This is the end," << std::endl << "my only friend... the end" << std::endl;
    annuaire << "<p>Self-generated, with IpToHtml, by alexandre ouillon</p>" << std::endl //DELETE ITTTTTTTTT
            << "</ul></body></html>" << std::endl;
    return 0;
  }
