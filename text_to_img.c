# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <bitmap.h>

# define ASCII_MAX 127
# define PIC_MAX 255

float scale(int num)
{
	return num * (PIC_MAX/ASCII_MAX);
}

int main(int argc, char * argv[])
{

	if(argc != 4){
		fprintf(stderr, "Usage %s <text_file_name> <width> <hight>\n",argv[0]);
		return 1;
	}

	else{

		int width = atoi(argv[2]);
		int hight = atoi(argv[3]);


		int image[hight][width];

		FILE * txt_file = fopen(argv[1],"r");

		int ch,num_ch = 0;
		int x = 0,y = 0;

		while(num_ch <= (width*hight)){
			float value = 0;

			if(ch != EOF){
				fscanf(txt_file,"%c",&ch);
				value = scale(ch);
			}

			image[y][x] = value;
			
			printf("\rProcessing => %d Total => %d", num_ch,(width*hight),value,ch);
			x = num_ch%hight;
			y = num_ch/hight;

			num_ch++;
		}


		fclose(txt_file);


		FILE * image_file = fopen("text.bmp","wb"); 
		create_image(image_file,width,hight,24,width,hight,0,0);
	
		for (int i = 0; i < hight; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				float pixel_val = image[i][j]; 

				write_img(image_file,i,j,pixel_val,pixel_val,pixel_val);

			}
		
		}

		fclose(image_file);

		printf("\n\n");

		return 0;
	}
}

