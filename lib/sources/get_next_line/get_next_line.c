#include "../../includes/libft.h"

//de-allocate the memory
static	void	ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

//slice the string into pieces
static char	*ft_slice(char **str)
{
	int		index;
	char	*ret;
	char	*sup;

	index = 0;
	if (!str[0])
		return (NULL);
	while (str[0][index] != '\n' && str[0][index] != '\0')
		index++;
	ret = ft_substr(str[0], 0, index + 1);
	sup = ft_strdup(str[0]);
	ft_free(str);
	str[0] = ft_substr(sup, index + 1, ft_strlen(sup));
	ft_free(&sup);
	if (!ft_strchr(ret, '\n'))
	{
		if (!ft_strlen(ret))
			ft_free(&ret);
		ft_free(str);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	int			size;
	char		*buffer;
	char		*support;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(fd, buffer, BUFFER_SIZE);
	while (size > 0)
	{
		buffer[size] = '\0';
		if (!string)
			string = ft_strdup(buffer);
		else
		{
			support = ft_strjoin(string, buffer);
			ft_free(&string);
			string = support;
		}
		if (ft_strchr(string, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_free(&buffer), ft_slice(&string));
}