__kernel void test(__global int *pixel, float shift_x, float shift_y, float zoom,
    int type, float j_re, float j_im, int max_i, float color)
{
	int		gid = get_global_id(0);
	float	c_re;
	float	c_im;
	float	z_re;
	float	z_im;
	float   tmp;
	int		i;
	int		r;
	int		g;
	int		b;
	float	t;

	c_im = shift_y + (float)(gid / 1001) / zoom;
	c_re = shift_x + (float)(gid % 1001) / zoom;
	z_re = 0;
	z_im = 0;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < max_i)
	{
		if (type == 1)
		{
		    tmp = z_re * z_re - z_im * z_im + j_re;
			z_im = 2.0 * z_re * z_im + j_im;
			z_re = tmp;
		}
		else if (type == 2)
		{
			tmp = z_re * z_re - z_im * z_im + c_re;
			z_im = 2.0 * z_re * z_im + c_im;
			z_re = tmp;
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
	t = color + (float)i / (float)max_i;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	pixel[gid] = ((r << 16) | (g << 8) | b);
}

