/*Welcome team
this is the main repo, we will add filters & menu HERE,
this massage will be deleted at last step*/

#include"Image_Class.h"

using namespace std;

//Invertion
void invert(Image& image){
  for(int r=0; r<image.width; r++ ){
    for(int c=0; c<image.height; c++ ){
      image(r,c,0)=255-image(r,c,0);
      image(r,c,1)=255-image(r,c,1);
      image(r,c,2)=255-image(r,c,2);
    }
  }
}
//Brightness
void brightness(Image& image){
  int M;
  float v;
  cout<< "\n 1] increase Brightness   2]: decrease Brightness\n ";
  cin >> M;
  cout<< " Enter the percentage [0~300%]: ";
  cin >> v;
 // cout<<v<<"  ";
  v = v/100+1 ;   if(M==2) v = 1/v;
  //cout<<v;
  for(int r=0; r<image.width; r++ ){
    for(int c=0; c<image.height; c++ ){
      for(int N=0; N<3; N++){
        if( image(r,c,N)*v > 255 ) image(r,c,N)=255;
        else
           image(r,c,N)*= v ;
      }
    }
  }
}
int main()
{
  string photo;
  int choice;

  //Menu

  cin>>photo;
  cin>>choice;
  Image image(photo);
  switch(choice){
  case 1:
  case 2:
  case 3:
      invert(image);
      break;
  //case 4:
  //case 5:
  //case
  case 7:
      brightness(image);
      break;
  //case 8:
  default:
      cout<< "Invalid choice!\n";
      break;
  }


//saving
  string newphoto;
  cin>>newphoto;
  image.saveImage(newphoto);
  system(newphoto.c_str());
    return 0;
}
