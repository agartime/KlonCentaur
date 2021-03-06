add_library(SharedCode STATIC)

# juce_generate_juce_header(SharedCode)

target_sources(SharedCode PRIVATE
    PluginBase.h
    IIRFilter.h
    BilinearTools.h
    InputBufferProcessor.h
    InputBufferProcessor.cpp
    PreAmpStage.h
    PreAmpStage.cpp
    AmpStage.h
    ClippingStage.h
    FeedForward2.h
    FeedForward2.cpp
    SummingAmp.h
    ToneFilterProcessor.h
    ToneFilterProcessor.cpp
    OutputStageProcessor.h
    OutputStageProcessor.cpp
    Json2RnnParser.h
    Json2RnnParser.cpp
)

target_compile_definitions(SharedCode PUBLIC
    JUCE_STANDALONE_APPLICATION=0
    JUCE_REPORT_APP_USAGE=0
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)

add_subdirectory(MLUtils)

target_link_libraries(SharedCode PRIVATE
    juce::juce_audio_utils
    MLUtils
)

# Need to build with -fPIC flag on Linux
set_target_properties(SharedCode PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE)
