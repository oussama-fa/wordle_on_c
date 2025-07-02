#include "wordle.h"

int main(void)
{
	Welcome_msg();
	t_data	*data = read_from_data_base();
	char	*random_word = get_random_word(data);
	char	input_str[6];
	ft_putstr_delay("Enter the World you Guess : \n");
	scanf("%s", &input_str);
	if (pars_input(data, input_str))
		return (ft_malloc(0, CLEAR), 1);
	int i = -1;
	while (++i < 6)
	{
		print_status(random_word, input_str);
		scanf("%s", &input_str);
		if (pars_input(data, input_str))
			return (ft_malloc(0, CLEAR), 1);
	}
	printf("\033[35m[ YOU LOSE ]\033[0m\n");
	printf("The Word is : [%s]\n", random_word);
	ft_malloc(0, CLEAR);
	return (1);
}
