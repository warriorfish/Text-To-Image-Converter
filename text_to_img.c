# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "bitmap.h"

# define ASCII_MAX 127
# define PIC_MAX 255

float scale(int num)
{
	return num * (PIC_MAX/ASCII_MAX);
}

int main(int argc, char * argv[])
{

	if(argc != 5){
		fprintf(stderr, "Usage %s <text_file_name> <outfile(without extention)> <width> <hight>\n",argv[0]);
		return 1;
	}

	else{
		
		const int width = atoi(argv[3]);
		const int hight = atoi(argv[4]);


		FILE * txt_file = fopen(argv[1],"r");
		FILE * img_file = fopen(argv[2],"wb");

		create_image(img_file,width,hight,24,width,hight,0,0);

		int ch,num_ch = 0;
		float value = 0;

		while(num_ch <= (width*hight)){


			if(ch != EOF){
				fscanf(txt_file,"%c",&ch);
				value = scale(ch);
			}
			else{
				value = 0.0;
			}

			
			printf("\rProcessing => %d Total => %d", num_ch,(width*hight));
			write_img(img_file,value,value,value);			

			num_ch++;
		}


		fclose(txt_file);
		fclose(img_file);
		printf("\n");

		return 0;
	}
}

