#include "daisy_seed.h"
#include "daisysp.h"

using namespace daisy;
using namespace daisysp;
using namespace daisy::seed;

DaisySeed hw;

Switch Button1;

// State counter for 5 different states
int state = 0;

// Audio effects
Phaser phaser;
Chorus chorus;
Overdrive drive;
Oscillator lfo;
Tremolo trem;
Metro      tick;
AdEnv      env;
PitchShifter ps;



// Potentiometer readings
float pot1, pot2;

// Declare functions
void DeclareInitHardware();
void Controls();
void GetEffectSample(float &outl, float inl);

// Callback function to process audio
void MyCallback(AudioHandle::InterleavingInputBuffer in,
                AudioHandle::InterleavingOutputBuffer out, 
                size_t size) 
{
    float outl, inl, outr;
    Controls(); // Check controls (e.g., button, potentiometers)

    for(size_t i = 0; i < size; i += 2)
    {
        inl = in[i];
        outl = inl;
		outr = inl;
		

        // Apply effects based on the current state
        switch (state)
        {
            case 1:  // phaser
                outl = phaser.Process(inl); // Apply Phaser
				outr = outl;
                break;
            case 2:  // chorus
				chorus.Process(inl);
                outl = chorus.GetLeft();
				outr = chorus.GetRight();
                break;
            case 3:  // ovedrive
				drive.SetDrive(fabsf(lfo.Process()));
                outl = drive.Process(inl);
                break;
            case 4:  // tremolo
				if(tick.Process())
				{
					trem.SetFreq(10.f * rand() * kRandFrac);
					trem.SetDepth(.3f + rand() * kRandFrac);
					env.Trigger();
				}
                outl = trem.Process(inl); 
				outr = outl;
                break;
			case 5:  // pitch shifter
                outl = inl;
				outr = ps.Process(inl);
                break;

            default: //nothin
                outl = inl;
				outr = inl;

                break;
        }

        out[i] = outl;  // Left channel
        out[i + 1] = outr;  // Right channel
    }
}

int main(void) {
    DeclareInitHardware();
    float sample_rate = hw.AudioSampleRate();

    phaser.Init(sample_rate);
    phaser.SetFreq(100.f);

	chorus.Init(sample_rate);
	chorus.SetLfoFreq(.33f, .2f);
    chorus.SetLfoDepth(1.f, 1.f);
    chorus.SetDelay(.75f, .9f);

	lfo.Init(sample_rate);
    lfo.SetAmp(.8f);
    lfo.SetWaveform(Oscillator::WAVE_TRI);
    lfo.SetFreq(.25f);

	trem.Init(sample_rate);

	ps.Init(sample_rate);
    // set transposition 1 octave up (12 semitones)
    ps.SetTransposition(12.0f);


	GPIO LED1, LED2, LED3, LED4, LED5;
	//D is where LED 1 is located
	LED1.Init(D20, GPIO::Mode::OUTPUT);  
	LED2.Init(D21, GPIO::Mode::OUTPUT);
	LED3.Init(D22, GPIO::Mode::OUTPUT);
	LED4.Init(D23, GPIO::Mode::OUTPUT);
	LED5.Init(D24, GPIO::Mode::OUTPUT);



    // Main loop
    while(1) {
        hw.StartAudio(MyCallback);
		switch (state)
        {
			case 1:  
                LED1.Write(true);
				LED2.Write(false);
				LED3.Write(false);
			   	LED4.Write(false);
				LED5.Write(false);
				
                break;
            case 2:  // State 2 logic
				LED1.Write(false);
				LED2.Write(true);
				LED3.Write(false);
			   	LED4.Write(false);
				LED5.Write(false);
                break;
            case 3:  // State 3 logic
				LED1.Write(false);
				LED2.Write(false);
				LED3.Write(true);
			   	LED4.Write(false);
				LED5.Write(false);
                break;
            case 4:  // State 4 logic
                LED1.Write(false);
				LED2.Write(false);
				LED3.Write(false);
			   	LED4.Write(true);
				LED5.Write(false);
                break;
			case 5:  // State 4 logic
                LED1.Write(false);
				LED2.Write(false);
				LED3.Write(false);
			   	LED4.Write(false);
				LED5.Write(true);
                break;
            // State 0: Default behavior (no effect)
            default:
               	LED1.Write(true);
			   	LED2.Write(true);
				LED3.Write(true);
			   	LED4.Write(true);
				LED5.Write(true);
                break;
		}
    }
}

void DeclareInitHardware() {
    hw.Configure();
    hw.Init();

    hw.SetAudioBlockSize(4);

    // Button initialization with debounce
    Button1.Init(hw.GetPin(25), 1000); // 1000 ms for debounce

    const int num_adc_channels = 2;
    AdcChannelConfig adc_config[num_adc_channels];

    adc_config[0].InitSingle(A0);
    adc_config[1].InitSingle(A1);

    hw.adc.Init(adc_config, num_adc_channels);
    hw.adc.Start();
}

void Controls() {
    Button1.Debounce();  // Debounce the button

    // Check if the button is pressed
    if (Button1.RisingEdge()) {
        // Increment the state and wrap around at 5
        state = (state + 1) % 6;
    }

    // Update potentiometer readings
    pot1 = hw.adc.GetFloat(0);
    pot2 = hw.adc.GetFloat(1);
}
