struct Point2d //二维点坐标
{
	double x;
	double y;
};

class Window
{
private:
	Point2d origin = {0.0, 0.0}; //赋值二维点坐标
	double dimension = 5.0; //赋值尺寸
	int height = 1080; //赋值高度
	int width = 1920; //赋值宽度
public:
	Window(){};
	Window(double _ox, double _oy, double _d) //获取二维点坐、尺寸
	{
		origin.x = _ox;
		origin.y = _oy;
		dimension = _d;
	};

	double get_dimension() {return dimension;}; //当用户想查看图片尺寸时调用
	double get_height() {return height;}; //当用户想查看图片高度时调用
	double get_width() {return width;}; //当用户想查看图片宽度时调用
	double get_ox() {return origin.x;}; //当用户想查看点坐标时调用
	double get_oy() {return origin.y;}; //当用户想查看点坐标时调用
	double get_lpp() //当用户想查看网格在复平面的宽度时调用
	{
		return (dimension * 2.0 / width);
	};
};
