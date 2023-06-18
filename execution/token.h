
#ifndef TOKEN_H
# define TOKEN_H

//--------------------------//
//			include			//
//--------------------------//

# include <stdbool.h>
# include "../include/err.h"
# include "../lib/lib_ft/libft.h"

//--------------------------//
//			define			//
//--------------------------//

# ifndef  TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

# define PIPE_NO 0
# define PIPE_IN 1
# define PIPE_OUT 2
# define PIPE_IN_OUT 3

# define NO_FILE 0


//--------------------------//
//			struct			//
//--------------------------//

typedef struct s_token
{
	char	build_in;
	char	mode;
	int		pipe_in;
	int		pipe_out;
	int		redi_in;
	int		redi_out;
}	t_token;

//--------------------------//
//			fontion			//
//--------------------------//

//t_token	*make_token(int in, int out, char build_in, int mode);
t_token	*make_token(char build_in, int mode, int redi_in, int redi_out);

/*
◦ < doit rediriger l’entrée.
◦ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
◦ > doit rediriger la sortie.
◦ >> doit rediriger la sortie en mode append.
*/


#endif // TOKEN_H
