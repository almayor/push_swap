cmake_minimum_required(VERSION 2.8.9)

project (push_swap)
include_directories(include libftprintfgnl)
link_directories(libftprintfgnl)

add_executable(push_swap
src/push_swap.c
src/utils/ps_tab2stack.c
src/utils/ps_exit.c
src/utils/ps_atoi.c
src/utils/ps_isnumeric_str.c
src/utils/ps_index_stack.c
src/operations/perform_operation.c
src/operations/functions/perform_sb.c
src/operations/functions/perform_rrb.c
src/operations/functions/perform_rb.c
src/operations/functions/perform_rra.c
src/operations/functions/perform_sa.c
src/operations/functions/perform_ra.c
src/operations/functions/perform_ss.c
src/operations/functions/perform_rr.c
src/operations/functions/perform_pa.c
src/operations/functions/perform_rrr.c
src/operations/functions/perform_pb.c
src/stack/issorted_stack.c
src/stack/min_stack.c
src/stack/rotate_stack.c
src/stack/new_stack.c
src/stack/push_stack.c
src/stack/free_stack.c
src/stack/avg_stack.c
src/stack/reverse_rotate_stack.c
src/stack/pull_stack.c
src/stack/swap_stack.c
src/stack/print_stack.c
src/stack/append_stack.c
src/stack/get_stack.c
src/stack/isset_stack.c
src/stack/search_stack.c
src/stack/max_stack.c
src/sorts/advanced_sort.c
src/sorts/simple_sort.c
src/sorts/advanced_prepare_stacks.c
)

target_link_libraries(push_swap libftprintfgnl.a)
target_compile_options(push_swap PUBLIC -Wall -Wextra -Werror -O3 -std=gnu11 -ffast-math -march=native
)
