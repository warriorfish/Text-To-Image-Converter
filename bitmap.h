#ifndef _BITMAP_H_
#define _BITMAP_H_

#define BMP_HEADER_SIZE
#define BMP_INFO_HEADER_SIZE

void create_image(FILE * image ,int width, int hight,int bit_per_pix,int H_res,int V_res,int colors,int imp_clr);
void write_img(FILE * img, int x, int y, float r, float g , float b);


#endif