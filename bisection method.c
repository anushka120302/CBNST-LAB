#include <stdio.h> 
#include <math.h>  
void bisect (float *mid_pt, float int_st, float int_end, int *iter_cnt);  
double get_fun (double res);  
  
  
int main ()  
{   
    int iter_cnt, mx_iter_cnt;  
    float mid_pt, int_st, int_end, err_all, root;  
      
    printf (" \n Enter the first starting point: ");  
    scanf (" %f", &int_st);  
    printf (" \n Enter the second ending point: ");  
    scanf (" %f", &int_end);  
    printf (" \n Enter the maximum iteration to be allowed: ");  
    scanf (" %d", &mx_iter_cnt);  

    printf (" Input the no. of allowed error point: ");  
    scanf (" %f", &err_all);    
    bisect (&mid_pt, int_st, int_end, &iter_cnt);  
       
    for (iter_cnt = 0; iter_cnt < mx_iter_cnt; mid_pt = root)  
    {   
        if ( get_fun (int_st) * get_fun (mid_pt) < 0)  
        {  
            int_end = mid_pt; 
        }  
        else  
        {  
            int_st = mid_pt; 
        }  
          
        bisect ( &root, int_st, int_end, &iter_cnt); 
        if ( fabs (root - mid_pt) < err_all)  
        {  
            printf (" \n The approximation root is: %f \n", root);  
            return 0;  
        }  
    }  
    printf (" The iterations are insufficient: ");  
    return 0;  
}  
  
 
void bisect (float *mid_pt, float int_st, float int_end, int *iter_cnt)  
{  
    *mid_pt = (int_st + int_end) / 2; // get the middle value  
    ++(*iter_cnt); // increment the iteration value  
    printf ( " Iteration \t %d: \t %f \n", *iter_cnt, *mid_pt);  
}  
  
double get_fun (double res)  
{  
    return (res * res * res - 4 * res - 9);  
}  
