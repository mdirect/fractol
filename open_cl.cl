__kernel void test(__global int *pixel)
{
    int             gid = get_global_id(0);

    int				i;
    double          z_re;
    double          z_im;
    double          c_re;
    double          c_im;
    int		        r;
    int		        g;
    int		        b;
    double	        t;

    c_re = -2.0 + ((double)(gid % 1001) / 250.0);
    c_im = -2.0 + ((double)(gid / 1001) / 250.0);
    z_re = c_re;
    z_im = c_im;
    i = 0;
    while (z_re * z_re + z_im * z_im <= 4 && i < 500)
    {
        z_re = z_re * z_re - z_im * z_im + c_re;
        z_im = 2.0 * z_re * z_im + c_im;
        i++;
    }
    t = (double)i / (double)500;
    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    pixel[gid] = ((r << 16) | (g << 8) | b);
}

