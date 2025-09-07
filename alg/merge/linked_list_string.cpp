/* R. Fabbri, 2024 */
#include "linked_list_string.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

#define MAX_NUMERO_DE_CARACTERES 64
struct No {
  //char *name;
  char name[MAX_NUMERO_DE_CARACTERES];
  /*
   opcional: convencao de '\0' no final
  */
  No *next;
};

typedef No *Lista;

// ---------------------------------------------------------------
// mesma lista, mas com ponteiro pra char
struct No2 {
  char *name;
  //char name[MAX_NUMERO_DE_CARACTERES];
  /*
   opcional: convencao de '\0' no final
  */
  No *next;
};

typedef No2 *Lista2;

void 
playground_lista()
{
  std::cout << "teste" << std::endl;
  Lista l;

  // cria um novo no
  
  l = (No *) malloc(sizeof(No));

  // no caso da implementacao estatica
  l->name[0] = '\0';
  
  // ou no caso do char * :
  //l->name = "";
  //l->name = 0;

  std::cout << std::string(l->name) << std::endl;

  std::cout << "teste" << std::endl;
  // ou
  printf("%s", l->name); // assume que nome contem '\0'
  
  strncpy(l->name, "joao", MAX_NUMERO_DE_CARACTERES);
  
  printf("%s", l->name); // assume que nome contem '\0'
}

void 
playground_lista2()
{
  // Exercicio1: prencher com lista 2
  std::cout << "teste" << std::endl;
  Lista l;

  // cria um novo no
  
  l = (No *) malloc(sizeof(No));

  // no caso da implementacao estatica
  l->name[0] = '\0';
  
  // ou no caso do char * :
  //l->name = "";
  //l->name = 0;

  std::cout << std::string(l->name) << std::endl;

  std::cout << "teste" << std::endl;
  // ou
  printf("%s", l->name); // assume que nome contem '\0'
  
  strncpy(l->name, "joao", MAX_NUMERO_DE_CARACTERES);
  
  printf("%s", l->name); // assume que nome contem '\0'
}
