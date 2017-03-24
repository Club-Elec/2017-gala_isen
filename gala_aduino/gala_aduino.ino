const int led_1 = 2;
const int led_2 = 3;
const int led_3 = 4;
const int led_4 = 5;
const int btn = 6;

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

Lettre l_1_LtoR[] = {G___, _A__, __L_, ___A, END};
Lettre l_1_TtoL[] = {___A, __L_, _A__, G___, END};

Lettre l_2_LtoR[] = {G___, GA__, _AL_, __LA, ___A, END};
Lettre l_2_TtoL[] = {___A, __LA, _AL_, GA__, G___, END};

Lettre l_3_LtoR[] = {G___, GA__, GAL_, _ALA, __LA, ___A, END};
Lettre l_3_TtoL[] = {___A, __LA, _ALA, GAL_, GA__, G___, END};

Lettre l_4_LtoM[] = {G___, GA__, GAL_, GALA, END};
Lettre l_4_MtoR[] = {GALA, _ALA, __LA, ___A, END};
Lettre l_4_LtoR[] = {G___, GA__, GAL_, GALA, _ALA, __LA, ___A, END};

Lettre l_full_blink[] = {GALA, END};
Lettre l_full_off[] = {END};
Lettre l_1on2letter_blink[] = {G_L_, _A_A, END};
Lettre l_end_middle_letter_blink[] = {G__A, _AL_, END};
Lettre l_end_letter_blink[] = {GA__, __LA, END};

#define short_pause 200
#define medium_pause 200
#define long_pause 300

#define blanck_never 0
#define blanck_after 1
#define blanck_before 2
#define blanck_both 3


//1 letter, left to right
Animation a_1_LtoR = {.steps = l_1_LtoR,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = blanck_after};

Animation a_1_TtoL = {.steps = l_1_TtoL,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = blanck_after};

//2 letters, left to right
Animation a_2_LtoR = {.steps = l_2_LtoR,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = blanck_after};

Animation a_2_TtoL = {.steps = l_2_TtoL,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = blanck_after};

//3 letters, left to right
Animation a_3_LtoR = {.steps = l_3_LtoR,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = blanck_after};

Animation a_3_TtoL = {.steps = l_3_TtoL,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = blanck_after};

//4 letters, left to middle
Animation a_4_LtoM = {.steps = l_4_LtoM,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = 0};

Animation a_4_MtoR = {.steps = l_4_MtoR,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = 0};

Animation a_4_LtoR = {.steps = l_4_LtoR,
				.pause = short_pause,
				.iterations = 1,
				.appendBlank = 0};

//4 letter, always on
Animation a_full_on = {.steps = l_full_blink,
				.pause = short_pause,
				.iterations = 3,
				.appendBlank = blanck_never};

//4 letter, always off
Animation a_full_off = {.steps = l_full_off,
				.pause = short_pause,
				.iterations = 3,
				.appendBlank = blanck_never};

//4 letter blink
Animation a_full_blink = {.steps = l_full_blink,
				.pause = short_pause,
				.iterations = 10,
				.appendBlank = blanck_after};

//1 letter on 2 blink
Animation a_1on2letter_blink = {.steps = l_1on2letter_blink,
				.pause = short_pause,
				.iterations = 10,
				.appendBlank = blanck_never};

//end letters blink with middle letters
Animation a_end_middle_letter_blink = {.steps = l_end_middle_letter_blink,
				.pause = short_pause,
				.iterations = 10,
				.appendBlank = blanck_never};

//2letter on one end blink
Animation a_end_letter_blink = {.steps = l_end_letter_blink,
				.pause = short_pause,
				.iterations = 10,
				.appendBlank = blanck_never};

const int animations_set_size = 14;

Animation* animations[] = {&a_full_on,//0
							&a_1_LtoR, &a_1_TtoL, &a_2_LtoR, &a_2_TtoL,//1 2 3 4
							&a_3_LtoR, &a_3_TtoL, &a_4_LtoR,//5 6 7
							&a_full_on,//8
							&a_full_blink,//9
							&a_full_on,//10
							&a_1on2letter_blink, &a_end_middle_letter_blink, &a_end_letter_blink};//11 12 13
int stop = 0;


void affichage(int l, int pause);

void setup() {
	// put your setup code here, to run once:
	pinMode(led_1, OUTPUT);
	pinMode(led_2, OUTPUT); 	
	pinMode(led_3, OUTPUT);
	pinMode(led_4, OUTPUT);
	pinMode(btn, INPUT);
}

int isBtnOn()
{
	static int ar = 0;
	int val = digitalRead(btn);
	if(val == HIGH)
	{
		if(ar == 0)
		{
			ar = 1;
			return 1;
		}
		return 0;
	}
	else
	{
		ar = 0;
		return 0;
	}
}

void loop()
{
	for(int i=0; i < animations_set_size; i++)
	{
		Animation* a = animations[i];

		//printf("Animation %d\n", i);

		for(int j=0; j < a->iterations; j++)
		{
			//printf("\tIteration %d\n", j);
			int k = 0;
			if(a->appendBlank == 3 || a->appendBlank == 2)
			{
				affichage(____, a->pause);
			}
			while(1)
			{
				if(isBtnOn() == 1)
				{
					if(stop == 0)
					{
						stop = 1;
					}
					else
					{
						stop = 0;
					}
				}
										
				if(stop == 1)
				{
					affichage(GALA, 1);
					continue;
				}
				
				if(a->steps[k] == END)
				{
					break;
				}
				affichage(a->steps[k], a->pause);
				k++;
			}
			if(a->appendBlank == 3 || a->appendBlank == 1)
			{
				affichage(____, a->pause);
			}
		}
	}
}

void affichage(int l, int pause)
{
	//printf("%d\t", l);
	//printf("\r");
	if( (l & 0x8) > 0)
	{
		//printf("G");
		digitalWrite(led_1, LOW);
	}
	else
	{
		//printf("_");
		digitalWrite(led_1, HIGH);
	}

	if( (l & 0x4) > 0)
	{
		//printf("A");
		digitalWrite(led_2, LOW);
	}
	else
	{
		//printf("_");
		digitalWrite(led_2, HIGH);
	}

	if( (l & 0x2) > 0)
	{
		//printf("L");
		digitalWrite(led_3, LOW);
	}
	else
	{
		//printf("_");
		digitalWrite(led_3, HIGH);
	}

	if( (l & 0x1) > 0)
	{
		//printf("A");
		digitalWrite(led_4, LOW);
	}
	else
	{
		//printf("_");
		digitalWrite(led_4, HIGH);
	}

	//printf("\n");
	delay(pause);
}
