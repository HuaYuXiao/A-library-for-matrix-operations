#include "stdio.h"
#include <stdlib.h>
#include "function.c"

int main(){
    float empty[]={0};

    struct matrix test_matrix;
    // test_matrix = (struct matrix*)malloc(sizeof(struct matrix));

    //test:
    float test_data[]={1,2,3,4,5,6};

    int test_data_length=sizeof(test_data)/sizeof(test_data[0]);
    createMatrix(&test_matrix,2,3,&test_data[0],test_data_length);

    //test:
    printMatrix(&test_matrix);
    printf("max value:%f\n",findmax(&test_matrix));
    printf("min value:%f\n",findmin(&test_matrix));

    // deleteMatrix(&test_matrix);

    // struct matrix test_matrix_paste;
    // copyMatrix(&test_matrix,&test_matrix_paste);

    // struct matrix* test_matrix_expand;
    // test_matrix_expand = (struct matrix*)malloc(sizeof(struct matrix));
    // test_matrix_expand=expandMatrix(&test_matrix,3,4);
    // printMatrix(test_matrix_expand);

    // struct matrix test_matrix_add;
    // struct matrix test_matrix_result=addMatrix(&test_matrix,&test_matrix_add);
    // printMatrix(&test_matrix_result);

    // free(&test_matrix);
    // free(&test_matrix_expand);

    return 0;
}