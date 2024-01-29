
# include "../push_swap.h"

int    get_moves(t_list **move_list)
{
    char    *str;

    while (str != NULL)
    {
        str = get_next_line(0);
        if (check_move(str) == -1)
            return (-1)
    }
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_list  *move_list;

    stack_a = NULL;
    stack_b = NULL;
    move_list = NULL;
    if (ac < )
        error_exit_ckecker(NULL, NULL, NULL)
    arg_manager(&stack_a, &stack_b);
    if (get_moves(&move_list) == -1)
        error_exit_checker(&stack_a, &stack_b, &move_list);
    make_moves(&move_list, &stack_a, &stack_b);
    check_sort(&stack_a, &stack_b);
}
