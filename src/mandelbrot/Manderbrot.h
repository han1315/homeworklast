#include <complex>

class Iteration
{
protected:
        std::complex<double> iteration_point{0.0, 0.0}; //定义复数初始二维点位
	int iteration_times = 0; //定义迭代次数 
	int max_iteration = 20; //定义最大迭代次数
	std::complex<double> iteration_const{0.0, 0.0}; //定义复数二维参数
	bool flag_stop = false; 
	bool flag_disconvergence = false;
public:
	Iteration(){}; //无需赋予参数迭代函数
        Iteration(std::complex<double> _ip,
			  int _max_it,
			  std::complex<double> _ic) :
		    iteration_point(_ip),
		    max_iteration(_max_it),
		    iteration_const(_ic) {}; /*调用函数需要赋予参数（参数1：二维点位，参数2：最大迭代次数，参数3：二维参数），当参数为复数时调用*/
	Iteration(double _ix,
			  double _iy,
			  int _max_it,
			  double _cx,
			  double _cy) :
		iteration_point(std::complex<double>{_ix, _iy}),
		max_iteration(_max_it),
		    iteration_const(std::complex<double>{_cx, _cy}) {}; /*调用函数需要赋予参数（参数1：二维点位，参数2：最大迭代次数，参数3：二维参数），当参数为常数时调用*/
	std::complex<double> get_iteration_point() //当用户想查看初始点位时调用
	{
		return iteration_point;
	};
	int get_iteration_times() //当用户想查看迭代次数时调用
	{
		return iteration_times;
	};
	std::complex<double> get_iteration_const() //当用户想查看参数时调用
	{
		return iteration_const;
	};
	int get_max_iteration() //当用户想查看最大迭代次数时调用
	{
		return max_iteration;
	};
	virtual void forward_step() = 0; //迭代函数赋初值
	virtual bool stop_criterion() = 0; //赋值给判断函数，用于当函数值达最大值时，迭代停止
	virtual bool is_disconvergence() = 0;  //赋值给判断函数，用于当函数迭代次数达最大值时，迭代停止
};

class Manderbrot : public Iteration
{
public:
	Manderbrot() : Iteration() {}; //无需赋予参数迭代函数
	Manderbrot(std::complex<double> _ip,
			   int _max_it,
			   std::complex<double> _ic) : Iteration(_ip, _max_it, _ic) {}; /*调用函数需要赋予参数，并将参数赋值到Iteration*/
	Manderbrot(double _ix,
			   double _iy,
			   int _max_it,
			   double _cx,
			   double _cy) : Iteration(_ix, _iy, _max_it, _cx, _cy) {}; /*调用函数需要赋予参数，并将参数赋值到Iteration*/
	virtual void forward_step();
	virtual bool stop_criterion();
	virtual bool is_disconvergence();
};

void Manderbrot::forward_step() //迭代函数
{
        iteration_point = iteration_point * iteration_point + iteration_const; //公式
	iteration_times++; //计算迭代次数
	if (iteration_times == max_iteration) //当迭代次数达到最大值时，迭代终止
	        flag_disconvergence = true; 
	if (std::abs(iteration_point) > 2.0) //当函数值达最大值时，迭代停止,abs是绝对值函数
	        flag_stop = true; //
};

bool Manderbrot::stop_criterion()
{
	return flag_stop;
};
bool Manderbrot::is_disconvergence()
{
	return flag_disconvergence; 
};
