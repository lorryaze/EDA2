#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct _Person {
		int id;
	char fn[100];
	char ln[100];
	char bd[100];
	char ph[100];
} Person;

Person hashes[MAX][100];
int hash_size[MAX];

// retorna indice da matrix hash
int hashing(int key) {
	int hash = (key*2654435761) % 1000;
	return hash;
}

void add() {
	
	Person new;
	
	scanf("%d", &new.id);
	printf("ID = %d\n", new.id);

	scanf("%s", new.fn);
	printf("fisrt name = %s\n", new.fn);
	
	scanf("%s", new.ln);
	printf("last name = %s\n", new.ln);
	
	scanf("%s", new.bd);
	printf("birthday = %s\n", new.bd);

	scanf("%s", new.ph);
	printf("phone = %s\n", new.ph);
	
	int hash = hashing(new.id);
	printf("hash_size= %d\n", hash_size[hash]);

	/*else{
		printf("ID %d ja cadastrado.\n", new.id);
	}*/
}

int main() {
		
	char command[10];	
	while(scanf("%s", command) != EOF){
		add();
	}
	return 0;
}
