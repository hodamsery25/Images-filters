#include "Image_Class.h"
#include<filesystem>
using namespace std;

// filter 2
void Black_White (Image& image) {
  for (int i=0; i < image.width; ++i) {
    for (int j=0; j < image.height; ++j) {
      unsigned char r = image.getPixel(i, j, 0);
      unsigned char g = image.getPixel(i, j, 1);
      unsigned char b = image.getPixel(i, j, 2);
      int avg = (r+g+b)/3;
      unsigned char newValue = (avg >= 128 ? 255:0);
      image.setPixel(i, j, 0, newValue);
      image.setPixel(i, j, 1, newValue);
      image.setPixel(i, j, 2, newValue);
    }
  }
}

// 3] Inverting
void invert(Image& image){
  for(int r=0; r < image.width; r++ ){
    for(int c=0; c < image.height; c++ ){
      image(r,c,0)=255-image(r,c,0);
      image(r,c,1)=255-image(r,c,1);
      image(r,c,2)=255-image(r,c,2);
    }
  }
}

////4] Frame
void frame (Image& image){
  int m,s ;
  cout<< " 1]Thin  2]Thick \n ";
  cin >> m;
  s = (m==1 ? 20:50 );
  Image fr (image.width + 2*s ,image.height + 2*s);
  for(int r=0; r < fr.width; r++ ){
    for(int c=0; c < fr.height; c++ ){
      for(int N=0; N<3; N++){
        fr(r,c,N) = 0;
      }
    }
  }
  for (int x=0; x < image.width ; x++){
    for (int y=0; y < image.height ; y++){
      for(int N=0; N<3; N++){
        fr(x+s,y+s,N) = image(x,y,N);
      }
    }
  }
  image = fr;
}

//// 6] Rotation
void Rotate (Image& image){
  int angle;
  cout << " Enter rotation angle [90-180-270]: ";
  cin >> angle;
  if (angle == 90) {
    Image rotated(image.height, image.width);
    for (int x = 0; x < image.width; ++x) {
      for (int y = 0; y < image.height; ++y) {
        for (int c = 0; c < 3; ++c) {
          rotated ( y, image.width - 1 - x , c ) = image (x, y, c);
        }
      }
    }
    image = rotated;
  }
  else if (angle == 180) {
    Image rotated(image.width, image.height);
    for (int x = 0; x < image.width; ++x) {
      for (int y = 0; y < image.height; ++y) {
        for (int c = 0; c < 3; ++c) {
          rotated (image.width - 1 - x, image.height - 1 - y, c) = image(x, y, c);
        }
      }
    }
    image = rotated;
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
    image = rotated;
  }
  else   cout << "=>Invalid angle! \n ";
}

//// 7] Brightness
void brightness (Image& image){
  int M;
  float v;
  cout<< " 1] Increase Brightness   2]: Decrease Brightness\n ";
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
 //// 8] Resize
void Resize (Image& image){
  int w,h;
  cout <<" Original dimensions: [" << image.width << "x" << image.height <<"]"<< endl;
  cout <<" New width : ";
  cin >> w;
  cout <<" New height : ";
  cin >> h;
  Image resized(w,h);
  for (int x=0; x<w; x++){
    for (int y=0; y<h; y++){
      int X = x*image.width/w;
      int Y = y*image.height/h;
      for (int c=0; c<3; c++){
        resized(x, y, c) = image(X, Y, c);
      }
    }
  }
  image = resized;
}

int main()
{
string photo;
int choice;
string answer;
cout<<" Enter Image's Name [with extension]: ";
cin>>photo;
Image image(photo);
Image tempimage;//for saving
string tempphoto = "tempphoto.jpg";
do {
  //Menu

  cout<<" chose Filter's number: ";
  cin >> choice;
  switch (choice) {
  case 1:
  case 2:
      Black_White(image);
      break;
  case 3:
      invert(image);
      break;
  case 4:
      frame(image);
      break;
  case 5:
  case 6:
      Rotate(image);
      break;
  case 7:
      brightness(image);
      break;
  case 8:
      Resize(image);
      break;
  default:
      cout<< "=>Invalid choice!\n ";
      break;
  }
  choice = 0;

//saving

  tempimage = image;
  tempimage.saveImage(tempphoto);
  system(tempphoto.c_str());
  remove("tempphoto.jpg");
  cout << " Do you want to apply another filter?\n ";
  cin >> answer;
}
while ( answer[0] == 'y' || answer[0] == 'Y');
//final saving
string newphoto;
cout<<" Enter Modified Image Name [with wanted extension]: ";
cin>>newphoto;
image.saveImage(newphoto);
cout << "\n >> Modified Image saved successfully! "<<endl;
cout << "\n << Thank you for using our program! >>\n" << endl;
return 0;
}
