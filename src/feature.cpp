#include <iostream>
/*
#include <opencv2/core.hpp>				// core functionality
#include <opencv2/imgcodecs.hpp>		// img file reading/writing (imread, imwrite)
#include <opencv2/highgui.hpp>			// GUI functions (imshow, waitKey)
*/

#include <opencv2/opencv.hpp>			// catches all the above and more includes


int main() 
{

	std::string img_path = "../data/im3.jpg";
	cv::Mat img = cv::imread(img_path, cv::IMREAD_GRAYSCALE);

	if (img.empty())
	{
		std::cout << "Could not read the image: " << img_path << std::endl;
		return 1;
	}


	// Creating ORB detector
	cv::Ptr<cv::ORB> orb = cv::ORB::create();

	// Detect keypoints
	std::vector<cv::KeyPoint> keypoints;
	orb->detect(img, keypoints);

	// Compute descriptors
	cv::Mat descriptors;		
	orb->compute(img, keypoints, descriptors);

	// Drawing keypoint on objects
	cv::Mat img_with_kps;
	cv::drawKeypoints(img, keypoints, cv::Scalar::all(-1));

	cv::imshow("ORB Keypoints", img_with_kps);
	int k = cv::waitKey(0);

	return 0;
}
