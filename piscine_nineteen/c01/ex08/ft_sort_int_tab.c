/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:24:19 by afocant           #+#    #+#             */
/*   Updated: 2024/02/11 21:27:09 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *p1, int *p2)
{
	int	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>
int main()
{
	int size = 6;
	int arr[] = {2, 5, 1, 3, 9, 7};


	for (int i = 0; i < size; i++)
		printf("%i, ", arr[i]);
	
	ft_sort_int_tab(arr, size);

	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%i, ", arr[i]);
}
*/
