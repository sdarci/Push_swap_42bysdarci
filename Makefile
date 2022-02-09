NAME	= push_swap

SRCS		=  main.c  ft_atoi_for_push_swap.c actions.c \
				actions2.c actions3.c global_sort.c  bubblesort.c \
				global_sort2.c 


CC		= cc

RM		= rm -f

HEAD	= push_swap.h

CFLAGS	= -Wall -Werror -Wextra

OBJS	=${SRCS:.c=.o}

.PHONY:	all clean fclean re

all:	${NAME}

${NAME}:	 ${OBJS} ${HEAD}
			 @${CC} ${CFLAGS}  ${OBJS} -o ${NAME}


clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all
