/*      < 2026-2027 >
FCAI-CU > 2nd Level > OOP > Assignment 1 > Image Filters
Section : (15,16)
Team members :
20250666 Malak Mohamed  Filters: 1]Gray scale     5]Flip       9]Merge       13]Fix natural sunlight
20250693 Merna Hany     Filters: 2]Black & White  6]Rotate     10]Detect     14]Old TV Effect
20250721 Hoda Ahmad     Filters: 3]Inverting      7]Brightness    11]Crop     15]purple effect
20251051 Alaa Sayed    Filters: 4]Frame          8] Resize      12]Blur       16]Infrared photography
*/
#include "Image_Class.h"
#include<filesystem>
using namespace std;

// 1] gray scale
void grayscale(Image& image) {
  for (int y = 0; y < image.height; ++y) {
    for (int x = 0; x < image.width; ++x) {
      unsigned char r = image.getPixel(x, y, 0);
      unsigned char g = image.getPixel(x, y, 1);
      unsigned char b = image.getPixel(x, y, 2);
      unsigned char gray = static_cast<unsigned char>(0.21 * r + 0.72 * g + 0.07 * b);
      image.setPixel(x, y, 0, gray);
      image.setPixel(x, y, 1, gray);
      image.setPixel(x, y, 2, gray);
    }
  }
}

// 2] Black & White
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

//// 5.1] Horizontal Flip
void horizontal_flip(Image& image) {
  for (int y = 0; y < image.height; ++y) {
    for (int x = 0; x < image.width / 2; ++x) {
      unsigned char r1 = image.getPixel(x, y, 0);
      unsigned char g1 = image.getPixel(x, y, 1);
      unsigned char b1 = image.getPixel(x, y, 2);
      unsigned char r2 = image.getPixel(image.width - x - 1, y, 0);
      unsigned char g2 = image.getPixel(image.width - x - 1, y, 1);
      unsigned char b2 = image.getPixel(image.width - x - 1, y, 2);
      image.setPixel(x, y, 0, r2);
      image.setPixel(x, y, 1, g2);
      image.setPixel(x, y, 2, b2);
      image.setPixel(image.width - x - 1, y, 0, r1);
      image.setPixel(image.width - x - 1, y, 1, g1);
      image.setPixel(image.width - x - 1, y, 2, b1);
    }
  }
}
//// 5.2] Vertical Flip
void vertical_flip(Image& image){
  for (int y = 0; y < image.height / 2; ++y) {
    for (int x = 0; x < image.width; ++x) {
      unsigned char r1 = image.getPixel(x, y, 0);
      unsigned char g1 = image.getPixel(x, y, 1);
      unsigned char b1 = image.getPixel(x, y, 2);
      unsigned char r2 = image.getPixel(x, image.height - y - 1, 0);
      unsigned char g2 = image.getPixel(x, image.height - y - 1, 1);
      unsigned char b2 = image.getPixel(x, image.height - y - 1, 2);
      image.setPixel(x, y, 0, r2);
      image.setPixel(x, y, 1, g2);
      image.setPixel(x, y, 2, b2);
      image.setPixel(x, image.height - y - 1, 0, r1);
      image.setPixel(x, image.height - y - 1, 1, g1);
      image.setPixel(x, image.height - y - 1, 2, b1);
    }
  }
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
//// 10 detect image edges
void detectEdges(Image& image){
  Image result(image.width, image.height);
  int Gx[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
  };
  int Gy[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
  };
  for (int y = 0; y < image.height; y++) {
    for (int x = 0; x < image.width; x++) {
      int r = image.getPixel(x, y, 0);
      int g = image.getPixel(x, y, 1);
      int b = image.getPixel(x, y, 2);
      int gray = 0.299 * r + 0.587 * g + 0.114 * b;
      image.setPixel(x, y, 0, gray);
      image.setPixel(x, y, 1, gray);
      image.setPixel(x, y, 2, gray);
    }
  }
  int threshold = 100;
  for (int y = 1; y < image.height - 1; y++) {
    for (int x = 1; x < image.width - 1; x++) {       {
      int sumX = 0;
      int sumY = 0;
      for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
          int val = image.getPixel(x + i, y + j, 0);
          sumX += val * Gx[j + 1][i + 1];
          sumY += val * Gy[j + 1][i + 1];
        }
      }
      int magnitude = sqrt(sumX * sumX + sumY * sumY);
      int color = (magnitude > threshold) ? 0 : 255;
      result.setPixel(x, y, 0, color);
      result.setPixel(x, y, 1, color);
      result.setPixel(x, y, 2, color);
    }
  }
  for (int x = 0; x < image.width; x++) {
    for (int c = 0; c < 3; c++) {
      result.setPixel(x, 0, c, 255);
      result.setPixel(x, image.height - 1, c, 255);
    }
  }
  for (int y = 0; y < image.height; y++) {
    for (int c = 0; c < 3; c++) {
      result.setPixel(0, y, c, 255);
      result.setPixel(image.width - 1, y, c, 255);
    }
  }
  image = result;
}
//// 11] Crop
void crop(Image& image){
  int x,y,w,h;
  cout<<"=Detect starting point (x,y) [will be upper left corner]";
  cout<<"\n (x) coordinate: ";
  cin >> x;
  cout<<" (y) coordinate: ";
  cin >> y;
  cout<<"=New dimensions: ";
  cout<<"\n Width: ";
  cin >> w;
  cout<<" Hight: ";
  cin >> h;
  Image cropped(w,h);
  for(int r = 0; r < w; r++ ){
    for(int c = 0; c < h; c++ ){
      for(int N=0; N<3; N++){
        cropped(r ,c ,N) = image(r+x,c+y,N);
      }
    }
  }
  image = cropped;
}

