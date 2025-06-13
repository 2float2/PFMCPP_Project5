/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

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

    VirtualStudioTechnology virtualGuitar{"Ample Sound Guitar"};

};

DAWProject::VirtualStudioTechnology::VirtualStudioTechnology(std::string vst) :
vstName(vst),
vstManufacturer("Toontrack"),
vstType("virtual instrument")
{
    numOfPresets = 100;
    std::cout << "\n[Constructor] " << vstName << " being constructed!" << std::endl;

}

DAWProject::VirtualStudioTechnology::~VirtualStudioTechnology()
{
    std::cout << "\n[Destructor] " << vstName << " being destructed!" << std::endl;
}

DAWProject::DAWProject(std::string dawProjectName) :
numOfSections(8),
isQuantized(true),
projectName(dawProjectName)
{
    std::cout << "\n[Constructor] " << projectName << " being constructed!" << std::endl;
}

DAWProject::~DAWProject()
{
    std::cout << "\n[Destructor] " << projectName << " being destructed!" << std::endl;
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
    int storePersonalBelongings(int requiredLockers);
};

BackstageArea::BackstageArea(double size) :
numOfEmptyLockers(5),
numOfDressingRooms(3),
numOfEquimentStorageShelves(10),
numOfAllLockers(8),
backStageSize(size)
{
    std::cout << "\n[Constructor] A backstage area of " << backStageSize << " square meters being constructed!" << std::endl;
}

BackstageArea::~BackstageArea()
{
    std::cout << "\n[Destructor] A backstage area of " << backStageSize << " square meters being destructed!" << std::endl;
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

int BackstageArea::storePersonalBelongings(int requiredLockers)
{    
    if(numOfEmptyLockers > 0)
    {
        while(requiredLockers > 0 && numOfEmptyLockers > 0)
        {
            --requiredLockers;
            --numOfEmptyLockers;
            std::cout << "\n[Loop] 1 locker allocated. Remaining: " 
                << numOfEmptyLockers << std::endl;
        }

        if(numOfEmptyLockers == 0)
        {
            std::cout << "\n[Info] All Lockers are now occupied" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "\n[Info] All requested lockers allocated" << std::endl;
            return requiredLockers;
        }
    }
    else
    {
        std::cout << "\n[Error] Sorry, there are no empty lockers left!" << std::endl;
        return -1;
    }        
}
/*
 copied UDT 3:
 */
struct LightingRig //9, Nested UDT
{
    LightingRig();

    int numOfDMXChannels = 4;
    int numOfTraditionalLights = 12;
    int numOfComputerLights =  35;
    int numOfControlChannels = 512;
    double heightOfRig = 10.5;
    std::string lightingConsoleType;

    struct LightingConsole
    {
        LightingConsole();

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

    LightingConsole mainConsole;
};

LightingRig::LightingConsole::LightingConsole():
hasInternetConnectivity(true),
consoleName("GrandMA3")
{
    std::cout << "\nLightingConsole being constructed!" << std::endl;
}

LightingRig::LightingRig():
lightingConsoleType("MA Lighting")
{
    std::cout << "\nLighitngRig being constructed!" << std::endl;
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
    for(int i =0 ; i < numOfDMXChannels; ++i)
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
    for(int i =0 ; i < numOfFaders; ++i)
    {
        std::cout << "\n[Loop] Now testing faders [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] Faders channel test complete!" << std::endl;
}
/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

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
    DAWProject dawp{"betcover!! Go Go Steam"};
    std::cout << "----------------\n";

    DAWProject::VirtualStudioTechnology vst{"Superior Drummer"};
    std::cout << "----------------\n";

    BackstageArea bsa(500.0);
    BackstageArea bsa0(300.0);
    BackstageArea bsa1(150.0);
    bsa1.numOfEmptyLockers = 0;
    std::cout << "----------------\n";

    LightingRig ltr;
    std::cout << "----------------\n";

    LightingRig::LightingConsole lc;
    std::cout << "----------------\n";



    
    dawp.playBackComposition();
    dawp.applyAudioEffects("reverb", dawp.virtualGuitar);
    dawp.quantizeNotes();
    std::cout << "\n[Member Initialization] A " << dawp.virtualGuitar.vstName << " is being used" << std::endl;
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
    bsa.storePersonalBelongings(4); 
    std::cout << "\n // Case 1: Demand > available lockers \n";
    bsa0.storePersonalBelongings(5);
    std::cout << "\n // Case 3: No lockers available (numOfEmptyLockers = 0) \n";
    bsa1.storePersonalBelongings(2);
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
    



    std::cout << "good to go!" << std::endl;
}
