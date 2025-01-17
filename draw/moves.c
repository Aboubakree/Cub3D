/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:41:49 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 11:54:50 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_right(double *newx, double *newy, t_data *mydata)
{
	*newx = mydata->player->j + cos(mydata->player->rotationangle + M_PI / 2)
		* mydata->player->movespeed;
	*newy = mydata->player->i + sin(mydata->player->rotationangle + M_PI / 2)
		* mydata->player->movespeed;
	if (wall_check(mydata, *newx, *newy))
	{
		mydata->player->j = *newx;
		mydata->player->i = *newy;
	}
	else
		return ;
}

void	move_left(double *newx, double *newy, t_data *mydata)
{
	*newx = mydata->player->j + cos(mydata->player->rotationangle - M_PI / 2)
		* mydata->player->movespeed;
	*newy = mydata->player->i + sin(mydata->player->rotationangle - M_PI / 2)
		* mydata->player->movespeed;
	if (wall_check(mydata, *newx, *newy))
	{
		mydata->player->j = *newx;
		mydata->player->i = *newy;
	}
	else
		return ;
}

void	move_up(double *newx, double *newy, t_data *mydata)
{
	*newx = mydata->player->j + cos(mydata->player->rotationangle)
		* mydata->player->movespeed;
	*newy = mydata->player->i + sin(mydata->player->rotationangle)
		* mydata->player->movespeed;
	if (wall_check(mydata, *newx, *newy))
	{
		mydata->player->j = *newx;
		mydata->player->i = *newy;
	}
	else
		return ;
}

void	move_down(double *newx, double *newy, t_data *mydata)
{
	*newx = mydata->player->j - cos(mydata->player->rotationangle)
		* mydata->player->movespeed;
	*newy = mydata->player->i - sin(mydata->player->rotationangle)
		* mydata->player->movespeed;
	if (wall_check(mydata, *newx, *newy))
	{
		mydata->player->j = *newx;
		mydata->player->i = *newy;
	}
	else
		return ;
}

void	move_keys(int keycode, t_data *mydata)
{
	double	newx;
	double	newy;

	(void)keycode;
	if (mydata->player->to_walk == 2)
		move_right(&newx, &newy, mydata);
	else if (mydata->player->to_walk == 1)
	{
		move_left(&newx, &newy, mydata);
	}
	else if (mydata->player->to_walk == 3)
	{
		move_up(&newx, &newy, mydata);
	}
	else if (mydata->player->to_walk == 4)
	{
		move_down(&newx, &newy, mydata);
	}
}
