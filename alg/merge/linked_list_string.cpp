/* R. Fabbri, 2024 */
#include "linked_list_string.h"
#include <cstdlib>
#include <cstring>

// Inserts
/*
 * A ideia é percorrer a lista até a posição devida:
 * Se for a primeira, retornamos a nova head.
 * Se for a última, só refazemos o link do último node, retornar a tail.
 * Se for no meio, refazer os links, retornar a head.
 *
 * Posição inválida retorna nullptr.
 *
 * Se for ciclica, tratamos a tail remapeada no diver code.
 */
NoArraySingleLink
insertToArraySingle (NoArraySingleLink *head, char data[], unsigned int pos)
{
}
NoPointerSingleLink
insertToPointerSingle (NoPointerSingleLink *head, char *data, unsigned int pos)
{
}
NoArrayDoubleLink
insertToArrayDouble (NoArrayDoubleLink *head, char data[], unsigned int pos)
{
}
NoPointerDoubleLink
insertToPointerDouble (NoPointerDoubleLink *head, char *data, unsigned int pos)
{
}

// Deletes
NoArraySingleLink
deleteFromArraySingle (NoArraySingleLink *head, char data[], unsigned int pos)
{
}
NoPointerSingleLink
deleteFromPointerSingle (NoPointerSingleLink *head, char *data,
                         unsigned int pos)
{
}
NoArrayDoubleLink
deleteFromArrayDouble (NoArrayDoubleLink *head, char data[], unsigned int pos)
{
}
NoPointerDoubleLink
deleteFromPointerDouble (NoPointerDoubleLink *head, char *data,
                         unsigned int pos)
{
}

// Gets
NoArraySingleLink
getFromArraySingle (NoArraySingleLink *head, unsigned int pos)
{
}
NoPointerSingleLink
getFromPointerSingle (NoPointerSingleLink *head, unsigned int pos)
{
}
NoArrayDoubleLink
getFromArrayDouble (NoArrayDoubleLink *head, unsigned int pos)
{
}
NoPointerDoubleLink
getFromPointerDouble (NoPointerDoubleLink *head, unsigned int pos)
{
}
