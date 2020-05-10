cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

link_directories(.)

add_executable(push_swap
        includes/libft.h
        includes/push_swap.h
        includes/stack.h
        srcs/operations/functions/perform_pa.c
        srcs/operations/functions/perform_pb.c
        srcs/operations/functions/perform_ra.c
        srcs/operations/functions/perform_rb.c
        srcs/operations/functions/perform_rr.c
        srcs/operations/functions/perform_rra.c
        srcs/operations/functions/perform_rrb.c
        srcs/operations/functions/perform_rrr.c
        srcs/operations/functions/perform_sa.c
        srcs/operations/functions/perform_sb.c
        srcs/operations/functions/perform_ss.c
        srcs/operations/perform_operation.c
        srcs/stack/append_stack.c
        srcs/stack/free_stack.c
        srcs/stack/has_duplicates_stack.c
        srcs/stack/is_sorted_stack.c
        srcs/stack/new_stack.c
        srcs/stack/print_stack.c
        srcs/stack/pull_stack.c
        srcs/stack/push_stack.c
        srcs/stack/reverse_rotate_stack.c
        srcs/stack/rotate_stack.c
        srcs/stack/swap_stack.c
        srcs/stack/min_stack.c
        srcs/stack/max_stack.c
        srcs/stack/avg_stack.c
        srcs/utils/is_numeric_str.c
        srcs/utils/ft_atoi2.c
        srcs/push_swap.c srcs/stack/rank_stack.c srcs/utils/process_arguments.c)

target_link_libraries(push_swap
        libftprintf.a)
