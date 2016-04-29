#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BMP {
    int fileSize;
    int imageWidth;
    int imageHeight;
    int imageSize;
    int * data;
};

struct BMP* load_BMP(char *filename){

    struct BMP *bmp;       // local integer for file loaded
    FILE *in;       // pointer for file opening
    int rowsize;   

    int row, col, color, i;
    unsigned char b;

    in=fopen(filename,"rb"); // open binary file
    if (in==NULL)
    {
        printf("Problem in opening file %s.\n",filename);
        return NULL;
    }


    bmp=(struct BMP*) malloc(sizeof(struct BMP)); //memory allocation
    if (bmp==NULL)
    {
        printf("Not enough memory to load the image.\n");
        return NULL;
    }
/*
    fread(bmp->BM,2,1,in);
    if (bmp->BM[0]!='B' || bmp->BM[1]!='M')
    {
        printf("Bad BMP image file.\n");
        free(bmp);
        return NULL;
    }
*/
    fread(&bmp->fileSize,4,1,in);
    /*fread(&bmp->Reserved1,2,1,in);
    fread(&bmp->Reserved2,2,1,in);
    fread(&bmp->imageOffset,4,1,in);
    fread(&bmp->imageHeaderSize,4,1,in);
    fread(&bmp->imageWidth,4,1,in);*/

    rowsize=4*((3*bmp->imageWidth+3)/4); //calculate rowsize because of padding

    fread(&bmp->imageHeight,4,1,in);
    fread(&bmp->imageSize,4,1,in);

    /*fread(&bmp->colorPlanes,2,1,in);
    fread(&bmp->compressionMethod,4,1,in);
    
    fread(&bmp->hPPM,4,1,in);
    fread(&bmp->vPPM,4,1,in);
    fread(&bmp->paletteColors,4,1,in);
    fread(&bmp->paletteImportantColors,4,1,in);*/


    /*bmp->data=(unsigned char*) malloc(bmp->imageSize); //allocate memory for image data array
    if (bmp->data==NULL)
    {
        printf("There is not enough memory to load the image\n");
        free(bmp);
        return NULL;
    }*/

    for(row=0;row<bmp->imageHeight;row++)  //read picture data
    {
        for(col=0;col<bmp->imageWidth;col++)
            for(color=0;color<=2;color++)
                fread(&bmp->data[row*rowsize+3*col+color],
                sizeof(unsigned char),1,in);

        //read extra bytes for end of row padding
        for(i=0;i<rowsize-3*bmp->imageWidth;i++)
            fread(&b,1,1,in);
    }
    printf("siemaaaaaaaaa\n");
    printf("Height: %d\n", bmp->imageHeight);

    fclose(in);
    return bmp;
}

int main(){

    struct BMP* image;
    load_BMP("croco.bmp");

    return 0;
}
