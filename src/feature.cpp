#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


int main() 
{

	std::string img_path = "../data/im3.jpg";
	cv::Mat img = cv::imread(img_path, cv::IMREAD_COLOR);

	if (img.empty())
	{
		std::cout << "Could not read the image: " << img_path << std::endl;
		return 1;
	}


	cv::imshow("Display", img);
	int k = cv::waitKey(0);

	return 0;
}
