#include<stdio.h>
#include<math.h>
#include "pbPlots.h"
#include "supportLib.h"

int main()
{
    double x[]= {1.0,2.0,3.0,4.0,2.0,1.0};
    double y[20];
    y[0] = x[0];
    y[1] = -0.5*y[0]+x[1];

    double axis[20];
    axis[0]=0;
    axis[1]=1;

    for(int n=2;n<20;n++)
    {
        axis[n]=n;
        if(n<6)
            y[n] = -0.5*y[n-1]+x[n]+x[n-2];
        else if(n>5 && n<8)
            y[n] = -0.5*y[n-1]+x[n-2];
	    else
		    y[n] = -0.5*y[n-1];
    }
    //for(int i=0;i<20;i++)
        //printf(y[i]);
    _Bool success;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	StringReference *errorMessage = (StringReference *)malloc(sizeof(StringReference));
	success = DrawScatterPlot(canvasReference, 600, 400, axis, 20, y, 20, errorMessage);

    if(success){
        size_t length;
        double *pngdata = ConvertToPNG(&length, canvasReference->image);
        WriteToFile(pngdata, length, "3.3.png");
        DeleteImage(canvasReference->image);
	}else{
	    fprintf(stderr, "Error: ");
	    for(int i = 0; i < errorMessage->stringLength; i++){
            fprintf(stderr, "%c", errorMessage->string[i]);
        }
        fprintf(stderr, "\n");
    }

	return success ? 0 : 1;
}
