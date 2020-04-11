# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BMP_HEADER_SIZE 14
# define BMP_INFO_HEADER_SIZE 40


struct BITMAP_FILE_HEADER
{
	char signature[2];
	int size;
	short reserved_1;
	short reserved_2;
	unsigned int offset;
		
};

struct BITMAP_IMAGE_HEADER
{
	unsigned int header_size;
	int width;
	int hight;
	short planes;
	short bit_per_pix;
	unsigned int compression;
	unsigned int img_size;
	int H_res;
	int V_res;
	unsigned int colors;
	unsigned int important_color;
	
};



void create_image(FILE * image ,int width, int hight,int bit_per_pix,int H_res,int V_res,int colors,int imp_clr){

	struct BITMAP_FILE_HEADER bfh;
	struct BITMAP_IMAGE_HEADER bih;

	int img_size = width * hight;

	//create the header

	memcpy(&bfh.signature,"BM",2);
	bfh.size = BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE + 4* img_size ;
	bfh.reserved_1 = 0;
	bfh.reserved_2 = 0;
	bfh.offset = 0;

	//create the info heaer
	bih.header_size = BMP_INFO_HEADER_SIZE;
	bih.width = width;
	bih.hight = hight;
	bih.planes = 1;
	bih.bit_per_pix = bit_per_pix;
	bih.compression = 0;
	bih.img_size = img_size;
	bih.H_res = H_res;
	bih.V_res = V_res;
	bih.colors = colors;
	bih.important_color = imp_clr;


	//extern FILE * image = fopen(img_name,"wb");
	fwrite(&bfh,1,14,image);
	fwrite(&bih,1,BMP_INFO_HEADER_SIZE,image);

	//return image;
}

void write_img(FILE * img,float r, float g , float b){

	unsigned char color[3] = {b,g,r};
	fwrite(color,1,sizeof(color),img);
}

