/*Welcome team
this is the main repo, we will add filters & menu HERE,
this massage will be deleted at last step*/

#include"Image_Class.h"

using namespace std;

int main()
{
  string photo;
  cin>>photo;
  Image image(photo);



//Invertion
  for(int r=0; r<image.width; r++ ){
    for(int c=0; c<image.height; c++ ){
      image(r,c,0)=255-image(r,c,0);
      image(r,c,0)=255-image(r,c,1);
      image(r,c,0)=255-image(r,c,2);
    }
  }


//saving(need optimization)
  image.saveImage(photo);
  system(photo.c_str());
    return 0;
}
