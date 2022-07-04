#include <iostream>
#include <fstream>
#include "bitmap.h"

void build_bmp(std::string _file,
			   int _w,
			   int _h,
			   char *_image)
{
        int width = _w; //图片宽度
        int height = _h; //图片高度
        std::ofstream outFile(_file.c_str(), std::ios::binary); //创建图片文件
        BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader; //以下为图片文件赋值
	bmpInfoHeader.biSize = sizeof(BITMAPINFOHEADER); 
	bmpInfoHeader.biWidth = width;
	bmpInfoHeader.biHeight = height;
	bmpInfoHeader.biPlanes = 1;
	bmpInfoHeader.biBitCount = 24;
	bmpInfoHeader.biCompression = 0;
	bmpInfoHeader.biSizeImage = width * height * 3; //图片总大小
	bmpInfoHeader.biXPelsPerMeter = 2834;
	bmpInfoHeader.biYPelsPerMeter = 2834;
	bmpInfoHeader.biClrUsed = 0;
	bmpInfoHeader.biClrImportant = 0;

	((char*)(&bmpFileHeader.bfType))[0] = 'B';
	((char*)(&bmpFileHeader.bfType))[1] = 'M';
	bmpFileHeader.bfReserved1 = 0;
	bmpFileHeader.bfReserved2 = 0;
	bmpFileHeader.bfOffBits = bmpInfoHeader.biSize + sizeof(BITMAPFILEHEADER);
	bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + bmpInfoHeader.biSizeImage;

	outFile.write(reinterpret_cast<char*>(&bmpFileHeader), sizeof(BITMAPFILEHEADER));
	outFile.write(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(BITMAPINFOHEADER));

	// char *cache = new char[bmpInfoHeader.biSizeImage];

	// for (int j = 0; j < height; j++)
	// 	for (int i = 0; i < width; i++)
	// 	{
	// 		int pos = j * width + i;
	// 		cache[pos * 3] = 0;
	// 		cache[pos * 3 + 1] = 0;
	// 		cache[pos * 3 + 2] = 255;
	// 	}
	outFile.write(_image, bmpInfoHeader.biSizeImage);
	//	delete [] cache;
	outFile.close(); //图片文件创建结束
};

