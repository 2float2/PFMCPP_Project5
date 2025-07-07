/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */







#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"

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

    BackstageAreaWrapper bsa( new BackstageArea(500.0));
    BackstageAreaWrapper bsa1( new BackstageArea(150.0));
    bsa1.bsaPtr->numOfEmptyLockers = 0;
    std::cout << "----------------\n";

    LightingRigWrapper ltr(new LightingRig( "Avolites" ));
    std::cout << "----------------\n";

    LightingRig::LightingConsole lc{ "Pearl" };
    std::cout << "----------------\n";

    AlbumRemakeWrapper ar( new AlbumRemake ( "My favourite songs", "Fuzz War", "Super Octave", "Nord Stage 3 HA88" ) );
    //ar.displayAllProjectName();
    std::cout << "----------------\n";

    ConcertHallWrapper ch( new ConcertHall( "Tokyo Dome" ) );
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



    bsa.bsaPtr->provideRestingSpaceForPerformers();
    bsa.bsaPtr->storeCablesAndInstruments();
    bsa.bsaPtr->provideStorageForPersonalBelongings();
    std::cout << "\n[Member Initialization] There are " << bsa.bsaPtr->numOfAllLockers << " lockers in the backstage area" << std::endl;
    std::cout << "\n // Case 1: Demand < available lockers \n";
    bsa.bsaPtr->storePersonalBelongings();
    std::cout << "\n // Case 2: No lockers available (numOfEmptyLockers = 0) \n";
    bsa1.bsaPtr->storePersonalBelongings();
    std::cout << "----------------\n";



    ltr.ltrPtr->illuminateTheStage();
    ltr.ltrPtr->changeLightingColorsAndPatterns(ltr.ltrPtr->mainConsole);
    ltr.ltrPtr->synchronizeLightingWithMusic(ltr.ltrPtr->mainConsole);
    std::cout << "\n[Member Initialization] The lighting console type is " << ltr.ltrPtr->lightingConsoleType << std::endl;
    ltr.ltrPtr->testDMXChannels();
    std::cout << "----------------\n";



    lc.panAndTiltLights(5, 135.0, 60.0);
    lc.adjustLightIntensity(1, 100.0);
    lc.changeGoboPattern(2, "star");
    std::cout << "\n[Member Initialization] The lighting console has " << lc.numOfFaders << " faders" << std::endl;
    lc.testFaders();
    std::cout << "----------------\n";



    ar.arPtr->displayOneDAWProject(ar.arPtr->betcover);
    ar.arPtr->displayAllProjectName();
    std::cout << "----------------\n";



    ch.chPtr->displayAllBackstageAreaSize();
    ch.chPtr->displayAllLightingRigType();
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
    std::cout << "\nbackstage can accomadate: " << bsa.bsaPtr->getCapacity() << " people" << "\nbackstage size: " << bsa.bsaPtr->backStageSize << std::endl;
    bsa.bsaPtr->printDetailedMemberInfo();

    //LightingRig
    std::cout << "\nThe lighting rig has " << ltr.ltrPtr->getNumOfScreens() << " screens" << "\nlighting rig height: " << ltr.ltrPtr->heightOfRig << std::endl;
    ltr.ltrPtr->printDetailedMemberInfo();

    //LightingConsole
    std::cout << "\nThe lighting console has " << lc.getNumOfUsbPort() << " usb ports" << "\nlighting console weight: " << lc.weightOfConsole << std::endl;
    lc.printDetailedMemberInfo();


    std::cout << "good to go!" << std::endl;
}
