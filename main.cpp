/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
/*
 copied UDT 1:
 */
struct DAWProject //1, Nested UDT
{
    DAWProject(std::string dawProjectName);
    ~DAWProject();


    std::string timeSignature = "3/4";
    std::string musicalMode = "minor";
    std::string keySignature = "A";
    int numOfSections;
    bool isQuantized;
    std::string projectName;

    struct VirtualStudioTechnology
    {
        VirtualStudioTechnology(std::string vst);
        ~VirtualStudioTechnology();

        std::string vstName;
        std::string vstManufacturer;
        std::string vstType;
        bool supportsMIDI = true;
        int numOfPresets;

        void acceptMIDIInput();
        void outputAudio(double outputVolume = 80.0);
        std::string changePreset(std::string presetName);
        void testMIDIInputChannels(int numOfMIDIInputChannels = 2);
    };

    void playBack();
    void playBackComposition();
    void applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse); 
    void quantizeNotes();

    VirtualStudioTechnology vst{"Kontakt"};

};

DAWProject::VirtualStudioTechnology::VirtualStudioTechnology(std::string vstn) :
vstName(vstn),
vstManufacturer("Toontrack"),
vstType("virtual instrument")
{
    numOfPresets = 100;
    std::cout << "\n[CTOR VirtualStudioTechnology] " << vstName << std::endl;
}

DAWProject::VirtualStudioTechnology::~VirtualStudioTechnology()
{
    std::cout << "\n[DTOR VirtualStudioTechnology] " << vstName << std::endl;
}

DAWProject::DAWProject(std::string dawProjectName) :
numOfSections(8),
isQuantized(true),
projectName(dawProjectName)
{
    std::cout << "\n[CTOR DAWProject] " << projectName << std::endl;
}

DAWProject::~DAWProject()
{
    std::cout << "\n[DTOR DAWProject] " << projectName << std::endl;
}

void DAWProject::playBack()
{
    std::cout << "\nNow playing..." << std::endl;
}

void DAWProject::playBackComposition()
{
    for(int i = 0; i < numOfSections; ++i)
    {
        playBack();
    }    
}

void DAWProject::applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse)
{
    std::cout << "\nApply " << effectName << " of " << vstInUse.vstName << std::endl;
}

void DAWProject::quantizeNotes()
{
    std::cout << "\nAre the MIDI notes quantized? " << (isQuantized? "Yes":"No") << std::endl;
}

void DAWProject::VirtualStudioTechnology::acceptMIDIInput()
{
    std::cout << "\nCurrent VST accepts MIDI input? " << (supportsMIDI? "Yes":"No") << std::endl;
}

void DAWProject::VirtualStudioTechnology::outputAudio(double outputVolume)
{
    std::cout << "\nOutput audio at " << outputVolume << "db" << std::endl;
}

std::string DAWProject::VirtualStudioTechnology::changePreset(std::string presetName)
{
    return presetName;
}

