
#ifndef TOKEN_H
# define TOKEN_H

//--------------------------//
//			include			//
//--------------------------//

# include "../include/err.h"
# include "../include/structure.h"
# include "../lib/lib_ft/libft.h"

//--------------------------//
//			fontion			//
//--------------------------//

t_token	*make_token(int flag, int redi_in, int redi_out);

/*
◦ < doit rediriger l’entrée.
◦ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
◦ > doit rediriger la sortie.
◦ >> doit rediriger la sortie en mode append.
*/

#endif // TOKEN_H
