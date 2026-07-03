#include "BasicHash.h"

int main( void )
{
    HashTable* HT = create( 193 );

    set( HT, 418,   32114);
    set( HT, 9,    514);
    set( HT, 27,   8917);
    set( HT, 1031, 286);

    printf("Key:%d, Value:%d\n", 418,  get( HT, 418 ) );
    printf("Key:%d, Value:%d\n", 9,    get( HT, 9 ) );
    printf("Key:%d, Value:%d\n", 27,   get( HT, 27 ) );
    printf("Key:%d, Value:%d\n", 1031, get( HT, 1031 ) );

    destroy( HT );

    return 0;
}
