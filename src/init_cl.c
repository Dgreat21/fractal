/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:57:00 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/20 12:57:03 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		*error_cl(int error_code, char *str)
{
	free(str);
	str = NULL;
	error_code = -1;
	if (error_code == 0)
		ft_putendl("\033[31mMalloc return null\033[0m");
	else if (error_code == 1)
		ft_putendl("\033[31mError in clGetPlatformIDs\033[0m");
	else if (error_code == 2)
		ft_putendl("\033[31mError in clGetDeviceIDs\033[0m");
	else if (error_code == 3)
		ft_putendl("\033[31mError in clCreateContext\033[0m");
	else if (error_code == 4)
		ft_putendl("\033[31mError in clCreateCommandQueue\033[0m");
	else if (error_code == 5)
		ft_putendl("\033[31mError in clCreateProgramWithSource\033[0m");
	else if (error_code == 6)
		ft_putendl("\033[31mError in clBuildProgram\033[0m");
	else if (error_code == 7)
		ft_putendl("\033[31mError in clCreateKernel\033[0m");
	else if (error_code == 8)
		ft_putendl("\033[31mError in clSetKernelArg\033[0m");
	else if (error_code == 9)
		ft_putendl("\033[31mError in clCreateBuffer\033[0m");
	return (NULL);
}

void			fill_arg(t_all *all, int *mem, double *dmem)
{
	mem[0] = LENGTH;
	mem[1] = WIDE;
	mem[2] = all->key;
	mem[3] = all->iter;
	mem[4] = all->color;
	mem[5] = all->pow;
	mem[6] = all->mouse;
	dmem[0] = all->maxy;
	dmem[1] = all->minx;
	dmem[2] = all->shift_y;
	dmem[3] = all->shift_x;
	dmem[4] = all->lr;
	dmem[5] = all->ud;
	dmem[6] = all->mouse_pos.x;
	dmem[7] = all->mouse_pos.y;
	dmem[8] = all->zoom;
}

char			*read__file(char *path)
{
	int			fd;
	int			number;
	char		*buff;

	fd = open(path, O_RDONLY);
	buff = (char*)malloc(sizeof(char) * 10000);
	if (fd < 2)
		exit(99);
	number = read(fd, buff, 10000);
	buff[number] = '\0';
	close(fd);
	return (buff);
}

void			*init_cl(t_all *all)
{
	int			er;
	char		*kernel_str;
	size_t		kernel_len;

	er = clGetPlatformIDs(1, &all->cl->pid, &all->cl->ret_num_platforms);
	er = clGetDeviceIDs(all->cl->pid, CL_DEVICE_TYPE_GPU, 1, &all->cl->d_id, 0);
	all->cl->cont = clCreateContext(NULL, 1, &all->cl->d_id, NULL, NULL, &er);
	all->cl->queue = clCreateCommandQueue(all->cl->cont, all->cl->d_id, 0, &er);
	kernel_str = read__file("./src/kernel.cl");
	kernel_len = ft_strlen(kernel_str);
	all->cl->program = clCreateProgramWithSource(all->cl->cont, 1,
			(const char**)&kernel_str, &kernel_len, &er);
	er = clBuildProgram(all->cl->program, 1, &all->cl->d_id, NULL, NULL, NULL);
	all->cl->kernel = clCreateKernel(all->cl->program, "fractol", &er);
	all->cl->cl_i_arg = clCreateBuffer(all->cl->cont, CL_MEM_READ_WRITE,
			sizeof(int) * 32, NULL, &er);
	all->cl->cl_data = clCreateBuffer(all->cl->cont, CL_MEM_READ_WRITE,
									sizeof(int) * WIDE * LENGTH, NULL, &er);
	all->cl->cl_f_arg = clCreateBuffer(all->cl->cont, CL_MEM_READ_WRITE,
										sizeof(double) * 32, NULL, &er);
	er = clSetKernelArg(all->cl->kernel, 0, sizeof(cl_mem), &all->cl->cl_data);
	er = clSetKernelArg(all->cl->kernel, 1, sizeof(cl_mem), &all->cl->cl_i_arg);
	er = clSetKernelArg(all->cl->kernel, 2, sizeof(cl_mem), &all->cl->cl_f_arg);
	error_cl(er, kernel_str);
	return (all);
}
