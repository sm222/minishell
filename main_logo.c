#include "include/minishell.h"

static void	set_color(char *color[11], int nb[7], char *tmp)
{
	int	i;

	i = 0;
	color[0] = RED;
	color[1] = GRN;
	color[2] = BLU;
	color[3] = YEL;
	color[4] = MAG;
	color[5] = CYN;
	color[6] = WHT;
	color[7] = ORG;
	color[8] = PIK;
	color[9] = TOX;
	while (i < 10)
	{
		if (tmp[0] == '-')
			nb[i] = tmp[i + 1] - '0';
		else
			nb[i] = tmp[i] - '0';
		if (nb[i] < 0)
			nb[i] = 0;
		i++;
	}
}

static void	set_m_i_n_s_h(t_logo *logo)
{
	logo->m[0] = L0M;
	logo->m[1] = L1M;
	logo->m[2] = L2M;
	logo->m[3] = L3M;
	logo->m[4] = L4M;
	logo->i[0] = L0I;
	logo->i[1] = L1I;
	logo->i[2] = L2I;
	logo->i[3] = L3I;
	logo->i[4] = L4I;
	logo->n[0] = L0N;
	logo->n[1] = L1N;
	logo->n[2] = L2N;
	logo->n[3] = L3N;
	logo->n[4] = L4N;
	logo->s[0] = L0S;
	logo->s[1] = L1S;
	logo->s[2] = L2S;
	logo->s[3] = L3S;
	logo->s[4] = L4S;
	logo->h[0] = L0H;
	logo->h[1] = L1H;
	logo->h[2] = L2H;
	logo->h[3] = L3H;
	logo->h[4] = L4H;
}

static void	print_seed(t_logo *logo)
{
	ft_printf(1, "seed	%d|%d|%d|%d|%d|%d|%d|%d|%d\n", \
	logo->nb[0], logo->nb[1], logo->nb[2], \
	logo->nb[3], logo->nb[4], logo->nb[5], \
	logo->nb[6], logo->nb[7], logo->nb[8]);
}

static void	set_all(t_logo *logo)
{
	set_color(logo->color, logo->nb, logo->tmp);
	set_m_i_n_s_h(logo);
	print_seed(logo);
	logo->e[0] = L0E;
	logo->e[1] = L1E;
	logo->e[2] = L2E;
	logo->e[3] = L3E;
	logo->e[4] = L4E;
	logo->l[0] = L0L;
	logo->l[1] = L1L;
	logo->l[2] = L2L;
	logo->l[3] = L3L;
	logo->l[4] = L4L;
}

void	print_logo(char *seed)
{
	t_logo		logo;
	int			i;

	if (seed && !ft_ban(seed, "0123456789"))
		logo.tmp = ft_strdup(seed);
	else
	{
		logo.con = ((long long)&print_logo);
		logo.tmp = ft_ulltoa((unsigned long long)logo.con, 10);
	}
	if (!logo.tmp)
		return ;
	set_all(&logo);
	i = -1;
	while (++i < 5)
	{
		ft_printf(1, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n", \
	logo.color[logo.nb[0]], logo.m[i], logo.color[logo.nb[1]], logo.i[i], \
	logo.color[logo.nb[2]], logo.n[i], logo.color[logo.nb[3]], logo.i[i], \
	logo.color[logo.nb[4]], logo.s[i], logo.color[logo.nb[5]], logo.h[i], \
	logo.color[logo.nb[6]], logo.e[i], logo.color[logo.nb[7]], logo.l[i], \
	logo.color[logo.nb[8]], logo.l[i]);
	}
	ft_free(logo.tmp);
	ft_putstr_fd("\n"MADE_BY MADE_BY_NANE RESET, 1);
}
