__kernel void	test(__global int *pixel, double shift_x, double shift_y, double zoom, int type, double j_re, double j_im, int max_i, double color)
{
	int		gid = get_global_id(0);
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		i;
	int		r;
	int		g;
	int		b;
	double	t;

	c_im = shift_y + (double)(gid / 1001) / zoom;
	c_re = shift_x + (double)(gid % 1001) / zoom;
	z_re = c_re;
	z_im = c_im;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < max_i)
	{
		if (type == 1)
		{
			z_re = z_re * z_re - z_im * z_im + j_re;
			z_im = 2.0 * z_re * z_im + j_im;
		}
		else if (type == 2)
		{
			z_re = z_re * z_re - z_im * z_im + c_re;
			z_im = 2.0 * z_re * z_im + c_im;
		}				
		else if (type == 3)
		{
			z_re = z_re * z_re * z_re - 3 * z_re * z_im * z_im + c_re;
			z_im = 3 * z_re * z_re * z_im - z_im * z_im * z_im + c_im;
		}
		else if (type == 4)
		{
			z_re = z_re * z_re * z_re * z_re - 6 * z_re * z_re * z_im * z_im + z_im * z_im * z_im * z_im + c_re;
			z_im = 4 * z_re * z_re * z_re * z_im - 4 * z_re * z_im * z_im * z_im + c_im;
		}
		else if (type == 5)
		{
			z_re = z_re * z_re * z_re * z_re * z_re - 10 * z_re * z_re * z_re * z_im * z_im + 5 * z_re * z_im * z_im * z_im * z_im + c_re;
			z_im = 5 * z_re * z_re * z_re * z_re * z_im - 10 * z_re * z_re * z_im * z_im * z_im + z_im * z_im * z_im * z_im * z_im + c_im;
		}
		else if (type == 6)
		{
			z_re = fabs(z_re * z_re - z_im * z_im) + c_re;
			z_im = 2.0 * z_re * z_im + c_im;
		}
		else if (type == 7)
		{
			z_re = z_re * z_re - z_im * z_im + c_re;
			z_im = 2.0 * fabs(z_re * z_im) + c_im;
		}
		else if (type == 8)
		{
			z_re = z_re * z_re - z_im * z_im + c_re;
			z_im = -2.0 * z_re * z_im + c_im;
		}
		i++;
	}
	t = color + (double)i / (double)max_i;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	pixel[gid] = ((r << 16) | (g << 8) | b);
}