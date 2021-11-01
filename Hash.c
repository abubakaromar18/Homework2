#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 50
#define MAX 256

typedef struct
{
    char* value;
}data;

struct data new_entry[TABLE_SIZE];

data *hash_table[TABLE_SIZE];

unsigned int hash(char *value)
{
    int size = strnlen(value, MAX);
    unsigned int hash_value = 0;

    for(int i = 0; i < size; i++)
    {
        hash_value = hash_value + value[i];
        hash_value = hash_value * value[i];
    }
    hash_value = hash_value % TABLE_SIZE;

    return hash_value;
}

void init_hash_table()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

bool hash_table_insert(data *entry)
{
    if(entry == NULL)
    {
        printf("ERROR: ENTRY WAS NULL\n");
        return false;
    }
    int position = hash(entry->value);
    
    if(hash_table[position] != NULL)
    {
        printf("ERROR: POSITION IN ARRAY WAS ALREADY FILLED\n");
        return false;
    }
    else
    {
        printf("SUCCESSFUL: ENTRY IS NOW STORED IN ARRAY\n");
        hash_table[position] = entry;
        return true;
    }
}

void print_table()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t---%s\n", i, hash_table[i]->value);
        }
    }
}

int main(int argc, char ** argv)
{
    init_hash_table();
    char input[MAX];
    char buffer[MAX];

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int i = 0;

    //READ IN NUMBER TO FIND
    sscanf(input, "%s", argv[0]);

    fp = fopen("test.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        new_entry[i].value = line;
        hash_table_insert(&buffer);
        print_table();
        i==;
    }

    fclose(fp);
}