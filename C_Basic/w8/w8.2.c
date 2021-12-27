#include <stdio.h>
#include <stdlib.h> 
#include <bsttree.h> // create by your self
#include <time.h>
int main(){
TreeType p, tree = NULL;
int i, n = 0;
srand(time(NULL));
for ( i = 0; i < 10; i++ ) 
insert (rand() % 100, tree ); 
printf("pretty print:\n");
strcpy(prefix," ");
prettyprint(tree,prefix);
printf("\n");
do {
printf("Enter key to search (-1 to quit):");
scanf("%d", &n);
p= Search(n, tree);
if (p!=NULL) printf("Key %d found on the tree",n);
else insert(n, tree);
while (n!=-1);
return 0;
}
