#include "ms.h"

static int	how_to_use(void)
{
	ft_printf(2, "%oms: -s\n", NULL);
	ft_printf(2, "%o	"DIRL, NULL);
	ft_printf(2, "%o	C show the color pallet\n", NULL);
	ft_printf(2, "%o	"COLOR_SYS, NULL);
	ft_printf(2, "%oms: -u\n", NULL);
	ft_printf(2, "%o	use too look for update, and auto update\n", NULL);
	ft_printf(2, "%o	you can use in .msrc\n", NULL);
	ft_printf(2, "%oms: -l\n", NULL);
	ft_printf(2, "%o	"LOGIC, NULL);
	ft_printf(2, "%oms: -r \n", NULL);
	ft_printf(2, "%o	"RUN, NULL);
	ft_printf(2, "%oms: -i\n", NULL);
	ft_printf(2, "%o	show information about default value on this shell\n", NULL);
	ft_printf(2, "%oms: log\n", NULL);
	ft_printf(2, "%o	use to print the log on scren with 'less'\n", NULL);
	return (0);
}

static int	bad_arg(char *s)
{
	ft_printf(2, "%o"MS_NAME"\b: ms: %s not valid\n", NULL, s);
	return (1);
}
static int	look_arg(char **av, size_t *i, size_t *j)
{
	*j = 0;
	*i = ft_strlen_double(av);
	if (*i == 1)
	{
		how_to_use();
		return (0);
	}
	return (0);
}

static int	readlog(void)
{
	t_mshell	*shell;
	char		*str;
	int			err;

	err = 0;
	shell = ft_return_ptr(NULL, SYS);
	if (!shell)
		return (1);
	ft_printf(NO_PRINT, "%o%s/.config/.log", &str, shell->compile_dir);
	if (access(str, F_OK | R_OK) == 0 && !shell->s_in)
		ft_printf(NO_PRINT, "%o"LESS_AND_ARGS"%s", &shell->s_in, str);
	else
	{
		ft_printf(2, "%oms: %s %s\n", NULL, str, strerror(errno));
		err = 1;
	}
	ft_free(str);
	return (err);
}

//update

static int	info(size_t *j)
{
	t_mshell	*data;

	(void)(*j);
	data = ft_return_ptr(NULL, SYS);
	if (data)
	{
		ft_printf(1, "%odefault value for:\n", NULL);
		ft_printf(1, "%obin find in : %s\n", NULL, PATH_BIN_S);
		ft_printf(1, "%osplit value on: %c\n", NULL, PATH_SPLIT);
		ft_printf(1, "%opath separator: %c\n", NULL, PATH_SEP);
		ft_printf(1, "%oPROMPT: %s\n", NULL, PROMPT);
		ft_printf(1, "%oversion: %s\n", NULL, get_env(data->en, "V_MINI"));
		ft_printf(1, "%oconpile dir: %s\n", NULL, get_env(data->en, "CONPILE_DIR"));
		ft_printf(1, "%olast compile vertion by %s at %s %s\n", NULL, USER_GCC , __DATE__, __TIME__);
	}
	return (1);
}

int	ft_ms(char **av, int re_in, int re_out, char **en)
{
	size_t	i;
	size_t	j;
	int		err;

	(void)re_in;
	(void)re_out;
	(void)en;
	err = look_arg(av, &i, &j);
	while (++j < i)
	{
		if (ft_strncmp(av[j], "-s", 3) == 0)
			err += ms_edit(av + j + 1, &j);
		else if (ft_strncmp(av[j], "-u", 3) == 0)
			ms_update(1);
		else if (ft_strncmp(av[j], "update", 7) == 0)
			ms_update(0);
		else if (ft_strncmp(av[j], "-l", 3) == 0)
			err += ms_logic(av + 2, &j);
		else if (ft_strncmp(av[j], "-r", 3) == 0)
			err += ms_run(av + 2, &j);
		else if (ft_strncmp(av[j], "-i", 3) == 0)
			err += info(&j);
		else if (ft_strncmp(av[j], "log", 4) == 0)
			err += readlog();
		else if (ft_strncmp(av[j], "-j", 3) == 0)
			err += ms_jump(av[j + 1], &j);
		else
			err += bad_arg(av[j]);
	}
	return (err);
}
