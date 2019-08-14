#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap; //Cria a variável cap do tipo VideoCapture (Classe usada para captura de videos/imagens da web cam ou de um arquivo).

	if (!cap.open(0)) //Se a câmera não abrir, termina o programa.
		return 0;

	for (;;)
	{
		Mat frame; //Cria a variável frame do tipo Mat (Matriz para guardar vários tipos de variáveis, ex: números, cores)
		cap >> frame; //Captura os frames pela webcam

		if (frame.empty()) break; // end of video stream

		Mat img(650, 600, CV_16UC3, Scalar(0, 50000, 50000)); //create an image ( 3 channels, 16 bit image depth, 650 high, 600 wide, (0, 50000, 50000) assigned for Blue, Green and Red plane respectively. )

		if (img.empty()) //check whether the image is loaded or not
		{
			cout << "ERROR : Image cannot be loaded..!!" << endl;
			//system("pause"); //wait for a key press
			return -1;
		}
		img = frame;

		vector<int> compression_params; //vector that stores the compression parameters of the image

		compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

		compression_params.push_back(98); //specify the compression quality

		bool bSuccess = imwrite("D:/TestImage.jpg", img, compression_params); //write the image to file

		namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);

		imshow("MyWindow", img);
		
		waitKey(0);

		destroyWindow("MyWindow");

		//if (waitKey(1) == 27) break;

		//cap.release();
	}
	// the camera will be closed automatically upon exit
	
	return 0;
}