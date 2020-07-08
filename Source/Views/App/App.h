#pragma once
#include <juce_gui_extra/juce_gui_extra.h>
#include <tracktion_engine/tracktion_engine.h>
#include "AppLookAndFeel.h"
#include "ThemeManager.h"
#include "Themes.h"
#include "PresetSlots.h"

class App : public juce::TabbedComponent,
            public juce::ApplicationCommandTarget,
            public juce::ChangeListener
{
public:

    App(tracktion_engine::Engine& e, juce::ValueTree v);

    void paint (juce::Graphics&) override;
    void resized() override;

    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(juce::Array<juce::CommandID>& commands) override;
    void getCommandInfo (juce::CommandID commandID, juce::ApplicationCommandInfo& result) override;
    bool perform (const InvocationInfo &info) override;

    void changeListenerCallback(juce::ChangeBroadcaster *source) override;

private:

    tracktion_engine::Engine& engine;
    std::unique_ptr<tracktion_engine::Edit> edit;
    juce::ApplicationCommandManager commandManager;
    AppLookAndFeel lookAndFeel;

    juce::String synthTabName = "SYNTH";
    juce::String drumTabName = "DRUM";
    juce::String tapeTabName = "TAPE";
    juce::String mixerTabName = "MIXER";
    juce::String settingsTabName = "SETTINGS";

    juce::ValueTree synthState;
    juce::ValueTree drumState;
    Themes themes;
    PresetSlots synthPresetSlots;
    PresetSlots drumPresetSlots;

    void setLookAndFeelColours();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (App)
};
