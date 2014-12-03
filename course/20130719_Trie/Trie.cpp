/* Library: Trie data structure
 *
 * Sample usage is as the main function.
 *
 * Note that the "NW" represent the  total number of words in trie,
 * and the index is from 0 to N-1. All node are dynamic allocation.
 *
 * Note the insert subroutine, the actual meaning for the trie  is
 * that the path between node represent the word[i].
 *
 *  */
#include <iostream>
#define MAXL 26		//the available words.
using namespace std;

/* for the trie subroutine */
typedef struct NODE_INFO
{
	struct NODE_INFO *next[MAXL];
	int id;
	bool isword;
}NODE;

int NW;			//number of words in the trie.
NODE *root;		//root for the trie.

/* Subroutine: create the root */
void ini()
{
	root = (NODE*)calloc(1, sizeof(NODE));
	NW = 0;
}

/* Subroutine: insert a word into the trie and return the corresponding
 * index. If it is existing in the trie, the inserting operation  won't
 * executed, just find the index and return.
 * Note that all the word should be the small case, and the index is Nw
 * variable. */
int insert(char word[])
{
	int i, l;
	NODE *ptr;			//ptr is for the traversal.
	l = strlen(word);

	for(i=0, ptr=root; i<l; i++)
	{
		if(ptr->next[word[i]-'a']==NULL)	//new node allocation
			ptr->next[word[i]-'a'] = (NODE*)calloc(1, sizeof(NODE));
		ptr = ptr->next[word[i]-'a'];		//"path" represent the word[i]
	}
	if(!(ptr->isword))	//create new id for the word.
		ptr->id = NW++,	ptr->isword = true;
	return ptr->id;		//return the id of the word.
}

/* Clear all the memory allocation in the trie */
void clear_trie(NODE *nd)
{
	if(nd==NULL) return;
	for(int i=0; i<MAXL; i++) clear_trie(nd->next[i]);
	free(nd);
}

int main()
{
	printf("remember to check the word base is a or A\n");
	freopen("2513", "r", stdin);

	char input[100];
	int id, n;

	while(scanf("%d", &n)==1)	//n is the total line of input
	{
		printf("A new trie is to be construction.\n");

		/* initialization for the trie */
		ini();

		/* read the word from the dictionary. */
		while(n--)
		{
			scanf("%s", input);
			id = insert(input);	//search the id of input word
			printf("%10s:%3d \n", input, id);
		}
		printf("Total %d words in the trie\n", NW);

		/* clear the memory in the trie */
		clear_trie(root);

	}

	return 0;
}
