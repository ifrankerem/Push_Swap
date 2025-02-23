#include "pushswap.h"

void	ra(t_stack *a)
{
	int		first;
	t_stack	*temp;

	first = a->value;
	temp = a;
	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	temp->value = first;
	write(1, "ra\n", 3);
}
void	rb(t_stack *b)
{
	int		first;
	t_stack	*temp;

	first = b->value;
	temp = b;
	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	temp->value = first;
	write(1, "rb\n", 3);
}
void	rr(t_stack *a, t_stack *b)
{
	int		first;
	t_stack	*temp;

	first = a->value;
	temp = a;
	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	temp->value = first;
	first = b->value;
	temp = b;
	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	temp->value = first;
	write(1, "rr\n", 3);
}

void	rrx(t_stack *a)
{
	t_stack	*temp;
	int		last_value;
	t_stack	*prev;

	if (!a || !a->next)
		return ;
	temp = a;
	while (temp->next)
		temp = temp->next;
	last_value = temp->value;
	while (temp != a)
	{
		prev = a;
		while (prev->next != temp)
			prev = prev->next;
		temp->value = prev->value;
		temp = prev;
	}
	a->value = last_value;
}
void	rra(t_stack *a)
{
	rrx(a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack *b)
{
	rrx(b);
	write(1, "rrb\n", 4);
}
void	rrr(t_stack *a, t_stack *b)
{
	rrx(a);
	rrx(b);
	write(1, "rrr\n", 4);
}
