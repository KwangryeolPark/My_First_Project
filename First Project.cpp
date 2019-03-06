#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238

double Degree_To_Radians(double);
void draw_sin_wave(void);
void draw_rect(unsigned int, unsigned int);
void draw_circle(unsigned int, unsigned int, unsigned int);

int main(void) {
	//	draw_sin_wave();
	//draw_rect(100,100);
	draw_circle(50, 50, 50);
	return 0;
}

double Degree_To_Radians(double degree) {
	return degree * PI / 180;
}
void draw_sin_wave(void) {
	for(unsigned int i = 0; i < 720; i++) {
		int data = int(sin(Degree_To_Radians(i))*20);
		for(int ii = -20; ii < 20; ii++) {
			for(int z = 0; z < ii; z++) printf(" ");
			if(data == ii) printf("*");
		}
		printf("\n");
	}
}
//0 1 2 3 4 3 2 1 0
//1 3 5 7 9 7 5 3 1
//      1 0 1 2 3 4
/*6(9-3) 7	3*2+1
7(9-2) 5	2*2+1
8 3	1*2+1
9 1	0*2+1*/
void draw_rect(unsigned int n, unsigned int n2) {
	#if false
	for(unsigned int i = 1; i <= n; i += 1) {
		if(i <= n/2)	{
			for(unsigned int ii = 0; ii < n/2-int(i); ii++)	printf(" ");
			for(unsigned int z = 0; z < i*2 - 1; z++) 	printf("*");
		} else {
			for(unsigned int ii = 0; ii < (i-n/2); ii++)	printf(" ");
			for(unsigned int z = 1; z < (n-i)*2; z++) 	printf("*");
		}
		printf("\n");
	}	
	#else
	for(unsigned int width = 0; width < n; width++) {
		for(unsigned int height = 0; height < n2; height++) {
			bool function[10];
			function[0] = (height <= width * 5) ? true : false;
			function[1] = (height >= width * 1) ? true : false;
			function[2] = (height >= 50 + width * -1) ? true : false;
			function[3] = (height <= 100 + width * -1) ? true : false;
			for(unsigned int ns = 0; ns < 4; ns++) function[0] *= function[ns];
			if(function[0]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	#endif
}
void draw_circle(unsigned int x, unsigned int y, unsigned int radius) {
	bool function = false;
	for(unsigned int width = 0; width < x+radius; width++) {
		for(unsigned int height = 0; height < y+radius; height++) {	
			function = ((width-x)*(width-x)*5 + (height-y)*(height-y) <= radius*radius) ? true : false;
			if(function) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
