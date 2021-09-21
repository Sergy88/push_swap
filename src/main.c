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
        ft_lstadd_front(lst, ft_lstnew(temp));
		c++;
    }
    return (0);
}

int main(int argc, char** argv)
{
    t_list *int_lst;
	t_list *stack_a;
	t_list *stack_b;

	int_lst = NULL;
	stack_a = NULL;
	stack_b = NULL;

	get_args(argc, argv, &int_lst);
	stack_a = copy_stack(int_lst);
	stack_b = copy_stack(int_lst);

	print_lst(int_lst);
	print_lst(stack_a);
	print_lst(stack_b);

	//ft_sx(&int_lst, 'a', 1);
	//print_lst(int_lst);

}
