#
int		find_size_of_side(int s)
{
	int	n;

	n = 1;
	while (n * n < s)
		n++;
	return (n);
}