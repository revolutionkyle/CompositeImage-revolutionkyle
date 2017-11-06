#include<vector>
#include<string>
#include<iostream>
#include "bitmap.h"

using namespace std;
string getinput(vector<string>); //gets user input for new picture locations.
char newpicture(); //asks the user whether or not they want to add a new picture to the composite image.
int redcomposite(vector <vector< vector< pixels > > >); //gets the sum of the red color values for all picture
int bluecomposite(vector <vector< vector< pixels > > >); // gets the sume of blue color values for all picture.
int greencomposite(vector <vector< vector< pixels > > >); // gets sum of green color values for all picture
const int MAX_PICTURES = 10;

int main()
{ string image;
  bool validImage = image.isImage();
  char newinput;
  vector<string> pictures;
  vector< vector < vector < pixels > > > images;
      //Get users input for each individual image and set up a loop for getting all their pictures.
      while(pictures.size<=MAX_PICTURES && (newpicture=='Y' || newpicture=='y'))
      { string Location;
        getinput();
        Location = getinput();
               
        // validate each image seperately and store such images as a vector of vectors
        Location.isImage();
        if(Location.isImage == "true")
        { pictures.push_back(Location);
        }
        else
        { newpicture = 'Y'
        }
        // allow user to keep inserting new pictures but force them to stop after 10.
        if(newpicture !=='Y')
        { newpicture()
        }
       }
      for(int i=0; i<pictures.size(); i++)
      { 
        image.open(pictures[i]);
        image.toPixelMatrix(pictures[i]) = image;
        images.push_back(pictures[i]);
      }



      //take the average of each of the red, blue, green colors of each individual picture
      


      //create a new image, that has the average of each color at each pixel.



      //save the image as "composite-revolutionkyle."



return 0;     
}
string getinput();
{ string pictureLocation;
  cout<<"Please insert a valid bmp image." << endl;
  cin>>pictureLocation;
  return pictureLocation;
}
char newpicture()
{ cout << "Would you like to insert another picture? Y/N" << endl;
  cin>>newpicture;
  return newpicture;
}
