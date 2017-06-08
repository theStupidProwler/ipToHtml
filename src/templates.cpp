#include "templates.hpp"
#include <iostream>
#include <fstream>

void ecrireDebutIndex();
void ecrireFinIndex();
void ecrireDebutPage(std::string nomFichier);
void ecrireFinPage(std::string nomFichier);
int boutonsNaviguation(std::string nomFichier);
void titleNumber(int numeroPage);
void h1Number(int numeroPage);

void ecrireDebutIndex()
  {
    std::string content;
    std::ofstream index("html/index.html");
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
    std::ofstream index("html/index.html", std::ios::app);
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
void ecrireDebutPage(std::string nomFichier)
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
  }
void ecrireFinPage(std::string nomFichier)
  {
    std::string content;
    std::ofstream fichier(nomFichier, std::ios::app);
    std::ifstream templateFile("templates/pagesTemplate.html");
    templateFile.seekg(0);

    while(content != "<!--footer-->")
      {
        getline(templateFile, content);
      }
    while(std::getline(templateFile, content))
      {
        fichier << content << std::endl;
      }
        templateFile.close();

  }
void boutonsNaviguation(int numeroPage)
  {
    std::string content;
    std::string nomFichier = "html/links" + std::to_string(numeroPage) + ".html";
    std::ifstream templateFile("templates/pagesTemplate.html");
    std::ofstream write(nomFichier, std::ios::app);
    while(content != "<!--fin-->")
      {
        getline(templateFile, content);
      }
    while(content != "<!--footer-->")
      {
        getline(templateFile, content);
        write << content;
      }
    if(nomFichier == "html/links1.html")
       {
         write << "<a href=\"index.html\">Home</a><a href=\"links2.html\"> Next </a> " << std::endl;
       }
   else
    {
      std::string inf = "links" + (std::to_string(numeroPage - 1)) + ".html";
      std::string sup = "links" + (std::to_string(numeroPage + 1)) + ".html";
      write << "<div class=\"selecteur\"> <a href=\""<< inf <<"\"> Previous </a>"
            << "<a href=\"index.html\">Home</a>"
            << "<a href=\""<< sup <<"\"> Next </a></div> " << std::endl;
    }

}
void titleNumber(int numeroPage)
  {
    std::string content;
    std::string nomFichier = "html/links" + std::to_string(numeroPage) + ".html";
    std::ifstream templateFile("templates/pagesTemplate.html");
    std::ofstream write(nomFichier, std::ios::app);
    while(content != "<!--titlenumber-->")
      {
        getline(templateFile, content);
      }
    while(content != "<!--h1number-->")
      {
        getline(templateFile, content);
        write << content;
      }
}
void h1Number(int numeroPage)
  {
    std::string content;
    std::string nomFichier = "html/links" + std::to_string(numeroPage) + ".html";
    std::ifstream templateFile("templates/pagesTemplate.html");
    std::ofstream write(nomFichier, std::ios::app);
    while(content != "<!--h1number-->")
      {
        getline(templateFile, content);
      }
      write << numeroPage;
    while(content != "<!--fin-->")
      {
        getline(templateFile, content);
        write << content;
      }

}
