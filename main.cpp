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
      image(r,c,0)=255-image(r,c,1);
      image(r,c,0)=255-image(r,c,2);
    }
  }
}
int main()
{
  string photo;
  int n;

  //Menu

  cin>>photo;
  cin>>n;

  Image image(photo);
  switch(n){
  case 1:
  case 2:
  case 3:invert(image);           break;
  //case 4:
  //case 5:
  //case 6:
  //case 7:
  //case 8:
  default:cout<<"No such a choice";break;
  }


//saving(need optimization)
  string newphoto;
  cin>>newphoto;
  image.saveImage(newphoto);
  system(newphoto.c_str());
    return 0;
}