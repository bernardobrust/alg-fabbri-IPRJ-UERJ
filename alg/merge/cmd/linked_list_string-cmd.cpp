#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "linked_list_string.h"

void
handle_single (int operation, int type)
{
  NoPointerSingleLink *head_p = nullptr;
  NoArraySingleLink *head_a = nullptr;
  char option = 'C';
  while (option != 'Q')
    {
      int pos{ 0 };
      std::cout << "Digite uma posição (0 é a primeira, 1 a segunda,...): ";
      std::cin >> pos;

      if (operation == 1)
        {
          // Insert
          char data[MAX_SZA];
          std::cout << "Digite o valor a ser inserido: ";
          std::cin >> data;
          if (type == 1)
            {
              // Pointer
              head_p = insertToPointerSingle (head_p, data, pos);
            }
          else
            {
              // Array
              head_a = insertToArraySingle (head_a, data, pos);
            }
        }
      else
        {
          // Delete
          if (type == 1)
            {
              // Pointer
              head_p = deleteFromPointerSingle (head_p, pos);
            }
          else
            {
              // Array
              head_a = deleteFromArraySingle (head_a, pos);
            }
        }

      std::cout << "Operação executada!\n";
      std::cout << "Lista atual:\n";
      if (type == 1)
        {
          NoPointerSingleLink *curr = head_p;
          while (curr)
            {
              std::cout << curr->name << " -> ";
              curr = curr->next;
            }
        }
      else
        {
          NoArraySingleLink *curr = head_a;
          while (curr)
            {
              std::cout << curr->name << " -> ";
              curr = curr->next;
            }
        }
      std::cout << "nullptr";

      std::cout << "\nDeseja sair?Opção (digite 'Q' para sair, 'C' para "
                   "continuar com essa operação, 'M' para mudar): ";
      std::cin >> option;

      if (option == 'M')
        {
          std::cout
              << "Selecione a operação : (1)Inserir (2) Deletar Escolha: ";
          std::cin >> operation;

          if (operation != 1 and operation != 2)
            {
              std::cerr << "Opção inválida!";
              exit (1);
            }
        }
    }
}

void
handle_double (int operation, int type)
{
  NoPointerDoubleLink *head_p = nullptr;
  NoArrayDoubleLink *head_a = nullptr;
  char option = 'C';
  while (option != 'Q')
    {
      int pos{ 0 };
      std::cout << "Digite uma posição (0 é a primeira, 1 a segunda, ...): ";
      std::cin >> pos;

      if (operation == 1)
        {
          // Insert
          char data[MAX_SZA];
          std::cout << "Digite o valor a ser inserido: ";
          std::cin >> data;
          if (type == 1)
            {
              // Pointer
              head_p = insertToPointerDouble (head_p, data, pos);
            }
          else
            {
              // Array
              head_a = insertToArrayDouble (head_a, data, pos);
            }
        }
      else
        {
          // Delete
          if (type == 1)
            {
              // Pointer
              head_p = deleteFromPointerDouble (head_p, pos);
            }
          else
            {
              // Array
              head_a = deleteFromArrayDouble (head_a, pos);
            }
        }

      std::cout << "Operação executada!\n";
      std::cout << "Lista atual:\nnullptr <-> ";
      if (type == 1)
        {
          NoPointerDoubleLink *curr = head_p;
          while (curr)
            {
              std::cout << curr->name << " <-> ";
              curr = curr->next;
            }
        }
      else
        {
          NoArrayDoubleLink *curr = head_a;
          while (curr)
            {
              std::cout << curr->name << " <-> ";
              curr = curr->next;
            }
        }
      std::cout << "nullptr";

      std::cout << "Deseja sair?Opção (digite 'Q' para sair, 'C' para "
                   "continuar com essa operação, 'M' para mudar): ";
      std::cin >> option;

      if (option == 'M')
        {
          std::cout
              << "Selecione a operação : (1)Inserir (2) Deletar Escolha: ";
          std::cin >> operation;

          if (operation != 1 and operation != 2)
            {
              std::cerr << "Opção inválida!";
              exit (1);
            }
        }
    }
}

void
handle_cyclic (int operation, int type)
{
  NoPointerSingleLink *head_p = nullptr;
  NoArraySingleLink *head_a = nullptr;
  char option = 'C';
  while (option != 'Q')
    {
      int pos{ 0 };
      std::cout << "Digite uma posição (0 é a primeira, 1 a segunda, ...): ";
      std::cin >> pos;

      // Break the cycle for the operation
      if (type == 1)
        {
          if (head_p)
            {
              NoPointerSingleLink *tail = head_p;
              while (tail->next && tail->next != head_p)
                {
                  tail = tail->next;
                }
              if (tail)
                tail->next = nullptr;
            }
        }
      else
        {
          if (head_a)
            {
              NoArraySingleLink *tail = head_a;
              while (tail->next && tail->next != head_a)
                {
                  tail = tail->next;
                }
              if (tail)
                tail->next = nullptr;
            }
        }

      if (operation == 1)
        {
          // Insert
          char data[MAX_SZA];
          std::cout << "Digite o valor a ser inserido: ";
          std::cin >> data;
          if (type == 1)
            {
              head_p = insertToPointerSingle (head_p, data, pos);
            }
          else
            {
              head_a = insertToArraySingle (head_a, data, pos);
            }
        }
      else
        {
          // Delete
          if (type == 1)
            {
              head_p = deleteFromPointerSingle (head_p, pos);
            }
          else
            {
              head_a = deleteFromArraySingle (head_a, pos);
            }
        }

      std::cout << "Operação executada !";
      // Print and re-establish cycle
      if (type == 1)
        {
          if (!head_p)
            {
              std::cout << "Lista: (vazia)";
            }
          else
            {
              std::cout << "Lista: ";
              NoPointerSingleLink *tail = head_p;
              while (tail->next)
                {
                  std::cout << tail->name << " -> ";
                  tail = tail->next;
                }
              std::cout << tail->name << " -> ";
              tail->next = head_p; // Cycle
              std::cout << head_p->name << " (head)";
            }
        }
      else
        {
          if (!head_a)
            {
              std::cout << "Lista: (vazia)";
            }
          else
            {
              std::cout << "Lista: ";
              NoArraySingleLink *tail = head_a;
              while (tail->next)
                {
                  std::cout << tail->name << " -> ";
                  tail = tail->next;
                }
              std::cout << tail->name << " -> ";
              tail->next = head_a; // Cycle
              std::cout << head_a->name << " (head)";
            }
        }

      std::cout << "Deseja sair? Opção (digite 'Q' para sair, 'C' para "
                   "continuar com essa operação, 'M' para mudar): ";
      std::cin >> option;

      if (option == 'M')
        {
          std::cout
              << "Selecione a operação : (1)Inserir (2) Deletar Escolha: ";
          std::cin >> operation;

          if (operation != 1 and operation != 2)
            {
              std::cerr << "Opção inválida!";
              exit (1);
            }
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
