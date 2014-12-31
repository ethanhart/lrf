#include "LRF.h" // Call the LRF library

// Tap to play Auld Lang Syne
// Author: Ethan Hart
// Date: 2014-12-31

// Light pattern for eyes
LRFPattern lightsPattern = {
  LRFColor_Red,
  LRFColor_Red,
  LRFPatternMode_RandomBoomerang
};

// Array of sounds
LRFSound alsIntro[14] = {
{ LRFNote_C, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_G, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_Short },
{ LRFNote_G, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_Short },
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_C, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_D, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Long, LRFDuration_Short }
};

LRFSound alsRep[8] = {
{ LRFNote_D, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_C, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Short },
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_Short },
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_G, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_Short },
{ LRFNote_G, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short }
};

LRFSound alsEnd1[6] = {
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Short },
{ LRFNote_D, LRFOctave_3, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_Short },
{ LRFNote_D, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_C, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_F, LRFOctave_3, LRFIntonation_Flat, LRFDuration_Long, LRFDuration_Short }
};

LRFSound alsEnd2[6] = {
{ LRFNote_D, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_C, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleMedium, LRFDuration_Short },
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_DoubleShort, LRFDuration_Short },
{ LRFNote_A, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_C, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Medium, LRFDuration_Short },
{ LRFNote_D, LRFOctave_4, LRFIntonation_Flat, LRFDuration_Long, LRFDuration_Short }
};

int alsIntroNotes = sizeof(alsIntro) / 2; // Keeps track of # of notes in array
int alsRepNotes = sizeof(alsRep) / 2;
int alsEndNotes = sizeof(alsEnd1) / 2;

// Function to play song and turn on the LED pattern
void playSong(void) {
  lrf.blinkAndSay(lightsPattern, alsIntro, alsIntroNotes);
  lrf.blinkAndSay(lightsPattern, alsRep, alsRepNotes);
  lrf.blinkAndSay(lightsPattern, alsEnd1, alsEndNotes);
  lrf.blinkAndSay(lightsPattern, alsRep, alsRepNotes);
  lrf.blinkAndSay(lightsPattern, alsEnd2, alsEndNotes);
  lrf.blinkAndSay(lightsPattern, alsRep, alsRepNotes);
  lrf.blinkAndSay(lightsPattern, alsEnd1, alsEndNotes);
}

void setup(void) {
  lrf.setup();
  lrf.setEventHandler(LRFEvent_Tap, &playSong); // Tap LRF to play song
}

void loop(void) {
  lrf.loop();
}

