#include<vector>
#include<iostream>
#include"bitmap.h"
#include<string>
using namespace std;
string getinput(); //gets user input for new pictures.

Pixel colorcomposite(vector <vector < vector < Pixel > > >,int,int,int); //returns a pixel that is the sum building a new picture.

bool samesize(vector < vector < Pixel > >, vector < vector < Pixel > >); //validates that 2 images are the same size.



int MAX_PICTURES = 10;

int main()
{ 
        string input;
        Bitmap image;
        string newinput;
        vector<string> pictures;
        vector < vector < Pixel > > bmp;
        vector< vector < vector < Pixel > > > images;
        vector < vector < Pixel > > compositeImage;
        // get user input for each individual image and get pictures
        while(pictures.size()<=MAX_PICTURES && input !="DONE")
        { input = getinput();
                if(input != "DONE")
                {
                        pictures.push_back(input);
                }


        }
        for(int i=0; i<pictures.size();i++)
        { image.open(pictures[i]);
                bool validImage = image.isImage();
                if(validImage == true)
                { bmp = image.toPixelMatrix();
                        images.push_back(bmp);  
                }
        }
        for(int j=0; j<images.size();j++)
        {
                bool validsize = samesize(images[0],images[j]);
                if(validsize==false)
                { images.erase(images.begin()+j);
                        cout << "The image has the wrong dimensions! it will not be included." << endl;
                }
        }
        for(int i =0; i<images.size();i++)
        {
                for(int j=0; j<images[j].size();j++)
                {
                        for(int k=0;k<images[i][j].size();k++)
                        {   
                                

                        }
                }
        }








        return 0;
}


string getinput()
{ 
        string pictureLocation;
        cout<< "Please insert a bmp image." << endl;
        cin>>pictureLocation;
        return pictureLocation;
}
bool samesize(vector < vector < Pixel > > pic1, vector < vector < Pixel > > pic2)
{ 
        if(pic1.size()==pic2.size() && pic1[0].size() == pic2[0].size())
        { return true;
        }
        else
        { return false;
        }
}
Pixel colorcomposite(vector < vector < vector < Pixel > > > bitmap,int a,int b,int c)
{ 
        Pixel rgb;
        rgb = bitmap[a][b][c];
        return rgb;

}
