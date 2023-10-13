//ALI MOHANMADIASL

#include "Inventory.h" 
#include <cstdlib>
  
inventory::inventory (){
  
a = NULL;
b = NULL;

}

void inventory::append (string d){
  
    if (d != "red" && d != "yellow" && d != "blue"){
        cout << "\nThe Given color is not a primary color!";
        exit (EXIT_FAILURE);
    
}

node * tmp = new node;  
tmp->data = d;
tmp->next = NULL;
if (a == NULL){      
    a = tmp;
    b = tmp;
}else{
      
b->next = tmp;
b = b->next;
    
    }

 
}


int inventory::insert (string d, int pos){
  
if (d != "red" && d != "yellow" && d != "blue"){
    cout << "\nThe Given color is not a primary color!";
      exit (EXIT_FAILURE);
}
  
 
int flag = 0, i = 1;
node * trav = a, *prev, *tmp = new node;
tmp->data = d;

while (trav != NULL){
    if (i == pos){
        flag = 1;
        break;
}
      
i++;
prev = trav;
trav = trav->next;
}
 
if (flag == 1){
    if (pos == 1){
        tmp->next = a;
	    a = tmp;
}else{
	tmp->next = trav;
	prev->next = tmp;
} 
return 1; 
}else
    {
return -1;
    
    }

 
}


 
int inventory::Delete (int pos) {
    int flag = 0, i = 1;
    node * t = a, *prev;
    while (t != NULL){
        if (i == pos){
            flag = 1;
            break;
        }
        i++;
        prev = t;
        t = t->next;
    }
if (flag == 1){
    if (pos == 1){
	    a = a->next;
}else{
	prev->next = t->next;
}
return 1;
}else{
    return -1;
}

 
}


 
void inventory::print (){

node * t = a; 
if (t == NULL)
    cout << "\nLinked list is empty";
else{
    while (t != NULL){
	    cout << t->data << endl;
	    t = t->next;
        }
    }
}

 
void inventory::reverse (){

node * cur = a;
node * prev = NULL, *next = NULL;

while (cur != NULL){ 
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;

    }
   
a = prev;

}


int inventory::search (string key) {
   
node * t = a;
int pos = 1;
  
while (t != NULL){
    if (t->data == key)
	return pos;
    t = t->next;
    pos++;
    }

return -1;

}
