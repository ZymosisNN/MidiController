// Amp
// params 7 - 12 doesn't change anything
#define AmpParam7  92
#define AmpParam8  93
#define AmpParam9  94
#define AmpParam10 95
#define AmpParam11 102
#define AmpParam12 103

/*** Unclear ***/
#define TapTempoTrigger  64  // 64-127 = Tap, unclear works or not
#define AmpSwitchAssign  84 // 0~63=Amp switch will turn Amp on/off ; 64~127=Amp switch will turn Comp on/off. Assign CC 111 to either Amp or Comp (enable/disable)
#define AmpState         111 // 0~63=Off ; 64~127=On. Toggles between Amp or Compressor (depending on CC 84 parameter)
#define AmpBypassVolume  105  // need to check

// Bass Amp only
#define BASS_AMP_DI_LOCUT  45
#define BASS_AMP_DI_LEVEL  48
#define BASS_AMP_DI_DELAY  49

// Mod
#define ModulationEnable  50
#define ModulationNote  51 // 0-13 (for tempo sync)
#define ModTempoMSB  89  // unclear mapping
#define ModTempoLSB  90
#define ModParam1MSB  29 // Mod Speed
#define ModParam1LSB  61
#define ModulationParam2  52
#define ModulationParam3  53
#define ModulationParam4  54
#define ModulationParam5  55 // not used
#define ModulationMix  56 // not working
#define ModulationPrePost  57
#define ModulationModelSelect  58

// Comp
#define CompressorEnable  26
#define CompressorGain  5
#define CompressorThreshold  9

// NG
#define NoiseGateEnable  22
#define NoiseGateThreshold  23
#define NoiseGateDecay  24

// EQ
#define EQEnable  63
#define EQFrequency1  20
#define EQFrequency2  42
#define EQFrequency3  60
#define EQFrequency4  77
#define EQGain1  114
#define EQGain2  116
#define EQGain3  117
#define EQGain4  119

// Delay
#define DelayEnable  28
#define DelayNote  31 // 0-13 (for tempo sync)
#define DelayParam1MSB  30  // Delay time
#define DelayParam1LSB  62
#define DelayParam2  33
#define DelayParam3  35
#define DelayParam4  85
#define DelayParam5  86
#define DelayMix  34
#define DelayPrePost  87

// Reverb
#define ReverbEnable  36
#define ReverbModelSelect  37
#define ReverbDecay  38
#define ReverbTone  39
#define ReverbPreDelay  40
#define ReverbMix  18
#define ReverbPrePost  41

// Stomp
#define StompParam1MSB     27 // Doesn't work
#define StompParam1LBS     59

/*** USELESS ***/
#define EffectTweak      1   // Controls a GearBox parameter depending on current CC 108 setting
#define TweakAssignment  108 // 0-13 Assign CC 1 to control a GearBox parameter
