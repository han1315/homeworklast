#include <iostream>
#include <cstdlib>
#include "Window.h"
#include "Julia.h"
#include "bitmap.h"

int main(int argc, char *argv[])
{
    if (argc < 5) //当输入参数不足时，发出提醒
	{
		std::cerr << "Usage: " << argv[0]
				  << " filename complex_real complex_imaginay max_iteration_time" << std::endl;
		exit(-1);
	}
	
    Window win(0.0, 0.0, 3.0);
	double lpp = win.get_lpp();
	double dim = win.get_dimension();
	int width = win.get_width();
	int height = win.get_height();
	double ox = win.get_ox() - dim;
	double oy = win.get_oy() - dim / width * height;
	int N = std::atof(argv[4]);

	char *cache = new char[width * height * 3]; //画图

	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			double x = ox + lpp * i;
			double y = oy + lpp * j;
			int pos = width * j + i; 
		        Julia man(std::complex<double>{x,y},
						   N,
				  std::complex<double>{std::atof(argv[2]),std::atof(argv[3])});
			while (!man.stop_criterion()) //但未达到最大值时且未达到最大迭代次数时，执行循环，当达到最大迭代次数或最大值时，循环结束
			{
				man.forward_step();
				if (man.is_disconvergence())
					break;
			}
			if (man.stop_criterion()) //当函数值超过最大值后，将点列染成白色
			{
				cache[pos * 3] = 255;
				cache[pos * 3 + 1] = 255;
				cache[pos * 3 + 2] = 255;
			}
			else //当函数达到最大迭代次数时，将点列染成黑色
			{
				cache[pos * 3] = 0;
				cache[pos * 3 + 1] = 0;
				cache[pos * 3 + 2] = 0;
			}
		}
	build_bmp(argv[1], width, height, cache); //创建bmp图片文件
	delete [] cache; 
	return 0;
};
