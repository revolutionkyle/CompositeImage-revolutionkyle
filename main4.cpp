#include<vector>
#include<iostream>
#include<string>
#include"bitmap.h"

using namespace std;

string getinput();

bool samesize(vector < vector < Pixel > >, vector < vector < Pixel > >);

void averagepixel(vector < vector < Pixel > >&,int);

vector< vector < Pixel > > composite(vector < vector < vector < Pixel > > >);

const int MAX_PICTURES = 255;

int main()
{ vector<string> pictures;
  vector < vector < Pixel > > compositeImage;
  Bitmap image;
  vector < vector < vector < Pixel > > > images;
  vector < vector < Pixel > > bmp;
  string input;

  while(input != "DONE" && pictures.size()<=MAX_PICTURES)
  { 
    input = getinput();
        if(input != "DONE")
        {
            pictures.push_back(input);
        }
    
  }

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
  
  for(int j=0; j< images.size();j++)
  {
    if(samesize(images[0],images[j])==false)
    {
        images.erase(images.begin()+j);
        cout << "This image has the wrong dimensions! It will not be included." << endl;
    }
  }

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
  }
  
  averagepixel(compositeImage,numpics);
  image.fromPixelMatrix(compositeImage);
  image.save("composite-revolutionkyle.bmp");
  




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
void averagepixel(vector < vector < Pixel > >& picture, int a )
{
    for(int i=0;i<picture.size();i++)
    {
        for(int j=0;j<picture[i].size();j++)
        {
            picture[i][j].red = picture[i][j].red/a;
            picture[i][j].blue = picture[i][j].blue/a;
            picture[i][j].green = picture[i][j].green/a;
        }
    }
}
vector < vector < Pixel > > composite(vector < vector < vector < Pixel > > >,vector < vector < Pixel > >&)