//// 15] Purple
void purple(Image& image){
  for(int r=0; r < image.width; r++ ){
    for(int c=0; c < image.height; c++ ){
      image(r,c,1) = 40;
    }
  }
}

int main()
{
string photo;
int choice;
string answer;
cout<<"             >> Welcome to <PixelLab> Photo Editor! <<\n\n";
cout<<" Enter Image's Name [with extension]: ";
cin>>photo;
Image image(photo);
Image tempimage;
string tempphoto = "tempphoto.jpg";

cout<<"\n                          ~< Filters List >~            \n\n";
cout<<"                    1] Gray scale       2] Black & White  \n";
cout<<"                    3] Invert colors    4] Frame          \n";
cout<<"                    5] Flip             6] Rotate         \n";
cout<<"                    7] Brightness       8] Resize         \n";
cout<<"                    9] Merge           10] detect Edges   \n";
cout<<"                   11] Crop            12] Blur           \n";
cout<<"                   13] sunlight        14] TV effect      \n";
cout<<"                   15] Purple          16] Infrared       \n";
cout<<"                   17] Skew            18] Oil paint      \n\n";

do {
  cout<<" chose Filter's number: ";
  cin >> choice;
  switch (choice) {
  case 1:
      grayscale(image);
      break;
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
      int M;
      cout<< " 1] Horizontal flip   2] Vertical flip\n ";
      cin >> M;
      M == 1? horizontal_flip(image) : vertical_flip(image) ;
      break;
  case 6:
      Rotate(image);
      break;
  case 7:
      brightness(image);
      break;
  case 8:
      Resize(image);
      break;
  case  9:
  case 10:
      detectEdges(image);
      break;
  case 11:
      crop(image);
      break;
  case 12:
  case 13:
  case 14:
  case 15:
      purple(image);
      break;
  case 16:
  case 17:
  case 18:
  default:
      cout<< "=>Invalid choice!\n ";
      break;
  }
  choice = 0;

//saving

  tempimage = image;
  tempimage.saveImage(tempphoto);
  system(tempphoto.c_str());
  cout << " Do you want to apply another filter?\n ";
  cin >> answer;
  remove("tempphoto.jpg");
}
while ( answer[0] == 'y' || answer[0] == 'Y');
  
cout<<" Do you want to save as a copy ?\n ";
cin >> answer;
if( answer[0] == 'y' || answer[0] == 'Y'){
  string newphoto;
  cout<<"\n Enter New Image Name [with wanted extension]: ";
  cin >>newphoto;
  image.saveImage(newphoto);
}
else image.saveImage(photo);
  
  
cout << "\n >> Image saved successfully! "<<endl;
cout << "\n                << Thank you for using our program! >>\n" << endl;
return 0;
}
