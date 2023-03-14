#include "stdio.h"
#include "float.h"

struct matrix {
int total_row;
int total_col;
int total_element;
float data[];
};

void createMatrix(struct matrix* this_matrix,const int this_total_row,const int this_total_col,float* p_this_test_data,int this_data_length){
    this_matrix->total_row=this_total_row;
    this_matrix->total_col=this_total_col;
    const int this_total_element=this_total_col*this_total_row;
    this_matrix->total_element=this_total_element;

    float test_data[this_total_element];

    // error:
    // int this_length=sizeof(test_data)/sizeof(test_data[0]);
    // printf("sizeof:%d\n",sizeof(test_data));
    // printf("sizeof0:%d\n",sizeof(test_data[0]));

    if(this_total_element<=this_data_length){
        // printf("this_total_element<=this_data_length\n");
        for(int i=0;i<this_total_element;i++){
            // error:
            // this_matrix->data[i]=test_data[i];
            this_matrix->data[i]=*p_this_test_data;
            p_this_test_data++;
        }
        
    }else{
        // printf("this_total_element>this_data_length\n");
        for(int i=0;i<this_data_length;i++){
            this_matrix->data[i]=*p_this_test_data;
            p_this_test_data++;
        }
        for(int i=this_data_length;i<this_total_element;i++){
            this_matrix->data[i]=0;
        }
    }
    p_this_test_data-=this_total_element;
}

void deleteMatrix(struct matrix* this_matrix){
    this_matrix=NULL;
}

void copyMatrix(struct matrix* copy_matrix,struct matrix* paste_matrix){
    const int shared_row=copy_matrix->total_row;
    const int shared_col=copy_matrix->total_col;
    const int total=shared_row*shared_col;

    float* p_paste_data=copy_matrix->data;

    for(int i=0;i<total;i++){
        paste_matrix->data[i]=*p_paste_data;
        p_paste_data++;
    }
    p_paste_data-=total;
}

// struct matrix* addMatrix(struct matrix* matrix1,struct matrix* matrix2){
//     const int shared_row=matrix1->total_row > matrix2->total_row ? matrix1->total_row : matrix2->total_row;
//     const int shared_col=matrix1->total_col > matrix2->total_col ? matrix1->total_col : matrix2->total_col;
//     const int total=shared_row*shared_col;

//     struct matrix* expand_matrix1;
//     struct matrix* expand_matrix2; 
//     struct matrix* result_matrix;

//     expand_matrix1=expandMatrix(expand_matrix1,shared_row,shared_col);
//     expand_matrix2=expandMatrix(expand_matrix2,shared_row,shared_col);

//     int location=0;
//     for(int r=0;r<shared_row;r++){
//         for(int c=0;c<shared_col;c++) {
//             result_matrix->data[location]=expand_matrix1->data[location]+expand_matrix2->data[location];
//             location++;
//         }
//     }
//     return result_matrix;
// }

// struct matrix* subtractMatrix(struct matrix* matrix1,struct matrix* matrix2){
//     const int shared_row=matrix1->total_row > matrix2->total_row ? matrix1->total_row : matrix2->total_row;
//     const int shared_col=matrix1->total_col > matrix2->total_col ? matrix1->total_col : matrix2->total_col;
//     const int total=shared_row*shared_col;

//     struct matrix* expand_matrix1;
//     struct matrix* expand_matrix2; 
//     struct matrix* result_matrix;

//     expand_matrix1=expandMatrix(expand_matrix1,shared_row,shared_col);
//     expand_matrix2=expandMatrix(expand_matrix2,shared_row,shared_col);

//     int location=0;
//     for(int r=0;r<shared_row;r++){
//         for(int c=0;c<shared_col;c++) {
//             result_matrix->data[location]=expand_matrix1->data[location]-expand_matrix2->data[location];
//             location++;
//         }
//     }
//     return result_matrix;
// }

// struct matrix* expandMatrix(struct matrix* this_matrix,const int expand_row,const int expand_col){
//     const int origin_row=this_matrix->total_row;
//     const int origin_col=this_matrix->total_col;
//     const int total=expand_row*expand_col;

//     float empty[total];
//     for(int i=0;i<total;i++) empty[i]=0;
//     struct matrix* result_matrix;
//     result_matrix->total_row=expand_row;
//     result_matrix->total_col=expand_col;
//     result_matrix->total_element=total;
//     // result_matrix.data=empty;
       
//     createMatrix(result_matrix,expand_row,expand_col,&empty[0],sizeof(empty)/sizeof(empty[0]));
//     float* p_data=&this_matrix->data[0];

//     int location_expand=0;
//     for(int r=0;r<origin_row;r++){
//         for(int c=0;c<origin_col;c++) {
//             result_matrix->data[location_expand]=*p_data;
//             location_expand++;
//             p_data++;
//         }
//         for(int c=origin_col;c<expand_col;c++) {
//             result_matrix->data[location_expand]=0;
//             location_expand++;
//         }
//     }
//     for(int r=origin_row;r<expand_row;r++){
//         for(int c=0;c<expand_col;c++) {
//             result_matrix->data[location_expand]=0;
//             location_expand++;
//         }
//     }
//     p_data=0;
//     location_expand=0;
//     return result_matrix;
// }

float findmax(struct matrix* this_matrix){
    float result=FLT_MIN;
    int location=0;
    for(int r=0;r<this_matrix->total_row;r++){
        for(int c=0;c<this_matrix->total_col;c++) {
            result=this_matrix->data[location] > result ? this_matrix->data[location] : result;
            location++;
        }     
    }
    return result;
}

float findmin(struct matrix* this_matrix){
    float result=FLT_MAX;
    int location=0;
    for(int r=0;r<this_matrix->total_row;r++){
        for(int c=0;c<this_matrix->total_col;c++) {
            result=this_matrix->data[location] < result ? this_matrix->data[location] : result;
            location++;
        }     
    }
    return result;
}

void printMatrix(struct matrix* this_matrix){
    const int row=this_matrix->total_row;
    const int col=this_matrix->total_col;
    const int total=row*col;

    printf("print start-------\n");
    int location=0;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++) {
            printf("%d:%f,",location,this_matrix->data[location]);
            location++;
        }     
        printf("\n");
    }
    printf("print end---------\n");
}