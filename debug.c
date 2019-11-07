///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   debug.c                                            :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/10/23 17:01:25 by dgreat            #+#    #+#             */
///*   Updated: 2019/11/05 20:05:12 by dgreat           ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractol.h"
//
//void		vard(char *s, t_point a)
//{
//	endl();
//	ft_putstr(s);
//	ft_putchar('(');
//	ft_putnbr(a.x);
//	ft_putchar(';');
//	ft_putnbr(a.y);
//	ft_putchar(';');
//	ft_putnbr(a.z);
//	ft_putchar(';');
//	ft_putnbr_base(a.hue.hex_color, 16, 1);
//	ft_putchar(')');
//	endl();
//}
//
//void	vardot(char *s, t_point a)
//{
//	endl();
//	ft_putstr(s);
//	ft_putchar('(');
//	ft_putnbr(a.x);
//	ft_putchar(';');
//	ft_putnbr(a.y);
//	ft_putchar(')');
//	endl();
//}
//
//void	each_dot(t_mlx win, t_point **tab, void (*f)(char *, t_point))
//{
//	int		i;
//	int		j;
//	char	*str;
//
//	i = -1;
//	while (++i < win.map.y)
//	{
//		j = -1;
//		while (++j < win.map.x && tab[i][j].hue.hex_color > 0)
//		{
//			str = ft_strjoin(ft_itoa(i), ":");
//			(*f)(ft_strjoin(str, ft_itoa(j)), tab[i][j]);
//		}
//	}
//}