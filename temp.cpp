#include <iostream>
using namespace std;

main() 
{ 
    char *names[6]; 
    int i;
    for ( i = 0 ; i <= 5 ; i++ ) { 
        printf ( "\nEnter name " ) ; 
        scanf ( "%s", names[i] ) ; 
    } 
}