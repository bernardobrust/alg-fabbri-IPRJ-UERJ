#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "linked_list_string.h"

void
handle_single (int operation, int type)
{
  NoPointerSingleLink *head_p
      = (NoPointerSingleLink *)malloc (sizeof (NoPointerSingleLink));
  NoArraySingleLink *head_a
      = (NoArraySingleLink *)malloc (sizeof (NoArraySingleLink));
  char option = 'N';
  while (option == 'N')
    {
      int pos{ 0 };
      std::cout << "\nDigite uma posição (0 é a primeira, 1 a segunda,..., -1 "
                   "para a última): ";
      std::cin >> pos;

      if (pos < -1)
        {
          std::cerr << "Posição inválida!";
          exit (1);
        }

      if (operation == 1)
        {
          // Insert
          if (type == 1)
            {
              // Pointer
              char *data{};
              std::cout << "Whats the data to be inserted?\nData:";
              std::cin >> data;

              if (pos == 0)
                {
                  head_p = insertToPointerSingle (head_p, data, 0);
                }
              else if (pos == -1)
                {
                  insertToPointerSingle (head_p, data, 1);
                }
              else
                {
                  NoPointerSingleLink *ret
                      = insertToPointerSingle (head_p, data, pos);
                  if (ret == nullptr)
                    {
                      std::cerr << "\nPosição Inválida";
                      exit (1);
                    }
                }
            }
          else
            {
              // Array
              char data[MAX_SZA];
              std::cout << "Whats the data to be inserted?\nData:";
              std::cin >> std::setw (sizeof (data)) >> data;
              if (pos == 0)
                {
                  head_a = insertToArraySingle (head_a, data, 0);
                }
              else if (pos == -1)
                {
                  insertToArraySingle (head_a, data, 1);
                }
              else
                {
                  NoArraySingleLink *ret
                      = insertToArraySingle (head_a, data, pos);
                  if (ret == nullptr)
                    {
                      std::cerr << "\nPosição Inválida";
                      exit (1);
                    }
                }
            }
        }
      else
        {
          // Delete
          if (type == 1)
            {
              // Pointer
            }
          else
            {
              // Array
            }
        }

      std::cout << "\nOperação executada!\n";
      std::cout << "Deseja sair?\nOpção (digite 'Q' para sair, 'N' para "
                   "continuar): ";
      std::cin >> option;
    }
}

void
handle_double (int operation, int type)
{
  if (operation == 1)
    {
      // Insert
      if (type == 1)
        {
          // Pointer
        }
      else
        {
          // Array
        }
    }
  else
    {
      // Delete
      if (type == 1)
        {
          // Pointer
        }
      else
        {
          // Array
        }
    }
}

void
handle_cyclic (int operation, int type)
{
  if (operation == 1)
    {
      // Insert
      if (type == 1)
        {
          // Pointer
        }
      else
        {
          // Array
        }
    }
  else
    {
      // Delete
      if (type == 1)
        {
          // Pointer
        }
      else
        {
          // Array
        }
    }
}

int
main ()
{
  int implementation_type, operation, type;

  std::cout << "Digite o tipo de implementacao de lista:\n(1) Encadeada\n(2) "
               "Duplamente encadeada\n(3) Buffer circular\nEscolha:";
  std::cin >> implementation_type;

  if (implementation_type > 3 or implementation_type < 1)
    {
      std::cerr << "Opção inválida!";
      exit (1);
    }

  std::cout << "\nSelecione a operação:\n(1) Inserir\n(2) Deletar\nEscolha:";
  std::cin >> operation;

  if (operation != 1 and operation != 2)
    {
      std::cerr << "Opção inválida!";
      exit (1);
    }

  std::cout << "\nSelecione o tipo:\n(1) Char *\n(2) Char[]\nEscolha:";
  std::cin >> type;

  if (type != 1 and type != 2)
    {
      std::cerr << "Opção inválida!";
      exit (1);
    }

  switch (implementation_type)
    {
    case 1:
      // Single
      handle_single (operation, type);
      break;
    case 2:
      // Double
      handle_double (operation, type);
      break;
    case 3:
      // Cyclic
      handle_cyclic (operation, type);
      break;
    default:
      std::cout << "\nIsso não devia acontecer...";
      exit (1);
      break;
    }

  return 0;
}