void DAWProject::VirtualStudioTechnology::testMIDIInputChannels(int numOfMIDIInputChannels)
{
    std::cout << "Testing MIDI input channels..." << std::endl;
    for (int i = 1; i < numOfMIDIInputChannels; ++i)
    {
        std::cout << "\n[Loop] Now testing MIDI input channel [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] MIDI input channels test complete!" << std::endl;
}
/*
 copied UDT 2:
 */
struct BackstageArea //2
{
    BackstageArea(double size);
    ~BackstageArea();

    int numOfEmptyLockers, numOfDressingRooms, numOfEquimentStorageShelves,numOfAllLockers;
    double backStageSize;
    bool hasEquipmentLoadingAccess = true;

    void provideRestingSpaceForPerformers();
    void storeCablesAndInstruments();
    void provideStorageForPersonalBelongings();
    int storePersonalBelongings();
};

BackstageArea::BackstageArea(double size) :
numOfEmptyLockers(5),
numOfDressingRooms(3),
numOfEquimentStorageShelves(10),
numOfAllLockers(8),
backStageSize(size)
{
    std::cout << "\n[CTOR BackstageArea] A " << backStageSize << "-square-meters backstage area is being constructed!" << std::endl;
}

BackstageArea::~BackstageArea()
{
    std::cout << "\n[DTOR BackstageArea] A " << backStageSize << "-square-meters backstage area is being destructed!" << std::endl;
}

void BackstageArea::provideRestingSpaceForPerformers()
{
    std::cout << "\nProvide " << backStageSize << " squre metres of resting space for performers" << std::endl;
}

void BackstageArea::storeCablesAndInstruments()
{
    std::cout << "\nStore cables and instruments with "<< numOfEquimentStorageShelves << " storeage shelves" << std::endl;
}

void BackstageArea::provideStorageForPersonalBelongings()
{
    std::cout << "\nProvide storage for personal belongings with " << numOfAllLockers << " lockers" << std::endl;
}

int BackstageArea::storePersonalBelongings()
{    
    if(numOfEmptyLockers != 0)
    {
        while(numOfEmptyLockers > 0)
        {
            --numOfEmptyLockers;
            std::cout << "\n[Loop] 1 locker allocated. Remaining: " << numOfEmptyLockers << std::endl;
        }
    }
    std::cout << "\n[Loop] Sorry, there are no empty lockers left" << std::endl;
    return numOfEmptyLockers;
}
/*
 copied UDT 3:
 */
struct LightingRig //9, Nested UDT
{
    LightingRig(std::string type);
    ~LightingRig();

    int numOfDMXChannels = 4;
    int numOfTraditionalLights = 12;
    int numOfComputerLights =  35;
    int numOfControlChannels = 512;
    double heightOfRig = 10.5;
    std::string lightingConsoleType;

    struct LightingConsole
    {
        LightingConsole(std::string name);
        ~LightingConsole();

        int numOfScreens = 3;
        int numOfFaders = 8;
        bool hasInternetConnectivity;
        double weightOfConsole = 120.0;
        std::string consoleName;

        void panAndTiltLights(int lightNumber, double panAngle = 135.0, double tiltAngle = 45.0);
        void adjustLightIntensity(int lightNumber, double intensity = 100.0);
        void changeGoboPattern(int lightNumber, std::string patternName = "star");
        void testFaders();

    };

    void illuminateTheStage();
    void changeLightingColorsAndPatterns(LightingConsole consoleInUse);
    void synchronizeLightingWithMusic(LightingConsole consoleInUse);
    void testDMXChannels();

    LightingConsole mainConsole {"Tiger Touch"};

};

LightingRig::LightingConsole::LightingConsole(std::string name):
hasInternetConnectivity(true),
consoleName(name)
{
    std::cout << "\n[CTOR LightingConsole] A " << consoleName << " console is being constructed!" << std::endl;
}

LightingRig::LightingConsole::~LightingConsole()
{
    std::cout << "\n[DTOR LightingConsole] A " << consoleName << " console is being destructed!" << std::endl;
}

LightingRig::LightingRig(std::string type):
lightingConsoleType(type)
{
    std::cout << "\n[CTOR LightingRig] A " << lightingConsoleType << " lighitng rig is being constructed!" << std::endl;
}

LightingRig::~LightingRig()
{
    std::cout << "\n[DTOR LightingRig] A " << lightingConsoleType << " lighitng rig is being destructed!" << std::endl;
}

void LightingRig::illuminateTheStage()
{
    std::cout << "\nIlluminate the stage from " << heightOfRig << " metres high" << std::endl;
}

void LightingRig::changeLightingColorsAndPatterns(LightingConsole consoleInUse)
{
    std::cout << "\nChange lighting colors and patterns with " << consoleInUse.consoleName << std::endl;
}

void LightingRig::synchronizeLightingWithMusic(LightingConsole consoleInUse)
{
    std::cout << "\nSynchronize lighting with music using " << consoleInUse.consoleName << std::endl;
}

void LightingRig::testDMXChannels()
{
    std::cout << "Testing DMX channels..." << std::endl;
    for(int i = 0; i < numOfDMXChannels; ++i)
    {
        std::cout << "\n[Loop] Now testing DMX channel [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] DMX channel test complete!" << std::endl;
}

void LightingRig::LightingConsole::panAndTiltLights(int lightNumber, double panAngle, double tiltAngle)
{
    std::cout << "\nPan and tilt light " << lightNumber << " to " << panAngle << " and " << tiltAngle << std::endl;
}

void LightingRig::LightingConsole::adjustLightIntensity(int lightNumber, double intensity)
{
    std::cout << "\nAdjust the intensity of light " << lightNumber << " to " << intensity << std::endl;
}

void LightingRig::LightingConsole::changeGoboPattern(int lightNumber, std::string patternName)
{
    std::cout << "\nChange the gobo pattern of light " << lightNumber << " to "<< consoleName << "'s default pattern: " << patternName << std::endl;
}

void LightingRig::LightingConsole::testFaders()
{
    std::cout << "Testing faders..." << std::endl;
    for(int i = 0; i < numOfFaders; ++i)
    {
        std::cout << "\n[Loop] Now testing faders [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] Faders channel test complete!" << std::endl;
}
/*
 new UDT 4:
 with 2 member functions
 */
struct AlbumRemake
{
    AlbumRemake(std::string name, std::string vst1, std::string vst2, std::string vst3);
    ~AlbumRemake();

    std::string albumName;
    DAWProject betcover {"野猿"};
    DAWProject maruja {"Drift Like Cloud, Flow Like Water"};
    DAWProject bcnr {"For the Cold Country"};

    void displayOneDAWProject(DAWProject p);
    void displayAllProjectName(); 
};

AlbumRemake::AlbumRemake(std::string name, std::string vst1, std::string vst2, std::string vst3):
albumName(name)
{
    std::cout << "\n[CTOR AlbumRemake] '"<< albumName << "' remake project is being constructed!" << std::endl;

    betcover.vst.vstName = vst1;
    maruja.vst.vstName = vst2;
    bcnr.vst.vstName = vst3;
    
    displayOneDAWProject(maruja);
}

AlbumRemake::~AlbumRemake()
{
    std::cout << "\n[DTOR AlbumRemake] The "<< albumName << " remake project is being destructed!" << std::endl;
}

void AlbumRemake::displayOneDAWProject(DAWProject p)
{
    std::cout << "\nYou are viewing the project: " << p.projectName << std::endl;
}

void AlbumRemake::displayAllProjectName()
{
    std::cout << "\nWhat are we working on?\n";
    std::cout << "\nFirst project: " << betcover.projectName << std::endl;
    std::cout << "\nSecond project: " << maruja.projectName << std::endl;
    std::cout << "\nThird project: " << bcnr.projectName << std::endl;
}


/*
 new UDT 5:
 with 2 member functions
 */
struct ConcertHall
{
    ConcertHall(std::string name);
    ~ConcertHall();

    BackstageArea leftBackstageArea {375.5};
    BackstageArea rightBackstageArea {525.5};
    LightingRig mainRig {"MA Lighting"};
    LightingRig subRig {"Avolites"};

    void displayAllBackstageAreaSize();
    void displayAllLightingRigType();
};

ConcertHall::ConcertHall(std::string name)
{
    std::cout << "\n[CTOR ConcertHall] "<< name << " is being constructed!" << std::endl;
}

ConcertHall::~ConcertHall()
{
    std::cout << "\n[DTOR ConcertHall] The concert hall is being destructed!" << std::endl;
}

void ConcertHall::displayAllBackstageAreaSize()
{
    std::cout << "\nThe left backstage area is " << leftBackstageArea.backStageSize << " square meters" << std::endl;
    std::cout << "\nThe right backstage area is " << rightBackstageArea.backStageSize << " square meters" << std::endl;
}

void ConcertHall::displayAllLightingRigType()
{
    std::cout << "\nThe main lighting rig is " << mainRig.lightingConsoleType << std::endl;
    std::cout << "\nThe sub lighting rig is " << subRig.lightingConsoleType << std::endl;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    DAWProject dawp {"betcover!! Go Go Steam"};
    std::cout << "----------------\n";

    DAWProject::VirtualStudioTechnology vst {"Superior Drummer"};
    std::cout << "----------------\n";

    BackstageArea bsa(500.0);
    BackstageArea bsa1(150.0);
    bsa1.numOfEmptyLockers = 0;
    std::cout << "----------------\n";

    LightingRig ltr {"Avolites"};
    std::cout << "----------------\n";

    LightingRig::LightingConsole lc {"Pearl"};
    std::cout << "----------------\n";

    AlbumRemake ar {"My favourite songs", "Fuzz War", "Super Octave", "Nord Stage 3 HA88"};
    //ar.displayAllProjectName();
    std::cout << "----------------\n";

    ConcertHall ch {"Tokyo Dome"};
    std::cout << "----------------\n";


    
    dawp.playBackComposition();
    dawp.applyAudioEffects("reverb", dawp.vst);
    dawp.quantizeNotes();
    std::cout << "\n[Member Initialization] A " << dawp.vst.vstName << " is being used" << std::endl;
    std::cout << "\n[Member Initialization] Is the project quantized? " << (dawp.isQuantized ? "Yes" : "No") << std::endl;
    std::cout << "----------------\n";



    vst.acceptMIDIInput();
    vst.outputAudio();
    vst.changePreset("Punk");
    std::cout << "\n[Member Initialization] The preset has been changed to [" << vst.changePreset("Jazz") << "]" << std::endl;
    vst.testMIDIInputChannels(2);
    std::cout << "----------------\n";


    
    bsa.provideRestingSpaceForPerformers();
    bsa.storeCablesAndInstruments();
    bsa.provideStorageForPersonalBelongings();
    std::cout << "\n[Member Initialization] There are " << bsa.numOfAllLockers << " lockers in the backstage area" << std::endl;
    std::cout << "\n // Case 1: Demand < available lockers \n";
    bsa.storePersonalBelongings();
    std::cout << "\n // Case 2: No lockers available (numOfEmptyLockers = 0) \n";
    bsa1.storePersonalBelongings();
    std::cout << "----------------\n";


    
    ltr.illuminateTheStage();
    ltr.changeLightingColorsAndPatterns(ltr.mainConsole);
    ltr.synchronizeLightingWithMusic(ltr.mainConsole);
    std::cout << "\n[Member Initialization] The lighting console type is " << ltr.lightingConsoleType << std::endl;
    ltr.testDMXChannels();
    std::cout << "----------------\n";


    
    lc.panAndTiltLights(5, 135.0, 60.0);
    lc.adjustLightIntensity(1, 100.0);
    lc.changeGoboPattern(2, "star");
    std::cout << "\n[Member Initialization] The lighting console has " << lc.numOfFaders << " faders" << std::endl;
    lc.testFaders();
    std::cout << "----------------\n";

    

    ar.displayOneDAWProject(ar.betcover);
    ar.displayAllProjectName();
    std::cout << "----------------\n";


    
    ch.displayAllBackstageAreaSize();
    ch.displayAllLightingRigType();
    std::cout << "----------------\n";


    
    std::cout << "good to go!" << std::endl;
}
