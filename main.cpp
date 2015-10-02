//
//  main.cpp
//  OpenCV test
//
//  Created by Chris Bloomfield on 30/09/15.
//  Copyright © 2015 Chris Bloomfield. All rights reserved.
//


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat image;
int red;
int blue;
int green;

static void onMouse( int event, int x, int y, int, void* )
{
    if( event != EVENT_LBUTTONDOWN )
        return;
    
    red = image.at<cv::Vec3b>(y,x)[0];
    blue = image.at<cv::Vec3b>(y,x)[1];
    green = image.at<cv::Vec3b>(y,x)[2];

    
}


int main()
{
    
    image = imread("house_2.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
    
    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.
    
    setMouseCallback( "Display window", onMouse);
    
    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
