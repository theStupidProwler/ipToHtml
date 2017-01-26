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
int nombreDeLignes()
  {


    string contenu;
    double fichiersAGenerer;
    int nombreLignes;
    cout << "Comptage de lignes en cours[";
    ifstream access("ip.txt");
    if(!access){cout << "FAIL]";}

    for(nombreLignes = 0; getline(access, contenu); nombreLignes ++){}
    cout << "OK]" << endl << "Nombre de lignes:" << nombreLignes << endl;
    fichiersAGenerer = nombreLignes / 50;
    cout << "Nombre de fichiers a generer:" << fichiersAGenerer << endl;

    return nombreLignes;
}
int main()
  {
    int decompteLien;
    string contenu;
    int i = 0;

    int compteARebour;
    int numeroPage, nombreDePages;
    string resultat;
    numeroPage = 0;
    nombreDePages = (nombreDeLignes() / 255);
    ofstream ecriture;
    ifstream access("raw.txt");
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
              << " <html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"annuaire.css\">" << endl
              << "<title>Botnet Database</title>" << endl
              << "<h1>Botnet Database</h1></head>" << endl
              << "<body><p>Hébérgé sur un serveur de 2006 #norajdemonlagaj</p><ul>" << endl;

    while(numeroPage != nombreDePages)
      {
        numeroPage ++;
        resultat = "links" + to_string(numeroPage) + ".html";
        ecriture.open(resultat.c_str());
        cout << "Tentative d'ouvrir le flux d'ecriture[";
        if(!ecriture)
          {

            cout << "FAIL]" << endl;
            return 403;
          }
      annuaire << "<li><a href=\"links" << numeroPage << ".html\">" << numeroPage << "</a></li>";
      cout << "OK]" << endl;
      cout << "Creation page html basique[";
      ecriture << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />" << endl
              << " <html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"annuaire.css\">" << endl;
              if(numeroPage == 1)
              {
                ecriture << "<a class=\"selecteurhaut\" href=index.html>accueil</a>" << endl;
                ecriture << "<a class=\"selecteurhaut\" href=links" << 2 << ".html>suivant</a><ul>" << endl;
              }
              else
              {
                cout << "Creation des boutons de naviguation[";
                ecriture << "<footer><a class=\"selecteurhaut\" href=links" << (to_string(numeroPage - 1)) << ".html>precedent</a>" << endl;
                ecriture << "<a class=\"selecteurhaut\" href=index.html>accueil</a>" << endl;
                ecriture << "<a class=\"selecteurhaut\" href=links" << (to_string(numeroPage + 1)) << ".html>suivant</a></footer><ul>" << endl;

              }
      ecriture << "<title>Botnet database #"<< numeroPage<<"</title>" << endl
              << "<h1>Bienvenue dans l'annuaire de tous les sites d'internet page "<< numeroPage <<" </h1></head>" << endl
              << "<nav><div class=\"hautbas\"> <ul><li><a href=\"#haut\">Haut</a></li><li><a href=\"#bas\">bas</a></li></ul></div></nav>" << endl
              << "<body><a name=\"haut\"></a><p>Hébérgé sur un serveur de 2006 #norajdemonlagaj</p>" << endl;
      cout << "OK]" << endl;
      cout << "creation des liens[";
      cout << "OK]" << endl;
      compteARebour = 255;

      while(compteARebour > 0)
        {
          if(numeroPage == 1)
            {
              access.seekg(0, ios::beg);
            }
          else
            {
              access.seekg((numeroPage * 255), ios::beg);
            }
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
        cout << "Creation des boutons de naviguation[";
        ecriture << "<footer><a class=\"selecteur\" href=links" << (to_string(numeroPage - 1)) << ".html>precedent</a>" << endl;
        ecriture << "<a class=\"selecteur\" href=index.html>accueil</a>" << endl;
        ecriture << "<a class=\"selecteur\" href=links" << (to_string(numeroPage + 1)) << ".html>suivant</a></footer>" << endl;
      }

        ecriture << "<p>Self-generated, with IpToHtml, by alexandre ouillon</p>" << endl
                << "</br></br><a name=\"bas\"></a></body></html>" << endl;
        cout << "OK]" << endl;



      ecriture.close();

      }
    cout << "Fin d'execution!" << endl;
    annuaire << "<p>Self-generated, with IpToHtml, by alexandre ouillon</p>" << endl
            << "</ul></body></html>" << endl;
    return 0;
  }
