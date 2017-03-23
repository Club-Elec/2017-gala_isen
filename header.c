//Representation d'une lettre
typedef enum
{
	____ = 0,
	___A = 1,
	__L_ = 2,
	__LA = 3,
	_A__ = 4,
	_A_A = 5,
	_AL_ = 6,
	_ALA = 7,
	G___ = 8,
	G__A = 9,
	G_L_ = 10,
	G_LA = 11,
	GA__ = 12,
	GA_A = 13,
	GAL_ = 14,
	GALA = 15,
	END
} Lettre;

//Représentation d'une animation
typedef struct
{
	Lettre* steps;
	int pause;
	int iterations;
	int appendBlank;
} Animation;

#include <stdio.h>
void main()
{
	Lettre l = GALA;
	printf("%d", l);
	Animation a = {.steps = (Lettre[]){G___, GA__, GAL_, GALA, END},
					.pause = 100,
					.iterations = 20,
					.appendBlank = 0};
	int i = 0;
	while(1)
	{
		if(a.steps[i] == END)
		{
			break;
		}
		printf("%d\t%d\t%d\n", a.steps[i], a.pause, a.iterations);
		i++;
	}
}
