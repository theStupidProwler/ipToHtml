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
      std::ofstream index("index.html", std::ios::app);
      std::ifstream templateFile("templates/indexTemplate.html");
      templateFile.seekg(11);
      index.seekp(std::ios_base::end);
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
        std::ofstream liens(nomFichier);
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
          std::ofstream fichier(nomFichier, std::ios::app);
          std::ifstream templateFile("templates/pagesTemplate.html");
          templateFile.seekg(10);
          fichier.seekp(260);
          std::cout << std::to_string(fichier.tellp()) << std::endl << templateFile.tellg();
          while(std::getline(templateFile, content))
            {
              std::getline(templateFile, content);
              fichier << content << "\n";
              std::cout << content << std::endl;
            }
          templateFile.close();
          return "defaut";
        }
