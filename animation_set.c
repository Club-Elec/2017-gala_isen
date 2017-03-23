Lettre l_1_LtoR[] = {G___, _A__, __L_, ___A, END}
Lettre l_1_TtoL[] = {___A, __L_, _A__, G___, END}

Lettre l_2_LtoR[] = {G___, GA__, _AL_, __LA, ___A, END}
Lettre l_2_TtoL[] = {___A, __LA, _AL_, GA__, G___, END}

Lettre l_3_LtoR[] = {G___, GA__, GAL_, _ALA, __LA, ___A, END}
Lettre l_3_TtoL[] = {___A, __LA, _ALA, GAL_, GA__, A___, END}

Lettre l_4_LtoM[] = {G___, GA__, GAL_, GALA, END}
Lettre l_4_MtoR[] = {GALA, _ALA, __LA, ___A, END}
Lettre l_4_LtoR[] = {G___, GA__, GAL_, GALA, _ALA, __LA, ___A, END}

Lettre l_full_blink[] = {GALA, END}
Lettre l_full_off[] = {END}
Lettre l_1on2letter_blink[] = {G_L_, _A_A, END}
Lettre l_end_middle_letter_blink[] = {G__A, _AL_, END}
Lettre l_end_letter_blink[] = {GA__, __LA, END}



const int short_pause = 100;
const int medium_pause = short_pause * 2;
const int long_pause = short_pause * 3;

const int blanck_never = 0;
const int blanck_after = 1;
const int blanck_before = 2;
const int blanck_both = 3;


//1 letter, left to right
Animation a_1_LtoR[] = {.steps = &l_1_LtoR,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_after};

Animation a_1_TtoL[] = {.steps = &l_1_TtoL,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_after};

//2 letters, left to right
Animation a_2_LtoR = {.steps = &l_2_LtoR,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_after};

Animation a_2_TtoL = {.steps = &l_2_TtoL,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_after};

//3 letters, left to right
Animation a_3_LtoR = {.steps = &l_3_LtoR,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_after};

Animation a_3_TtoL = {.steps = &l_3_TtoL,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_after};

//4 letters, left to middle
Animation a_4_LtoM = {.steps = &l_4_LtoM,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = 0};

Animation a_4_MtoR = {.steps = &l_4_MtoR,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = 0};

Animation a_4_LtoR = {.steps = &l_4_LtoR,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = 0};

//4 letter, always on
Animation a_full_on = {.steps = &l_full_blink,
				.pause = short_pause,
				.iterations = 3
				.appendBlank = blanck_never};

//4 letter, always off
Animation a_full_off = {.steps = &l_full_off,
				.pause = short_pause,
				.iterations = 3
				.appendBlank = blanck_never}

//4 letter blink
Animation a_full_blink = {.steps = &l_full_blink,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_after};

//1 letter on 2 blink
Animation a_1on2letter_blink = {.steps = &l_1on2letter_blink,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_never};

//end letters blink with middle letters
Animation a_end_middle_letter_blink = {.steps = &l_end_middle_letter_blink,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_never};

//2letter on one end blink
Animation a_end_letter_blink = {.steps = l_end_letter_blink,
				.pause = short_pause,
				.iterations = 1
				.appendBlank = blanck_never};

Animation animations[] = {a_full_on, 
							a_1_LtoR, a_1_TtoL, a_2_LtoR, a_2_TtoL,
							a_3_LtoR, a_3_TtoL, a_4_LtoR,
							a_full_on,
							a_full_blink,
							a_full_on,
							a_1on2letter_blink, a_end_middle_letter_blink, _end_letter_blink}
