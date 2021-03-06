#ifndef MYLNF_H_INCLUDED
#define MYLNF_H_INCLUDED

#include <JuceHeader.h>

class MyLNF : public LookAndFeel_V4
{
public:
    MyLNF();

    Typeface::Ptr getTypefaceForFont(const Font&) override;

    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float rotaryStartAngle,
                           float rotaryEndAngle, juce::Slider& slider) override;

    void drawToggleButton (Graphics& g, ToggleButton& button,
                           bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    void positionComboBoxText (ComboBox& box, Label& label) override;

private:
    std::unique_ptr<Drawable> knob = Drawable::createFromImageData (BinaryData::knob_svg, BinaryData::knob_svgSize);
    std::unique_ptr<Drawable> pointer = Drawable::createFromImageData (BinaryData::pointer_svg, BinaryData::pointer_svgSize);

    Typeface::Ptr roboto;
    Typeface::Ptr robotoBold;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyLNF)
};

#endif // MYLNF_H_INCLUDED
