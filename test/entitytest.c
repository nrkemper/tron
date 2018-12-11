#include "../entity.h"

int main (void)
{	
	ENTY_Init ();
	ENTY_PrintEntities ();
	ENTY_DeleteEntity (0);
	ENTY_DeleteEntity (1);
	ENTY_Shutdown ();
	return 0;
}
