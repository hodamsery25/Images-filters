/*Welcome team
this is the main repo, we will add filters & menu HERE,
this massage will be deleted at last step*/
#include"Image_Class.h"
using namespace std;

// filter 2
void Black&White(Image& image) {
  for (int i = 0; i < image.width; ++i) {
    for (int j = 0; j < image.height; ++j) {
      unsigned char r = image.getPixel(i, j, 0);
      unsigned char g = image.getPixel(i, j, 1);
      unsigned char b = image.getPixel(i, j, 2);
      int avg = (r + g + b) / 3;
      unsigned char newValue = (avg >= 128) ? 255 : 0;
      image.setPixel(i, j, 0, newValue);
      image.setPixel(i, j, 1, newValue);
      image.setPixel(i, j, 2, newValue);
    }
  }
}
// 3] Invertion
void invert(Image& image){
  for(int r=0; r<image.width; r++ ){
    for(int c=0; c<image.height; c++ ){
      image(r,c,0)=255-image(r,c,0);
      image(r,c,1)=255-image(r,c,1);
      image(r,c,2)=255-image(r,c,2);
    }
  }
}


// 6] Rotation
void Rotation (Image& image)
  int angle;
  cout << " Enter rotation angle [90-180-270]: ";
  cin >> angle;
  if (angle == 90) {
    Image rotated(image.height, image.width);
    for (int x = 0; x < image.width; ++x) {
      for (int y = 0; y < image.height; ++y) {
        for (int c = 0; c < 3; ++c) {
          rotated(y, image.width - 1 - x, c) = image(x, y, c);
        }
      }
    }
    cout << "Image rotated 90 degrees successfully!\n";
  } 
  else if (angle == 180) {
    Image rotated(image.width, image.height);
    for (int x = 0; x < image.width; ++x) {
      for (int y = 0; y < image.height; ++y) {
        for (int c = 0; c < 3; ++c) {
          rotated(image.width - 1 - x, image.height - 1 - y, c) = image(x, y, c);
        }
      }
    }
    cout << "Image rotated 180 degrees successfully!\n";
  } 
else if (angle == 270) {
  Image rotated(image.height, image.width);
  for (int x = 0; x < image.width; ++x) {
    for (int y = 0; y < image.height; ++y) {
      for (int c = 0; c < 3; ++c) {
        rotated(image.height - 1 - y, x, c) = image(x, y, c);
      }
    }
  }
  cout << "Image rotated 270 degrees successfully!\n"; 
else   cout << "Invalid angle! Please enter 90, 180, or 270.\n";


// 7] Brightness
void brightness(Image& image){
  int M;
  float v;
  cout<< " 1] increase Brightness   2]: decrease Brightness\n ";
  cin >> M;
  cout<< " Enter the percentage [0~300%]: ";
  cin >> v;
  v = v/100+1 ;   if(M==2) v = 1/v;
  for(int r=0; r<image.width; r++ ){
    for(int c=0; c<image.height; c++ ){
      for(int N=0; N<3; N++){
        if( image(r,c,N)*v > 255 ) image(r,c,N)=255;
        else image(r,c,N)*= v ;
      }
    }
  }
}


int main()
{
  string photo;
  int choice;

  cout<<" Enter Image's Name [with extention]: ";
  cin>>photo;
  
  //Menu
  
  cout<<" chose Filter's number: ";
  cin>>choice;
  Image image(photo);
  switch(choice){
  case 1:
  case 2:
      Black&White(image);
      break;
  case 3:
      invert(image);
      break;
  case 4:
  case 5:
  case 6:
  case 7:
      brightness(image);
      break;
  case 8:
  default:
      cout<< "=>Invalid choice!\n";
      break;
  }


//saving
  string newphoto;
  cout<<" Modifed Image's Name [with wanted extevtion]: "
  cin>>newphoto;
  image.saveImage(newphoto);
  system(newphoto.c_str());
  cout << " thank you." << endl;
    return 0;
}

////////////////////////while loop
 /* 
    cout << "do you want to apply another filter? (y/n): ";
    char choice;
    cin >> choice;

    while (choice == 'y' || choice == 'Y') {
        cout << "Enter input image filename: ";
        cin >> inputFilename;
        Image newImage(inputFilename);
/////
        cout << "Enter output image filename: ";
        cin >> outputFilename;
        newImage.saveImage(outputFilename);
        cout << "do you want to apply another filter? (y/n): ";
        cin >> choice;
    }    */
