#include "pushswap.h"

void	rx(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	last = *a;
	(*a) = (*a)->next;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
}
void	rb(t_stack **b)
{
	rx(b);
	write(1, "rb\n", 3);
}
void	ra(t_stack **a)
{
	rx(a);
	write(1, "ra\n", 3);
}
void	rr(t_stack **a, t_stack **b)
{
	rx(a);
	rx(b);
	write(1, "rr\n", 3);
}

void	rrx(t_stack **a)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	*a = last;
}
void	rra(t_stack **a)
{
	rrx(a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
	rrx(b);
	write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b)
{
	rrx(a);
	rrx(b);
	write(1, "rrr\n", 4);
}
