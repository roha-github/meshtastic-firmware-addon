/* https://github.com/todd-herbert/meshtastic-firmware/blob/diy-modules/src/modules/DemoDIYModule.h */

#pragma once

#include "DIYModule.h"

#ifdef DIYMODULES
#ifdef DIYMODULES_DEMO

/*
 * DIY Modules - Demo
 *
 * This code is *not* official,
 * This code is *not* part of the Meshtastic project.
 *
 * This code is a quick demonstration of an unofficial "DIYModule" class.
 * A starting point, to help you control a remote node,
 * using commands sent from an unmodified client app.
 *
 * Create a "Demo" channel on your node,
 * then send a message to the channel from a connected phone.
 * Message will be intercepted by this demo, not sent out over the mesh.
 *
 * To implement:
 *   - In src/modules/Modules.cpp
 *     - Import your module's .h file
 *     - Create an instance of your module in setupModules()
 *
 *   - In variants/<your board>/variant.h
 *      - #define DIYMODULES
 *      - #define DIYMODULES_DEMO (to build this demo)
 *        (or add to your platformio.ini file, if you don't mind VSCode greying-out your work)
 */

class DemoDIYModule : public DIYModule
{
  public:
    DemoDIYModule();

    // Implement this method to handle your custom commands
    virtual void handleSentText(const meshtastic_MeshPacket &mp) override;

    void exampleHelp();
    void exampleSaveNum(char *numAsText);
    void exampleSaveText(char *text);
    void exampleLoad();
};

// You need to call new() for this in src/modules/Modules.cpp setupModules()
extern DemoDIYModule *demoDIYModule;

#endif // DIYMODULES_DEMO
#endif // DIYMODULES
