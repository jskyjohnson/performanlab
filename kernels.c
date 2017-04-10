/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following student struct 
 */
student_t student = {
    "Sky Johnson",     /* First member full name */
    "skjo8703@colorado.edu"  /* First member email address */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/
 
/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
        }
    }
}

char rotateS_descr[] = "Simple Rotate";
void rotateS(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            dst[RIDX(dim-1-j, i, dim)]  = src[RIDX(i, j, dim)];
        }
    }
}

char rotate6_descr[] = "rotate6 : no multiplcation";
void rotate6(int dim, pixel *src, pixel *dst) 
{
	naive_rotate(dim,src,dst);
}

char rotate5_descr[] = "rotate5: srccalls";
void rotate5(int dim, pixel *src, pixel *dst) 
{
	int i, j;
    int buff = dim*dim;

    dst += buff - dim;
    for (i = 0; i < dim; i += 32){ 
		for (j = 0; j < dim; j++){ 
			*dst = *src;src += dim;
			*(dst + 1)=*src;src += dim;
			*(dst + 2)=*src;src += dim;
			*(dst + 3)=*src;src += dim;
			*(dst + 4)=*src;src += dim;
			*(dst + 5)=*src;src += dim;
			*(dst + 6)=*src;src += dim;
			*(dst + 7)=*src;src += dim;
			*(dst + 8)=*src;src += dim;
			*(dst + 9)=*src;src += dim;
			*(dst + 10)=*src;src += dim;
			*(dst + 11)=*src;src += dim;
			*(dst + 12)=*src;src += dim;
			*(dst + 13)=*src;src += dim;
			*(dst + 14)=*src;src += dim;
			*(dst + 15)=*src;src += dim;
			*(dst + 16)=*src;src += dim;
			*(dst + 17)=*src;src += dim;
			*(dst + 18)=*src;src += dim;
			*(dst + 19)=*src;src += dim;
			*(dst + 20)=*src;src += dim;
			*(dst + 21)=*src;src += dim;
			*(dst + 22)=*src;src += dim;
			*(dst + 23)=*src;src += dim;
			*(dst + 24)=*src;src += dim;
			*(dst + 25)=*src;src += dim;
			*(dst + 26)=*src;src += dim;
			*(dst + 27)=*src;src += dim;
			*(dst + 28)=*src;src += dim;
			*(dst + 29)=*src;src += dim;
			*(dst + 30)=*src;src += dim;
			*(dst + 31)=*src;

			 dst -= dim;
			src -= dim*31 - 1;
		}
		dst += 32 + buff;
		src += dim*31;
	}
}
#define move(a) dst[RIDX(dim-1-j, i+(a), dim)] = src[RIDX(i+(a), j, dim)];

char rotate4_descr[] = "rotate4:v4";
void rotate4(int dim, pixel *src, pixel *dst) 
{

    int i, j;

    for (i = 0; i < dim; i += 32) 
        for (j = 0; j < dim; j++) {
            move(0);move(1);move(2);move(3);
            move(4);move(5);move(6);move(7);
            move(8);move(9);move(10);move(11);
            move(12);move(13);move(14);move(15);
            move(16);move(17);move(18);move(19);
            move(20);move(21);move(22);move(23);
            move(24);move(25);move(26);move(27);
            move(28);move(29);move(30);move(31);
        }
}
char rotate3_descr[] = "rotate3: An even older version";
void rotate3(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    int dst_val, src_val, dim_val, i_val;
    for(i = 0; i < dim; i+=8){
        for(j = 0; j < dim; j++){
			dim_val = dim-1-j;
			i_val = i;
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
        }
    }
}

char rotate2_descr[] = "rotate2: An older working version";
void rotate2(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    int dst_val, src_val, dim_val, i_val;
    for(j = 0; j < dim; j++){
        dim_val = dim-1-j;
        for(i = 0; i < dim; i+=8){
			i_val = i;
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
            
            dst_val = RIDX(dim_val, i_val, dim);
            src_val = RIDX(i_val, j, dim); 
            dst[dst_val]  = src[src_val];
            i_val++;
        }
    }
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Baseworking version";
void rotate(int dim, pixel *src, pixel *dst) 
{
	rotate5(dim, src, dst);
}
/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
    add_rotate_function(&rotate2, rotate2_descr);
    add_rotate_function(&rotate3, rotate3_descr);  
    add_rotate_function(&rotate4, rotate4_descr);
    add_rotate_function(&rotate5, rotate5_descr);
    add_rotate_function(&rotateS, rotateS_descr);
    add_rotate_function(&rotate6, rotate6_descr);
    //add_rotate_function(&attempt_eight, rotate_eight_descr);
}


/***************
 * SMOOTH KERNEL
 **************/
 
/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* Compute min of two integers */
static int min(int a, int b) {
    if(a<b){
        return a;
    }else{
        return b;
    }
}

/* Compute max of two integers */
static int max(int a, int b) {
    if(a>b){
        return a;
    }else{
        return b;
    }
}

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum){
    sum->red = 0;
    sum->green = 0;
    sum->blue = 0;
    sum->num = 0;
}

static void accumulate_sum(pixel_sum *sum, pixel p){
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
}
/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j, ii, jj;
    pixel_sum ps;
    
    for (j = 0; j < dim; j++){
        for (i = 0; i < dim; i++){
            initialize_pixel_sum(&ps);
            for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++){
                for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++){
                    accumulate_sum(&ps, src[RIDX(ii,jj,dim)]);
                }
            }
            dst[RIDX(i,j,dim)].red   = ps.red/ps.num;
            dst[RIDX(i,j,dim)].green = ps.green/ps.num;
            dst[RIDX(i,j,dim)].blue  = ps.blue/ps.num;
        }
    }
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    naive_smooth(dim, src, dst);
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}

