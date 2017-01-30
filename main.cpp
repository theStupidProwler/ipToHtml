#include <iostream>
#include <fstream>
#include <string>
using namespace std;




void error(int err)
{
switch (err) {
  case 403:
  cout << "U must launch dat stupid piece of code in root" << endl;
  break;
  case 404:
  cout << "WOW DID U JUST TRYNA LAUNCH AN NON EXISTING FILE?\n"
      << "u stupid fagot, relaunch dat code with a valid database in txt"
      << " and the root rights(admin if ur a low-valuable winfag)" << endl;
      break;
  case 0:
  break;
}
}
double nombreDeLignes()
  {


    string contenu;
    double fichiersAGenerer;
    int nombreLignes;
    cout << "Comptage de lignes en cours[";
    ifstream access("examples/raw.txt");
    if(!access){cout << "FAIL]";}

    for(nombreLignes = 0; getline(access, contenu); nombreLignes ++){}
    cout << "OK]" << endl << "Nombre de lignes:" << nombreLignes << endl;
    fichiersAGenerer = nombreLignes / 50;
    cout << "Nombre de fichiers a generer:" << fichiersAGenerer << endl;

    return nombreLignes;
}
int main()
  {
  //  int decompteLien;
    string contenu;
    int i = 0;

    int compteARebour;
    int numeroPage, nombreDePages;
    string resultat;
    numeroPage = 0;
    nombreDePages = (nombreDeLignes() / 255);
    ofstream ecriture;
    ifstream access("examples/raw.txt");
    cout << "Tentative d'ouvrir le flux de lecture[";
    if(!access)
      {
      //  int err;
        cout << "FAIL]" << endl;
        //err = 404;
        //error(err);
        return 403;
      }
    cout << "OK]" << endl;
    ofstream annuaire("index.html");
    cout << "Tentative d'ouvrir le flux d'ecriture[";
    if(!annuaire)
      {
        cout << "FAIL]" << endl;

        return 403;
      }
      cout << "OK]" << endl;
      annuaire << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />" << endl
              << " <html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"assets/annuaire.css\">" << endl
              << "<title>Botnet Database</title>" << endl
              << "<h1>Botnet Database</h1></head>" << endl
              << "<body><p>Hébérgé sur un serveur de 2006 #norajdemonlagaj</p><ul>" << endl;

    while(numeroPage != nombreDePages)
      {
        numeroPage ++;
        resultat = "links" + to_string(numeroPage) + ".html";
        ecriture.open(resultat.c_str());
        cout << "Attempt to create a file stream[";
        if(!ecriture)
          {

            cout << "FAIL]" << endl;
            return 403;
          }
      annuaire << "<li><a href=\"links" << numeroPage << ".html\">" << numeroPage << "</a></li>";
      cout << "OK]" << endl;
      cout << "Website Creation[";
      ecriture << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />" << endl
              << " <html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"annuaire.css\">" << endl;
              if(numeroPage == 1)
              {
                ecriture << "<a class=\"selecteurhaut\" href=index.html>accueil</a>" << endl;
                ecriture << "<a class=\"selecteurhaut\" href=links" << 2 << ".html>suivant</a><ul>" << endl;
              }
              else
              {
                cout << "Making navigation button[";
                ecriture << "<footer><a class=\"selecteurhaut\" href=links" << (to_string(numeroPage - 1)) << ".html>precedent</a>" << endl;
                ecriture << "<a class=\"selecteurhaut\" href=index.html>accueil</a>" << endl;
                ecriture << "<a class=\"selecteurhaut\" href=links" << (to_string(numeroPage + 1)) << ".html>suivant</a></footer><ul>" << endl;

              }
      ecriture << "<title>Botnet database #"<< numeroPage<<"</title>" << endl
              << "<h1>Ip list #"<< numeroPage <<" </h1></head>" << endl
              << "<nav><div class=\"bottomtop\"> <ul><li><a href=\"#top\">top</a></li><li><a href=\"#bottom\">bottom</a></li></ul></div></nav>" << endl
              << "<body><a name=\"top\"></a>" << endl;
      cout << "OK]" << endl;
      cout << "Links creation[";
      cout << "OK]" << endl;
      compteARebour = 255;
      access.seekg(((numeroPage * 255) - 1), ios::beg);
      while(compteARebour > 0)
        {
          compteARebour --;
          access >> contenu;
          ecriture << "</br><li><a target='_blank' href='http:/" << "/" << contenu << "'>"
                  << "#" << i <<":" << contenu
                  << "</a></li>" << endl;

          i++;
        }
    ecriture << "</ul>";
    if(numeroPage == 1)
      {
        ecriture << "<a href=links" << 2 << ".html>suivant</a></footer>" << endl;
      }
      else
      {

        ecriture << "<footer><a class=\"selecteur\" href=links" << (to_string(numeroPage - 1)) << ".html>Previous</a>" << endl;
        ecriture << "<a class=\"selecteur\" href=index.html>accueil</a>" << endl;
        ecriture << "<a class=\"selecteur\" href=links" << (to_string(numeroPage + 1)) << ".html>Following</a></footer>" << endl;
      }

        ecriture << "<p>Self-generated, with IpToHtml, by alexandre ouillon</p>" << endl //very optional, delete it and set ur name ;)
                << "</br></br><a name=\"bottom\"></a></body></html>" << endl;

      ecriture.close();

      }
    cout << "This is the end," << endl << "my only friend... the end" << endl;
    annuaire << "<p>Self-generated, with IpToHtml, by alexandre ouillon</p>" << endl //DELETE ITTTTTTTTT
            << "</ul></body></html>" << endl;
    return 0;
  }
