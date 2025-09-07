/* R. Fabbri, 2025 */
#ifndef LINKED_LIST_STRING_H
#define LINKED_LIST_STRING_H

#define MAX_NUMERO_DE_CARACTERES 64

// Singles, funciona pra circular tb
struct NoArraySingleLink
{
  char name[MAX_NUMERO_DE_CARACTERES];

  NoArraySingleLink *next;
};
struct NoPointerSingleLink
{
  char *name;

  NoPointerSingleLink *next;
};

// Doubles
struct NoArrayDoubleLink
{
  char name[MAX_NUMERO_DE_CARACTERES];

  NoArrayDoubleLink *next;
  NoArrayDoubleLink *prev;
};
struct NoPointerDoubleLink
{
  char *name;

  NoPointerDoubleLink *next;
  NoPointerDoubleLink *prev;
};

// Inserts
NoArraySingleLink insertToArraySingle (NoArraySingleLink *head, char data[],
                                       unsigned int pos);
NoPointerSingleLink insertToPointerSingle (NoArraySingleLink *head, char *data,
                                           unsigned int pos);
NoArrayDoubleLink insertToArrayDouble (NoArraySingleLink *head, char data[],
                                       unsigned int pos);
NoPointerDoubleLink insertToPointerDouble (NoArraySingleLink *head, char *data,
                                           unsigned int pos);

// Deletes
NoArraySingleLink deleteFromArraySingle (NoArraySingleLink *head, char data[],
                                         unsigned int pos);
NoPointerSingleLink deleteFromPointerSingle (NoArraySingleLink *head,
                                             char *data, unsigned int pos);
NoArrayDoubleLink deleteFromArrayDouble (NoArraySingleLink *head, char data[],
                                         unsigned int pos);
NoPointerDoubleLink deleteFromPointerDouble (NoArraySingleLink *head,
                                             char *data, unsigned int pos);

// Gets
NoArraySingleLink getFromArraySingle (NoArraySingleLink *head,
                                      unsigned int pos);
NoPointerSingleLink getFromPointerSingle (NoArraySingleLink *head,
                                          unsigned int pos);
NoArrayDoubleLink getFromArrayDouble (NoArraySingleLink *head,
                                      unsigned int pos);
NoPointerDoubleLink getFromPointerDouble (NoArraySingleLink *head,
                                          unsigned int pos);

#endif /* LINKED_LIST_STRING_H */
