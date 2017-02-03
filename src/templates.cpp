#include "templates.hpp"
#include <iostream>
#include <fstream>

void ecrireDebutIndex();
void ecrireFinIndex();
std::string ecrireDebutPage(std::string nomFichier);
std::string ecrireFinPage(std::string nomFichier);
int boutonsNaviguation(std::string nomFichier);
int titleNumber(int numeroPage);
int h1Number(int numeroPage);

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
/*std::string ecrireDebutPage(std::string nomFichier)
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
  }*/
std::string ecrireFinPage(std::string nomFichier)
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
        return "default";
  }
int boutonsNaviguation(int numeroPage)
  {
    std::string content;
    std::string nomFichier = "links" + std::to_string(numeroPage) + ".html";
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
    if(nomFichier == "links1.html")
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
return 1;
}
int titleNumber(int numeroPage)
  {
    std::string content;
    std::string nomFichier = "links" + std::to_string(numeroPage) + ".html";
    std::ifstream templateFile("templates/pagesTemplate.html");
    std::ofstream write(nomFichier, std::ios::app);
    while(content != "<!--title-->")
      {
        getline(templateFile, content);
        getline(templateFile, content);
        write << content;
      }
    if(nomFichier == "links1.html")
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
return 1;
}
int h1Number(int numeroPage)
  {
    std::string content;
    std::string nomFichier = "links" + std::to_string(numeroPage) + ".html";
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
    if(nomFichier == "links1.html")
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
return 1;
}
