/*Welcome team
this is the main repo, we will add filters & menu HERE,
this massage will be deleted at last step*/

#include"Image_Class.h"
#include "filter.h" // Include your filter header so main knows about your function
#include <iostream>



using namespace std;

int main()
{
  string photo;
  cin>>photo;
  Image image(photo);

 int choice;
    cout << "Choose a filter:\n";
    cout << "1. grayscale\n"; // Put your filter option here
    // Other team members' filters will go here as they push them
    cin >> choice;

    switch (choice) {
        case 1: // Change this to your assigned case number
            modify_grayscale_filter(image);
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
 
  

//saving(need optimization)
  image.saveImage(photo);
  system(photo.c_str());
    return 0;
}
