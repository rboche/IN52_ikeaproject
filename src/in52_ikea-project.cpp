#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int main(int argc, const char * argv[]){

	cv::Mat img = cv::imread("C:\\Users\\Rémi\\Documents\\in\\img\\imagetest.jpg");
	if(!img.data){
		std::cout << "Image file not found\n";
		return 1;
	}
/*
	cv::cvtColor(img, img, CV_BGR2GRAY);
	cv::threshold(img, img, 128, 255, CV_THRESH_BINARY);


	std::vector<std::vector<cv::Point> > contours;
	cv::Mat contourOutput = img.clone();
	cv::findContours(contourOutput, contours, CV_RETR_LIST,CV_CHAIN_APPROX_NONE);



	cv::Mat contourImage(img.size(), CV_8UC3, cv::Scalar(0,0,0));
	cv::Scalar colors[3];
	colors[0] = cv::Scalar(255,0,0);
	colors[1] = cv::Scalar(0,255,0);
	colors[2] = cv::Scalar(0,0,255);
	for(size_t idx = 0; idx < contours.size(); idx++){
		cv::drawContours(contourImage,contours,idx,colors[idx % 3]);
	}

	cv::imshow("Input image", img);
	cvMoveWindow("Input image",0,0);
	cv::imshow("Contours", contourImage);
	cvMoveWindow("Contours",200,0);
	cv::waitKey(0);

	return 0;*/

	//Deuxième méthode : utilise Laplace
	//plus performante

	Mat src, gray, dst, abs_dst;
	src = img;

	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	cvtColor(src,gray,CV_RGB2GRAY);

	Laplacian(gray,dst,CV_16S,3,1,0,BORDER_DEFAULT);
	convertScaleAbs(dst,abs_dst);
	imshow("result",abs_dst);

	waitKey(0);
	return 0;



}
