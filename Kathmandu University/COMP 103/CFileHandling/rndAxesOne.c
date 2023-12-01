#include <stdio.h>
typedef struct points
{
    int x;
    int y;
}points;


FILE* in = NULL;
FILE* out = NULL;

int main(void){

    points p1 = {
        .x = 10,
        .y = -82
    };

    points p2;

    out = fopen("points.dat", "wb");
    size_t bytes_written = fwrite(&p1, sizeof(points), 1, out);
    printf("Size written: %zu\n", bytes_written);
    fclose(out);
    if(bytes_written == 0){
        printf("Unknown error. Haven't understood the concepts enough.\n");
    }

    in = fopen("points.dat", "rb");
    size_t bytes_read = fread(&p2, sizeof(points), 1, in);
    printf("Size read: %zu\n", bytes_read);
    fclose(in);
    if(bytes_read == 0){
        printf("Unknown error. Haven't understood the concepts enough.\n");
    }

    printf("X: = %d\n", p2.x);
    printf("Y: = %d\n", p2.y);
    return 0;
}
