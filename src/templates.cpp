#include "templates.h"
#include <iostream>
#include <fstream>
using namespace std;
void ecrireDebutIndex();
void ecrireFinIndex();
std::string ecrireDebutPage(std::string nomFichier);
std::string ecrireFinPage(std::string nomFichier);

void ecrireDebutIndex()
  {
    std::string content;
    std::string balise = "fin";
    std::ofstream index("index.html");
    std::ifstream templateFile("templates/indexTemplate.html");
    std::getline(templateFile, content);
    while(content != balise)
      {
        std::getline(templateFile, content);
        index << content << endl;
      }

  }
  void ecrireFinIndex()
    {
      std::string content;
      std::string balise = "fin";
      std::ofstream index("index.html");
      std::ifstream templateFile("templates/indexTemplate.html");
      std::getline(templateFile, content);
      while(content != balise)
        {
          // nothing to do 
        }
      while(std::getline(templateFile, content))
        {
          std::getline(templateFile, content);
          index << content << endl;
        }
    }
