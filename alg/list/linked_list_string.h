/* R. Fabbri, 2025 */
#ifndef LINKED_LIST_STRING_H
#define LINKED_LIST_STRING_H

#define MAX_SZA 64

// Singles, funciona pra circular tb
struct NoArraySingleLink
{
  char name[MAX_SZA];

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
  char name[MAX_SZA];

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
NoArraySingleLink *insertToArraySingle (NoArraySingleLink *head, char data[],
                                        int pos);
NoPointerSingleLink *insertToPointerSingle (NoPointerSingleLink *head,
                                            char *data, int pos);
NoArrayDoubleLink *insertToArrayDouble (NoArrayDoubleLink *head, char data[],
                                        int pos);
NoPointerDoubleLink *insertToPointerDouble (NoPointerDoubleLink *head,
                                            char *data, int pos);

// Deletes
NoArraySingleLink *deleteFromArraySingle (NoArraySingleLink *head, int pos);
NoPointerSingleLink *deleteFromPointerSingle (NoPointerSingleLink *head,
                                              int pos);
NoArrayDoubleLink *deleteFromArrayDouble (NoArrayDoubleLink *head, int pos);
NoPointerDoubleLink *deleteFromPointerDouble (NoPointerDoubleLink *head,
                                              int pos);

// Gets
void getFromArraySingle (NoArraySingleLink *head, int pos);
NoPointerSingleLink* getFromPointerSingle (NoPointerSingleLink *head, int pos);
void getFromArrayDouble (NoArrayDoubleLink *head, int pos);
void getFromPointerDouble (NoPointerDoubleLink *head, int pos);

// Other operations
int sum (NoPointerSingleLink *head);
int sumRec (NoPointerSingleLink *head, int acc);

#endif /* LINKED_LIST_STRING_H */
