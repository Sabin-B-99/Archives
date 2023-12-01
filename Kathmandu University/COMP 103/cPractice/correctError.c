#include <stdio.h>
int main()
{
    int j = 0;
    for(int i = 0; i < 10; i++){
        if(i<7){
            continue;
        }else if(i > 7){
            j++;
            break;
        }
    }
    return 0;
}