#include<vector>
#include<string>
#include"bitmap.h"
#include<iostream>

using namespace std;

string getinput();

void resize(vector< vector < Pixel > >, vector < vector < int > >&);

void averagevector(vector < vector < int > >&, int);

const int MAX_PICTURES = 10;

int main()
{       Bitmap image;
        string input;
        string newinput;
        vector < vector < Pixel > > Image;
        vector < vector < Pixel > > compositeImage;
        vector < vector < int > > redSumVector;
        vector < vector < int > > blueSumVector;
        vector < vector < int > > greenSumVector;
        vector < vector < vector < Pixel > > > images;
        int k=0;
        while(input !="DONE" && k<= MAX_PICTURES)
        {
                input = getinput();
                if(input != "DONE")
                {
                image.open(input);
                }
                bool validImage = image.isImage();
                if(validImage == true)
                {
                        Image = image.toPixelMatrix();
                        images.push_back(Image);
                        if(images[0].size() == images[k].size() && images[0][0].size() == images[0][k].size())
                        {


                                resize(Image, redSumVector);
                                resize(Image, blueSumVector);
                                resize(Image, greenSumVector);


                                for(int i = 0; i< redSumVector.size();i++)
                                {
                                        for(int j=0;j<redSumVector[i].size();j++)
                                        {
                                                Pixel rgb = Image[i][j];
                                                redSumVector[i][j] +=  rgb.red;
                                                blueSumVector[i][j] += rgb.blue; 
                                                greenSumVector[i][j] += rgb.green;
                                        }
                                }
                                cout << "Image " << k+1 << " has been processed." << endl;
                        }
                        else
                        {
                                cout << "Woops! you input an image with the wrong dimensions. It will not be included." << endl;
                                k--;
                        }
                }
                if(validImage == false)
                {
                        cout << "Thats not a valid image!" << endl;
                        k--;
                }



                k++;
        }
        averagevector(redSumVector,k);
        averagevector(blueSumVector,k);
        averagevector(greenSumVector,k);
        compositeImage.resize(redSumVector.size());
        for(int i=0;i<redSumVector.size();i++)
        {
            compositeImage[i].resize(redSumVector[i].size());
        }
        
        for(int i=0; i< compositeImage.size();i++)
        {
                for(int j=0; j<compositeImage[i].size();j++)
                {
                        Pixel rgb = compositeImage[i][j];
                        rgb.red = redSumVector[i][j];
                        rgb.blue = blueSumVector[i][j];
                        rgb.green = greenSumVector[i][j];
                        compositeImage[i][j] = rgb;

                }
        }

        image.fromPixelMatrix(compositeImage);
        image.save("Composite-revolutionkyle");
        





                return 0;
}

string getinput()
{   string pictureLocation;
        cout << "Please insert an image." << endl;
        cin >> pictureLocation;
        return pictureLocation;
}
void resize(vector < vector < Pixel > > pic1, vector < vector < int > >& pic2)
{       
        pic2.resize(pic1.size());
        for(int i =0; i< pic1.size();i++)
        { 
                pic2[i].resize(pic1[i].size());
        }

}

void averagevector(vector < vector < int > >& picture, int k)
{
        for(int i =0; i<picture.size();i++)
        {
                for(int j=0;j<picture[i].size();j++)
                {
                        picture[i][j] = (picture[i][j]/k);
                }
        }
}

