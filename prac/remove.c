#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	current = *begin_list;
	prev = ((void *)0);
	while (current)
	{
		next = current->next;
		if (cmp(current->data, data_ref) == 0)		
		{
			if (prev) 
				prev->next = current->next;
			else
				*begin_list = current->next;
			free(current);
			current = ((void *)0);
		}
		prev = current;
		current = next;
	}
}
