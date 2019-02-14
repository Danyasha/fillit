#include "../backtraking.h"

void print_map(char **c)
{
	int	i;

	i = 0;
	while(c[i])
		printf("%s\n", c[i++]);
}
void two_fig_test()
{
	int		fd;
	t_dlst	*head;
	t_map	*map;

	fd = open("test.fillit", O_RDONLY);
	head = ft_validate_main(fd);
	print_map(head->tetra);
	print_map(head->next->tetra);
	map = map_gen(head, 5);
	tetra_place(map, head, 0, 0);
	tetra_place(map, head->next, 1, 0);
	print_map(map->map);
	tetra_del(map, head->next);
	printf("\n");
	print_map(map->map);
	close(fd);
}

int main()
{
two_fig_test();
	return (0);
}