#include "templates.hpp"
#include <iostream>
#include <fstream>

void ecrireDebutIndex();
void ecrireFinIndex();
std::string ecrireDebutPage(std::string nomFichier);
std::string ecrireFinPage(std::string nomFichier);

void ecrireDebutIndex()
  {
    std::string content;
    std::ofstream index("index.html");
    std::ifstream templateFile("templates/indexTemplate.html");
    std::getline(templateFile, content);
    while(content != "fin")
      {
        std::getline(templateFile, content);
        index << content << std::endl;
      }
    templateFile.close();
  }
  void ecrireFinIndex()
    {
      std::string content;
      std::ofstream index("index.html");
      std::ifstream templateFile("templates/indexTemplate.html");
      std::getline(templateFile, content);
      while(content != "fin")
        {
          // nothing to do
        }
      while(std::getline(templateFile, content))
        {
          std::getline(templateFile, content);
          index << content << std::endl;
        }
        templateFile.close();
        std::cout << "fermeture du fichier"<< std::endl;
    }
   std::string ecrireDebutPage(std::string nomFichier)
      {
        std::cout << "lancemement de la fonction" << std::endl;
        std::string content;
        std::ofstream liens(nomFichier.c_str());
        std::ifstream templateFile("templates/pagesTemplate.html");
        std::getline(templateFile, content);
        while(content != "fin")
          {
            std::getline(templateFile, content);
            liens << content << std::endl;
            std::cout << "Using Template" << std::endl;
          }
          std::cout << "fermeture du fichier"<< std::endl;
          templateFile.close();
          return "defaut";
        }
    std::string ecrireFinPage(std::string nomFichier)
        {
          std::string content;
          std::string balise = "fin";
          std::ofstream index(nomFichier.c_str());
          std::ifstream templateFile("templates/pagesTemplate.html");
          std::getline(templateFile, content);
          while(content != balise)
            {
              // nothing to do
            }
          while(std::getline(templateFile, content))
            {
              std::getline(templateFile, content);
              index << content << std::endl;
            }
          templateFile.close();
          return "defaut";
        }
