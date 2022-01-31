#define MAX_CHAR  10
#define TABLE_SIZE  13
typedef struct {
    char key[MAX_CHAR];
    /* other fields */
} element;
element hash_table[TABLE_SIZE];

void init_table(element ht[])
{
  int i;
  for (i=0; i<TABLE_SIZE; i++)
    ht[i].key[0]= 'NULL' ;
}

int transform(char *key)
{
  int number=0;
  while (*key) number += *key++;
  return number;
}

int hash(char *key)
{
  return (transform(key)
          % TABLE_SIZE);
}
