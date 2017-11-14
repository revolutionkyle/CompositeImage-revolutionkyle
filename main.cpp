#include<vector>
#include<iostream>
#include<string>
#include"bitmap.h"

using namespace std;

string getinput(); //gets input from user for file names.

bool samesize(vector < vector < Pixel > >, vector < vector < Pixel > >); //tests whether or not 2 images are the same size.

void averagepixel(vector < vector < Pixel > >&,int); //takes the average value of each color at each pixel based around the integer.



int main()
{ //variable declaration.
        vector<string> pictures;
        vector < vector < Pixel > > compositeImage;
        Bitmap image;
        vector < vector < vector < Pixel > > > images;
        vector < vector < Pixel > > bmp;
        string input;
        //get user input and fill a vector of strings.

        while(input != "DONE")
        { 
                input = getinput();
                if(input != "DONE")
                {
                        pictures.push_back(input);
                }

        }
        //open and validate the images as proper images
        for(int i=0;i<pictures.size();i++)
        { 
                image.open(pictures[i]);
                if(image.isImage())
                {
                        bmp = image.toPixelMatrix();
                        images.push_back(bmp);
                }
                else
                { cout << "Not an image!" << pictures[i] << " won't be included." << endl;
                }
        }
        if(images.size() <2)
        {
                cout << "Error! composite image cannot be made." << endl;
                return 0;
        }

        for(int j=0; j< images.size();j++)
        {
                if(samesize(images[0],images[j])==false)
                {
                        images.erase(images.begin()+j);
                        cout << "This image has the wrong dimensions! It will not be included." << endl;
                }
        }

        //loop through the 3d matrix and fill it with the sum of rgb values.

        int numpics = images.size();
        int rows = images[0].size();
        int cols = images[0][0].size();
        compositeImage.resize(images[0].size());
        for(int i=0;i<images[0].size();i++)
        {
                compositeImage[i].resize(images[0][0].size());
        }
        
        
        for(int i=0;i<cols;i++)
        {
                for(int j=0;j<rows;j++)
                {
                        for(int k=0;k<numpics;k++)
                        {   Pixel rgb =compositeImage[j][i];
                                rgb.red += images[k][j][i].red;
                                rgb.blue += images[k][j][i].blue;
                                rgb.green += images[k][j][i].green;
                                compositeImage[j][i] = rgb;
                        }
                        
                }
               if(i==images[0][0].size())
               {
                cout<< "The composite image is halfway done." << endl;
               }
                
        }


        //average the values of each color for each pixel based on number of pictures.
        averagepixel(compositeImage,numpics);
        //convert matrix back into an image.
        image.fromPixelMatrix(compositeImage);
        //save image as composite-revolutionkyle.bmp
        image.save("composite-revolutionkyle.bmp");
        cout << "The composite image is ready!" << endl;






        return 0;
}


string getinput()
{   string pictureLocation;
        cout << "Please insert an image." << endl;
        cin >> pictureLocation;
        return pictureLocation;
}
bool samesize(vector < vector < Pixel > > pic1, vector < vector < Pixel > > pic2)
{
        if(pic1.size() == pic2.size() || pic1[0].size() == pic2.size())
        {
                return true;
        }
        else
        {
                return false;
        }
}
void averagepixel(vector < vector < Pixel > >& image, int a)
{
    for(int i=0;i<image.size();i++)
    {
        for(int j=0;j<image[i].size();j++)
        {
            Pixel rgb = image[i][j];
            rgb.red = rgb.red/a;
            rgb.blue = rgb.blue/a;
            rgb.green = rgb.green/a;
            image[i][j] = rgb;
        }
    }
}
