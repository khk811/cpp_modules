#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float	a_x = a.getPointX();
	float	a_y = a.getPointY();
	float	b_x = b.getPointX();
	float	b_y = b.getPointY();
	float	c_x = c.getPointX();
	float	c_y = c.getPointY();
	float	p_x = point.getPointX();
	float	p_y = point.getPointY();

	std::cout << "[" << point.getPointX() << "]" << std::endl;
	std::cout << "[" << p_y << "]" << std::endl;
	float alpha = ((b_y - c_y)*(p_x - c_x) + (c_x - b_x)*(p_y - c_y)) /
				((b_y - c_y)*(a_x - c_x) + (c_x - b_x)*(a_y - c_y));
	float beta = ((c_y - a_y)*(p_x - c_x) + (a_x - c_x)*(p_y - c_y)) /
				((b_y - c_y)*(a_x - c_x) + (c_x - b_x)*(a_y - c_y));
	float gamma = 1.0f - (alpha + beta);

	std::cout << "{" << alpha + beta << "}" << std::endl;
	std::cout << "(" << alpha << ")" << std::endl;
	std::cout << "(" << beta << ")" << std::endl;
	std::cout << "(" << gamma << ")" << std::endl;
	if (alpha > 0 && beta > 0 && gamma > 0)
		return true;
	else
		return false;
}
