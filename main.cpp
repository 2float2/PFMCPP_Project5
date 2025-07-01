/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
#include "LeakedObjectDetector.h"
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
        std::string getVstManufacturer();
        void printDetailedMemberInfo();
    };

    void playBack();
    void playBackComposition();
    void applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse);
    void quantizeNotes();
    std::string getTrackType();
    void printDetailedMemberInfo();

    VirtualStudioTechnology vst{"Kontakt"};

    JUCE_LEAK_DETECTOR(DAWProject)

};

struct DAWProjectWrapper
{
    DAWProjectWrapper(DAWProject* ptr) : dawpPtr(ptr) { }
    ~DAWProjectWrapper() { delete dawpPtr; }
    DAWProject* dawpPtr = nullptr;
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
    for (int i = 0; i < numOfSections; ++i)
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
    std::cout << "\nAre the MIDI notes quantized? " << (isQuantized ? "Yes" : "No") << std::endl;
}

std::string DAWProject::getTrackType()
{
    return "midi track";
}

void DAWProject::printDetailedMemberInfo()
{
    std::cout << "\n[DAWProject] track type: " << this->getTrackType() << " \ntime signature: " << this->timeSignature << std::endl;
}

void DAWProject::VirtualStudioTechnology::acceptMIDIInput()
{
    std::cout << "\nCurrent VST accepts MIDI input? " << (supportsMIDI ? "Yes" : "No") << std::endl;
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

std::string DAWProject::VirtualStudioTechnology::getVstManufacturer()
{
    return "Spitfire Audio";
}

void DAWProject::VirtualStudioTechnology::printDetailedMemberInfo()
{
    std::cout << "\n[VirtualStudioTechnology] manufacturer: " << this->getVstManufacturer() << " \nvst name: " << this->vstName << std::endl;
}

/*
 copied UDT 2:
 */
struct BackstageArea //2
{
    BackstageArea(double size);
    ~BackstageArea();

    int numOfEmptyLockers,
    numOfDressingRooms, numOfEquimentStorageShelves, numOfAllLockers;
    double backStageSize;
    bool hasEquipmentLoadingAccess = true;

    void provideRestingSpaceForPerformers();
    void storeCablesAndInstruments();
    void provideStorageForPersonalBelongings();
    int storePersonalBelongings();
    int getCapacity();
    void printDetailedMemberInfo();

    JUCE_LEAK_DETECTOR(BackstageArea)
};

struct BackstageAreaWrapper
{
    BackstageAreaWrapper(BackstageArea* ptr) : bsaPtr(ptr){ }
    ~BackstageAreaWrapper() { delete bsaPtr;}
    BackstageArea* bsaPtr = nullptr;
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
    std::cout << "\nStore cables and instruments with " << numOfEquimentStorageShelves << " storeage shelves" << std::endl;
}

void BackstageArea::provideStorageForPersonalBelongings()
{
    std::cout << "\nProvide storage for personal belongings with " << numOfAllLockers << " lockers" << std::endl;
}

int BackstageArea::storePersonalBelongings()
{
    if (numOfEmptyLockers != 0)
    {
        while (numOfEmptyLockers > 0)
        {
            --numOfEmptyLockers;
            std::cout << "\n[Loop] 1 locker allocated. Remaining: " << numOfEmptyLockers << std::endl;
        }
    }
    std::cout << "\n[Loop] Sorry, there are no empty lockers left" << std::endl;
    return numOfEmptyLockers;
}

int BackstageArea::getCapacity()
{
    return 500;
}

void BackstageArea::printDetailedMemberInfo()
{
    std::cout << "\n[BackstageArea] can accomadate: " << this->getCapacity() << " people" << "\nbackstage size: " << this->backStageSize << std::endl;
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
    int numOfComputerLights = 35;
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
        int getNumOfUsbPort();
        void printDetailedMemberInfo();

    };

    void illuminateTheStage();
    void changeLightingColorsAndPatterns(LightingConsole consoleInUse);
    void synchronizeLightingWithMusic(LightingConsole consoleInUse);
    void testDMXChannels();
    int getNumOfScreens();
    void printDetailedMemberInfo();

    LightingConsole mainConsole{ "Tiger Touch" };

    JUCE_LEAK_DETECTOR(LightingRig)

};

struct LightingRigWrapper
{
    LightingRigWrapper(LightingRig* ptr) : ltrPtr(ptr) { }
    ~LightingRigWrapper() { delete ltrPtr; }
    LightingRig* ltrPtr = nullptr;
};

LightingRig::LightingConsole::LightingConsole(std::string name) :
hasInternetConnectivity(true),
consoleName(name)
{
    std::cout << "\n[CTOR LightingConsole] A " << consoleName << " console is being constructed!" << std::endl;
}

LightingRig::LightingConsole::~LightingConsole()
{
    std::cout << "\n[DTOR LightingConsole] A " << consoleName << " console is being destructed!" << std::endl;
}

LightingRig::LightingRig(std::string type) :
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
    for (int i = 0; i < numOfDMXChannels; ++i)
    {
        std::cout << "\n[Loop] Now testing DMX channel [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] DMX channel test complete!" << std::endl;
}

int LightingRig::getNumOfScreens()
{
    return 3;
}

void LightingRig::printDetailedMemberInfo()
{
    std::cout << "\nThe [LightingRig] has " << this->getNumOfScreens() << " screens" << "\nlighting rig height: " << this->heightOfRig << std::endl;
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
    std::cout << "\nChange the gobo pattern of light " << lightNumber << " to " << consoleName << "'s default pattern: " << patternName << std::endl;
}

