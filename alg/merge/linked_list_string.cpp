/* R. Fabbri, 2024 */
#include "linked_list_string.h"
#include <cstdlib>
#include <cstring>

// Inserts
/*
 * A ideia é percorrer a lista até a posição devida:
 * Se for a primeira, retornamos a nova head.
 * Se for a última, só refazemos o link do último node, retornar a tail só pra
 * falar que tem retorno. Se for no meio, refazer os links, retornar a head.
 * Posição inválida retorna nullptr.
 *
 * Se for ciclica, tratamos a tail remapeada no diver code.
 */
NoArraySingleLink *
insertToArraySingle (NoArraySingleLink *head, char data[], int pos)
{
}
NoPointerSingleLink *
insertToPointerSingle (NoPointerSingleLink *head, char *data, int pos)
{
}
NoArrayDoubleLink *
insertToArrayDouble (NoArrayDoubleLink *head, char data[], int pos)
{
}
NoPointerDoubleLink *
insertToPointerDouble (NoPointerDoubleLink *head, char *data, int pos)
{
}

// Deletes
NoArraySingleLink *
deleteFromArraySingle (NoArraySingleLink *head, char data[], int pos)
{
}
NoPointerSingleLink *
deleteFromPointerSingle (NoPointerSingleLink *head, char *data, int pos)
{
}
NoArrayDoubleLink *
deleteFromArrayDouble (NoArrayDoubleLink *head, char data[], int pos)
{
}
NoPointerDoubleLink *
deleteFromPointerDouble (NoPointerDoubleLink *head, char *data, int pos)
{
}

// Gets
NoArraySingleLink *
getFromArraySingle (NoArraySingleLink *head, int pos)
{
}
NoPointerSingleLink *
getFromPointerSingle (NoPointerSingleLink *head, int pos)
{
}
NoArrayDoubleLink *
getFromArrayDouble (NoArrayDoubleLink *head, int pos)
{
}
NoPointerDoubleLink *
getFromPointerDouble (NoPointerDoubleLink *head, int pos)
{
}
