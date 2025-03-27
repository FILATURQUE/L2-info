#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Déclaration anticipée de menu_t
typedef struct menu_s menu_t;

typedef struct 
{
    char* descriptif;
    void (*function) ();
}
action_t;

typedef struct
{
    enum {SE, ACT} type_item;
    union menu
    {
        menu_t* sous_ensemble; // menu_t est maintenant reconnu
        action_t action; 
    };
    
}
item_t;

struct menu_s
{
    menu_t* parent;
    char* descriptif;
    item_t* ensemble;
    int count;    
}; 

menu_t* createMenu(const char* text)
{
    menu_t* newMenu = malloc(sizeof(menu_t));
    char* cpy = malloc(strlen(text)*sizeof(char));
    cpy = strcpy(cpy,text);
    newMenu->parent = NULL;
    newMenu->descriptif = cpy;
    newMenu->ensemble = (void*) malloc(9*sizeof(item_t));
    newMenu->count = 0;
    return newMenu;
}

void addMenuAction(menu_t* m, const char* text, void(*f)())
{
    action_t newAction;
    char* cpy = malloc(strlen(text)*sizeof(char));
    cpy = strcpy(cpy,text);
    newAction.descriptif = cpy;
    newAction.function = f;
    item_t newItem;
    newAction.type_item = ACT;
    newItem.action = newAction;
    m->ensemble[m->count] = newItem;
    m->count++;
}

void addSubMenu(menu_t* m, menu_t* sm)
{   
    if (sm->parent == NULL)
    {
        item_t newItem;
        newItem.sous_ensemble = sm;
        m->ensemble[m->count] = newItem;
        sm->parent = m;
        m->count++;
    }
}

void deleteMenu(menu_t* m)
{
    if (m->parent != NULL)
    {
        for (int i = 0; i < m->count; i++)
        {
            if (m->ensemble[i]->sous_ensemble)
            {
                m->ensemble[i]->sous_ensemble->parent = NULL;
                deleteMenu(m->ensemble[i]->sous_ensemble);
            }
        }
        free(m);
    }
}

int main(){
    return EXIT_SUCCESS;
}

