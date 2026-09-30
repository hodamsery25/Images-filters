/*Welcome team
this is the main repo, we will add filters & menu HERE,
this massage will be deleted at last step*/

#include"Image_Class.h"
#include "filter.h" 
 

using namespace std;

int main()
{
  string photo;
  cin>>photo;
  Image image(photo);

  modify_grayscale_filter(image); 
  



//saving(need optimization)
  image.saveImage(photo);
  system(photo.c_str());
    return 0;
}
