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
    while(content != "<!--fin-->")
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
      templateFile.seekg(0);
      while(content != "<!--fin-->")
        {
          getline(templateFile, content);
        }
      while(std::getline(templateFile, content))
        {
          std::getline(templateFile, content);
          index << content << std::endl;
        }
        templateFile.close();
    }
   std::string ecrireDebutPage(std::string nomFichier)
      {

        std::string content;
        std::ofstream liens(nomFichier);
        std::ifstream templateFile("templates/pagesTemplate.html");
        std::getline(templateFile, content);
        while(content != "<!--fin-->")
          {
            std::getline(templateFile, content);
            liens << content << std::endl;

          }

          templateFile.close();
          return "defaut";
        }
    std::string ecrireFinPage(std::string nomFichier)
        {
          std::string content;
          std::ofstream fichier(nomFichier, std::ios::app);
          std::ifstream templateFile("templates/pagesTemplate.html");


          templateFile.seekg(0);
          while(content != "<!--fin-->")
            {
              getline(templateFile, content);
            }
          while(std::getline(templateFile, content))
            {
              std::getline(templateFile, content);
              fichier << content << "\n";
            
            }
          templateFile.close();
          return "defaut";
        }
