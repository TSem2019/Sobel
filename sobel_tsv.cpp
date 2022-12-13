#include "sobel_tsv.h"

int* sobel_tsv(int *src, int width, int height)
{
    int *result = nullptr;
    result      = new int [width*height];


    int gx, gy;

    int z[9]    = {0,0,0,0,0,0,0,0,0};
    int *pz0    = &z[0];
    int *pz2    = pz0 + 2;
    int *pz3    = pz0 + 3;
    int *pz5    = pz0 + 5;
    int *pz6    = pz0 + 6;
    int *pz8    = pz0 + 8;

    int *pt1    = src;
    int *pt2    = src;
    int *pt3    = src + width;
    int *ptr    = result;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {

            if (col == 0)
            {
                *pz0 =  *pt1;
                *pz3 =  *pt2;
                *pz6 =  *pt3;
            }
            else
            {
                *pz0 =  *(pt1 - 1);
                *pz3 =  *(pt2 - 1);
                *pz6 =  *(pt3 - 1);
            }


            if (col == (width - 1))
            {
                *pz2 =  *pt1;
                *pz5 =  *pt2;
                *pz8 =  *pt3;
            }
            else
            {
                *pz2 =  *(pt1 + 1);
                *pz5 =  *(pt2 + 1);
                *pz8 =  *(pt3 + 1);
            }

            gx = (z[2] + 2*z[5]   + z[8]) - (z[0] + 2*z[3]   + z[6]);
            gy = (z[6] + 2*(*pt3) + z[8]) - (z[0] + 2*(*pt1) + z[2]);

            *ptr = int(sqrt(pow(gx,2) + pow(gy,2)));
            ptr++;

            pt1++;
            pt2++;
            pt3++;
        }

        if (row == 0)
            pt1 -= width;

        if (row == (height - 2))
            pt3 -= width;
    }

    return result;
}
    //
/*
    int *pt1    = src+1;
    int *pt2    = src+1;
    int *pt3    = src + width + 1;
    int *ptr    = result + 1;

    for (int row = 0; row < height; row++)
    {
        for (int col = 1; col < (width - 1); col++)
        {

            *pz0 =  *(pt1 - 1);
            *pz3 =  *(pt2 - 1);
            *pz6 =  *(pt3 - 1);

            *pz2 =  *(pt1 + 1);
            *pz5 =  *(pt2 + 1);
            *pz8 =  *(pt3 + 1);


            gx = (*pz2+2*(*pz5)+*pz8) - (*pz0+2*(*pz3)+*pz6);//(z[2]+2*z[5]+z[8])   - (z[0]+2*z[3]+z[6]);
            gy = (*pz6+2*(*pt3)+*pz8) - (*pz0+2*(*pt1)+*pz2);//(z[6]+2*(*pt3)+z[8]) - (z[0]+2*(*pt1)+z[2]);

            *ptr = int(sqrt(pow(gx,2) + pow(gy,2)));
            ptr++;

            pt1++;
            pt2++;
            pt3++;
        }
        ptr+= 2;

        pt1+= 2;
        pt2+= 2;
        pt3+= 2;

        if (row == 0)
            pt1 -= width;

        if (row == (height - 2))
            pt3 -= width;
    }
//---
     pt1    = src;
     pt2    = src;
     pt3    = src + width;
     ptr    = result;

    for (int row = 0; row < height; row++)
    {

        *pz2 =  *(pt1 + 1);
        *pz5 =  *(pt2 + 1);
        *pz8 =  *(pt3 + 1);

        gx = (*pz2+2*(*pz5)+*pz8)   - (*(pt1)+2*(*(pt2))+*(pt3));
        gy = (3*(*pt3)+*pz8) - (3*(*pt1)+*pz2);

        *ptr = int(sqrt(pow(gx,2) + pow(gy,2)));

        ptr+= width;
        pt2+= width;

        if (row != 0)
            pt1 += width;

        if (row != (height - 2))
            pt3 += width;

    }

    pt1    = src+width-1;
    pt2    = src+width-1;
    pt3    = src + width+width-1;
    ptr    = result+width-1;

   for (int row = 0; row < height; row++)
   {

       *pz0 =  *(pt1 - 1);
       *pz3 =  *(pt2 - 1);
       *pz6 =  *(pt3 - 1);

       gx = (*(pt1)+2*(*(pt2))+*(pt3))   - (*pz0+2*(*pz3)+*pz6);
       gy = (*pz6 - *pz0) + 3*((*pt3) - (*pt1));

       *ptr = int(sqrt(pow(gx,2) + pow(gy,2)));

       ptr+= width;
       pt2+= width;

       if (row != 0)
           pt1 += width;

       if (row != (height - 2))
           pt3 += width;
   }
*/