void LightingRig::LightingConsole::testFaders()
{
    std::cout << "Testing faders..." << std::endl;
    for (int i = 0; i < numOfFaders; ++i)
    {
        std::cout << "\n[Loop] Now testing faders [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] Faders channel test complete!" << std::endl;
}

int LightingRig::LightingConsole::getNumOfUsbPort()
{
    return 4;
}

void LightingRig::LightingConsole::printDetailedMemberInfo()
{
    std::cout << "\nThe [LightingConsole] has " << this->getNumOfUsbPort() << " usb ports" << "\nlighting console weight: " << this->weightOfConsole << std::endl;
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
    DAWProject betcover{ "野猿" };
    DAWProject maruja{ "Drift Like Cloud, Flow Like Water" };
    DAWProject bcnr{ "For the Cold Country" };

    void displayOneDAWProject(DAWProject p);
    void displayAllProjectName();

    JUCE_LEAK_DETECTOR(AlbumRemake)
};

struct AlbumRemakeWrapper
{
    AlbumRemakeWrapper(AlbumRemake* ptr) : arPtr(ptr) { }
    ~AlbumRemakeWrapper() { delete arPtr; }
    AlbumRemake* arPtr = nullptr;
};

AlbumRemake::AlbumRemake(std::string name, std::string vst1, std::string vst2, std::string vst3) :
albumName(name)
{
    std::cout << "\n[CTOR AlbumRemake] '" << albumName << "' remake project is being constructed!" << std::endl;

    betcover.vst.vstName = vst1;
    maruja.vst.vstName = vst2;
    bcnr.vst.vstName = vst3;

    displayOneDAWProject(maruja);
}

AlbumRemake::~AlbumRemake()
{
    std::cout << "\n[DTOR AlbumRemake] The " << albumName << " remake project is being destructed!" << std::endl;
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

    BackstageArea leftBackstageArea{ 375.5 };
    BackstageArea rightBackstageArea{ 525.5 };
    LightingRig mainRig{ "MA Lighting" };
    LightingRig subRig{ "Avolites" };

    void displayAllBackstageAreaSize();
    void displayAllLightingRigType();

    JUCE_LEAK_DETECTOR(ConcertHall)
};

struct ConcertHallWrapper
{
    ConcertHallWrapper(ConcertHall* ptr) : chPtr(ptr) { }
    ~ConcertHallWrapper() { delete chPtr; }
    ConcertHall* chPtr = nullptr;
};

ConcertHall::ConcertHall(std::string name)
{
    std::cout << "\n[CTOR ConcertHall] " << name << " is being constructed!" << std::endl;
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
    DAWProjectWrapper dawp( new DAWProject( "betcover!! Go Go Steam" ) );
    std::cout << "----------------\n";

    DAWProject::VirtualStudioTechnology vst{ "Superior Drummer" };
    std::cout << "----------------\n";

    BackstageArea bsa(500.0);
    BackstageArea bsa1(150.0);
    bsa1.numOfEmptyLockers = 0;
    std::cout << "----------------\n";

    LightingRig ltr{ "Avolites" };
    std::cout << "----------------\n";

    LightingRig::LightingConsole lc{ "Pearl" };
    std::cout << "----------------\n";

    AlbumRemake ar{ "My favourite songs", "Fuzz War", "Super Octave", "Nord Stage 3 HA88" };
    //ar.displayAllProjectName();
    std::cout << "----------------\n";

    ConcertHall ch{ "Tokyo Dome" };
    std::cout << "----------------\n";



    dawp.dawpPtr->playBackComposition();
    dawp.dawpPtr->applyAudioEffects("reverb", dawp.dawpPtr->vst);
    dawp.dawpPtr->quantizeNotes();
    std::cout << "\n[Member Initialization] A " << dawp.dawpPtr->vst.vstName << " is being used" << std::endl;
    std::cout << "\n[Member Initialization] Is the project quantized? " << (dawp.dawpPtr->isQuantized ? "Yes" : "No") << std::endl;
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


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------\n";
    std::cout << "--------------- Project 5.2 'this' keyword ---------------\n";
    std::cout << "----------------------------------------------------------\n";
    //DAWProject
    std::cout << "\ndaw track type: " << dawp.dawpPtr->getTrackType() << " \ntime signature: " << dawp.dawpPtr->timeSignature << std::endl;
    dawp.dawpPtr->printDetailedMemberInfo();

    //VirtualStudioTechnology
    std::cout << "\nvst manufacturer: " << vst.getVstManufacturer() << " \nvst name: " << vst.vstName << std::endl;
    vst.printDetailedMemberInfo();

    //BackstageArea
    std::cout << "\nbackstage can accomadate: " << bsa.getCapacity() << " people" << "\nbackstage size: " << bsa.backStageSize << std::endl;
    bsa.printDetailedMemberInfo();

    //LightingRig
    std::cout << "\nThe lighting rig has " << ltr.getNumOfScreens() << " screens" << "\nlighting rig height: " << ltr.heightOfRig << std::endl;
    ltr.printDetailedMemberInfo();

    //LightingConsole
    std::cout << "\nThe lighting console has " << lc.getNumOfUsbPort() << " usb ports" << "\nlighting console weight: " << lc.weightOfConsole << std::endl;
    lc.printDetailedMemberInfo();


    std::cout << "good to go!" << std::endl;
}
