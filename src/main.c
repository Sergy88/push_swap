#include "../includes/push_swap.h"

#include <stdio.h>


t_int_cont *new_int(char *str_int)
{
	int i;
	t_int_cont *cont;

	i = ft_atoi(str_int);
	cont = (t_int_cont *) malloc(sizeof(t_int_cont));
	cont->val = i;
	cont->index = 0;
	cont->round = 0;
	return cont;
}

void print_lst(t_list *lst)
{
	while(lst)
	{
		printf("index %d\n",  ((t_int_cont *) lst->content)->index );
		printf("round %d\n",  ((t_int_cont *) lst->content)->round );
		printf("val %d\n",  ((t_int_cont *) lst->content)->val);
		printf("\n\n");
		lst = lst->next;
	}
}

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("stack A\t\t\t\t\t\t\t\tstack B\n");
	while(stack_a || stack_b)
	{
		if (stack_a) {
			printf("index %d \t", ((t_int_cont *) stack_a->content)->index);
			printf("round %d \t", ((t_int_cont *) stack_a->content)->round);
			printf("val %d \t|", ((t_int_cont *) stack_a->content)->val);
			stack_a = stack_a->next;
		} else
		{
			printf("NULL      \tNULL      \tNULL  \t|");
		}
		printf("\t\t");
		if (stack_b) {
			printf("index %d \t", ((t_int_cont *) stack_b->content)->index);
			printf("round %d \t", ((t_int_cont *) stack_b->content)->round);
			printf("val %d \t", ((t_int_cont *) stack_b->content)->val);
			stack_b = stack_b->next;
		} else
		{
			printf("NULL      \tNULL      \tNULL  \t|");
		}
		printf("\n");
	}
}

int get_args(int argc, char **argv, t_list **lst)
{
    int c;
	t_int_cont *temp;

    c = 1;
    if (argc < 2)
        return (-1);
    while (c < argc)
    {
		temp = new_int(argv[c]);
        ft_lstadd_back(lst, ft_lstnew(temp));
		c++;
    }
    return (0);
}

int sort(t_list **stack_a_ptr, t_list **stack_b_ptr, t_list *sorted)
{
	int max;
	int c;
	t_list *stack_a;
	t_list *stack_b;

	stack_a = *stack_a_ptr;
	stack_b = *stack_b_ptr;


	c = 0;
	max = 0;
	while (sorted)
	{
		sorted = sorted->next;
		max++;
	}

	while(stack_a)
	{
		if (((t_int_cont *) (stack_a->content))->index == c)
		{
			ft_rx(&stack_a, 'a', 1);
			c++;
			break ;
		}
		else
		{
			ft_px(&stack_a, &stack_b, 'b', 1);
		}
	}
	while(c < max)
	{
		while(stack_b && (c < max))
		{
			if (((t_int_cont *) (stack_b->content))->index == c)
			{
				ft_px(&stack_a, &stack_b, 'a', 1);
				ft_rx(&stack_a, 'a', 1);
				c++;
			}
			else
			{
				ft_rx(&stack_b, 'b', 1);
			}
		}
	}
	*stack_a_ptr = stack_a;
	*stack_b_ptr = stack_b;
	return (1);
}

int main(int argc, char** argv)
{
    t_list *int_lst;
	t_list *sorted;
	t_list *stack_a;
	t_list *stack_b;

	int_lst = NULL;
	stack_a = NULL;
	stack_b = NULL;

	get_args(argc, argv, &int_lst);
	sorted = copy_stack(int_lst);
	ft_sort(sorted);
//	print_lst(sorted);
	stack_a = copy_stack(int_lst);
	index_stack(stack_a, sorted);
//	print_stacks(stack_a, stack_b);
	sort(&stack_a, &stack_b, sorted);
//	print_stacks(stack_a, stack_b);
//	ft_rrx(&stack_a, 'a', 1);
//	print_stacks(stack_a, stack_b);
//
//	ft_rrx(&stack_a, 'a', 1);
//	print_stacks(stack_a, stack_b);
//
//	ft_rrx(&stack_a, 'a', 1);
//	print_stacks(stack_a, stack_b);
//
//	ft_rrx(&stack_b, 'b', 1);
//	print_stacks(stack_a, stack_b);

	//ft_sx(&int_lst, 'a', 1);
	//print_lst(int_lst);

}
